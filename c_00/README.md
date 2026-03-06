## Project Overview
C 00 is the first C project of the Piscine. For the very first project of the Piscine, see [Shell 00](../shell_00/).

This module covers:
- the `write` system call
- the ASCII table
- the very basics of programming:
  - variables
  - conditionals
  - loops

Although it might seem simple at first glance, you would be mistaken to think that this module is boring or that there is nothing to learn from it as a more experienced developer. Interestingly, the `printf` function is absent from the entire cursus, leaving us with the task of implementing everything on top of the `write` system call. This makes printing a number an unexpectedly tedious task: you have to convert each digit to its ASCII value before being able to print it. This process is illustrated in [ex07/ft_putnbr.c](./ex07/ft_putnbr.c).

## Contents

### ex00: ft_putchar

This exercise consists of writing a function that prints the character passed as an argument using the `write` system call. The assignment provides an example implementation, which I simply copied verbatim:
```c
write(1, &c, 1);
```
The first argument is the identifier of the "file" you want to write to. The second is the address of the data to be written, and the third specifies how many bytes to write from that address.

On UNIX systems, standard output is treated like a file. This design provides a unified interface for both regular files and standard streams (stdin, stdout, stderr). The value `1` is the "file descriptor" (id) corresponding to stdout.

From now on, I'll always be using `STDOUT_FILENO` instead of the [magic number](https://en.wikipedia.org/wiki/Magic_number_(programming)) `1`.

### ex01: ft_print_alphabet

This exercise consists of printing the entire lowercase alphabet on a single line. It is expected to be solved using a loop, writing each character from `'a'` to `'z'` with the function from the previous exercise:
```c
void ft_print_alphabet(void)
{
    int letter;
    
    letter = 'a';
    while (letter <= 'z')
    {
        ft_putchar(letter);
        letter++;
    }
}
```
But if you understand how `write` works, you can just hardcode the answer:
```c
void ft_print_alphabet(void)
{
    write(STDOUT_FILENO, "abcdefghijklmnopqrstuvwxyz", 26);
}
```

### ex02: ft_print_reverse_alphabet

Same as above, but in reverse order. To avoid typing the reversed alphabet manually, I generated it using a shell command:
```bash
echo {z..a} | tr -d ' '
```

### ex03: ft_print_numbers

Same once again, but with digits. Really nothing interesting to see here.

Just note that the loop should go from `'0'` to `'9'` (notice the quotes), and not from `0` to `9`. Character literals versus integer literals. Character literals will expand to the corresponding ASCII value.

### ex04: ft_is_negative

Print "P" when the number is positive, print "N" otherwise. Since the ternary operator is banned, I had to get a bit clever to keep it as a one-liner.

### ex05: ft_print_comb

Print all different 3-digit combinations in ascending order, without repetition, so that the output looks like this:
```
012, 013, 014, 015, 016, 017, 018, 019, 023, ..., 789
```
If done right, there should be 120 combinations.

I thought it would be funny to hardcode the answer, but my mischievousness was swiftly punished by the Moulinette. I was writing `sizeof combs` bytes, and since I had defined `combs` using a string literal, that meant I was also printing the null terminator.

My peers didn't notice the invisible character at the end of my output during the reviews. The Moulinette did.

### ex06: ft_print_comb2

Print all different combinations of two distinct 2-digits numbers (XX XX) between `00` and `99`, listed in ascending order, so that the output looks like this:
```
00 01, 00 02, 00 03, 00 04, 00 05, ..., 00 99, 01 02, ..., 97 99, 98 99
```
I was told that the total number of solutions can be calculated using the [binomial coefficient](https://en.wikipedia.org/wiki/Binomial_coefficient):

$$
\frac{100!}{2!(100-2)!} = 4950
$$

This can be solved quite simply with two nested loops, iterating from `0` to `99`. The tricky part compared to the earlier exercises is that you now have to print two-digit numbers. That means you must first extract the tens digit and the ones digit, then convert them to their ASCII values before printing.
- Extracting the tens: `n / 10`
- Extracting the ones: `n % 10`
- Converting to ASCII: `digit + '0'`

### ex07: ft_putnbr

This one was one of my favorite exercise because it makes you rethink something you've always taken for granted: printing a number.

The goal is simple: print a number to the terminal.

In higher-level languages like Python, printing the number `42` is as simple as calling `print(42)`. The language handles all the conversion magic for you. In C, however, if you tried to print the value `42` directly with `write`, you'd end up with something like this:

```c
#include <unistd.h>

int main(void)
{
    int n = 42;

    write(STDOUT_FILENO, &n, 1);
}
```

```shell
$> gcc print42.c && ./a.out
*
```
It prints `*` instead of `42`. Why?

Because you are not printing the number "42" as characters, you are writing raw bytes from memory. The terminal displays characters according to their ASCII values. The decimal value `42` corresponds to `'*'` in ASCII, so that's what gets displayed.

If you want to display "42", you must first produce the character `'4'` (ASCII 52), then the character `'2'` (ASCII 50), and write those bytes instead. In other words, you must convert the integer into its decimal representation manually.

This is the kind of low-level detail that would never occur to you otherwise. That's what I really like about `ft_putnbr` 🥰

To isolate the digits of a number one by one, you can do the number modulo 10 to extract the right-most digit. Then divide the number by ten to shift it to the right, then extract the next number with modulo 10 again. Rince and repeat until the number is fully processed. The only problem is that if you print the digits as you retrieve them — right-most first — the number appears backwards: 42 becomes 24.

A common solution among 42 students is to use recursion. Instead of printing the digit immediately, you first recursively process `n / 10`, which removes the last digit. This continues until the number has only a single digit left — the most significant one. At that point, the recursion starts returning, and each stack frame prints `n % 10`. Because the calls return in the reverse order in which they were made, the digits are printed from the most significant to the least significant.

As for me, I opted for an iterative solution. Since I can't print the digits as I read them, I have to store them somewhere. The iterative strategy therefore requires defining a buffer to temporarily hold the digits, filling the buffer backwards, and finally printing them all at once once the entire number has been processed.

This approach is more performant than the recursive one because it only calls `write` once. `write` is a significant performance bottleneck because it performs a [system call](https://en.wikipedia.org/wiki/System_call), which typically involves a [context switch](https://en.wikipedia.org/wiki/Context_switch) between user space and kernel space. As much as possible, I try to minimize such calls.

One question raised by the iterative approach is what the appropriate buffer size should be. Ideally, the buffer should be just large enough to hold the widest possible `int` — that is, `INT_MIN`, which is `-2147483648` on the school machines. I could simply count the number of characters required to represent `-2147483648` and use it as the buffer size, but this wouldn't be portable. On a 16-bit system such as an Arduino, `INT_MIN` is `-32768`, meaning the buffer would be larger than necessary. Conversely, if my code were to run on a Cray supercomputer, where the size of an `int` is wider, the buffer could overflow!

The optimal size can instead be computed statically. The maximum number of decimal digits required to represent an *n*-bit signed integer is:

$$ \lceil (\text{n} - 1) \times \log_{10}(2) \rceil $$

because a signed integer has one bit reserved for the sign and the remaining bits determine the magnitude.

Since we don't have access to `log10`, we can approximate `log10(2)` very closely with `28 / 93`. This yields the following formula for the buffer size:

```math
\left( \text{sizeof}(\text{int}) \times \text{CHAR\_BIT} - 1 \right) \times \frac{28}{93} + 2
```

The first `+1` accounts for the ceiling of the division, and the second `+1` accounts for the possible minus sign, hence `+2` in total.

## ex08: ft_print_combn

The goal of this exercise is to print all combinations of `n` distinct digits in ascending order, separated by commas and spaces, just like `ft_print_comb` does for three digits but generalized for any `n` from 1 to 10. For example, `ft_print_combn(9)` should print:
```
012345678, 012345679, 012345689, 012345789, 012346789, 012356789, 012456789, 013456789, 023456789, 123456789
```

Again, the total number of combinations for a given `n` can be calculated using the binomial coefficient: $\binom{10}{n} = \frac{10!}{n!(10-n)!}$

Because the number of nested loops we would need depends entirely on `n`, we obviously can't hardcode them.

The core logic is about figuring out how to generate the next valid combination from the current one. If you look closely at the combinations, you always want to increment the right-most digit. But what happens when a digit reaches its maximum value?

Because the digits must be in strictly ascending order, a digit's maximum value is dictated by its position. For example, if n = 3, the last combination is 789. The digit at index 0 maxes out at `'7'`, index 1 at `'8'`, and index 2 at `'9'`.

We can abstract this into a simple formula. The maximum character allowed at any index `i` is simply `'9'` minus its distance from the end of the string: `'9' - (n - 1 - i)`.

With this in mind, generating the next sequence becomes a three-step process inside an infinite loop:
1. Scan right-to-left: Start at the last index (`n - 1`) and move leftward as long as the current digit is at its maximum allowable value.
2. Increment and cascade: Once we find a digit that can be incremented, we add 1 to it. Then, we move back to the right, setting every subsequent digit to be exactly 1 greater than the digit to its left. This ensures we maintain the ascending order without skipping any combinations.
3. Terminate: If our right-to-left scan goes past index 0 (`i < 0`), it means every single digit has reached its maximum capacity. We have printed the final combination, and the function can simply return.
