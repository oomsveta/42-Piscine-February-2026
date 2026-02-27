# Rush 02 - Numbers To Words

## What Is a "Rush"?

A "Rush" is the name given to the group projects available during the weekends of the Piscine at 42 School.
Rush projects are designed to be grueling, requiring a level of knowledge slightly beyond what is expected at this point in the program. Aside from the difficulty of the assignment itself, part of the challenge of Rushes stems from the fact that you're grouped with people chosen at random. You must coordinate your schedules during the weekend and ensure that everyone understands each aspect of the project; otherwise, the entire group receives a zero grade. Unlike other Piscine projects, Rushes are graded by members of the school's staff, not your peers. And if you fail, it's impossible to retry a Rush. You must make it work perfectly within the allotted time on the first attempt.

## Project Overview

This Rush consists of writing a program that converts numbers into English words. For example, given "42" as input, it outputs:
```
forty two
```
Although it may seem simple enough at first glance, some aspects of the assignment made implementing it a truly grueling task. As usual, the entire program must be written in C without using any functions from the standard library, except for `malloc` and a few syscall wrappers (`write`, `read`, `open`, `close`). All code must comply with the [Norm](../norm.en.pdf) and its ridiculous length restrictions. Functionally, one of the main challenges is parsing a dictionary file that defines the words used for numbers. While the "ones" and "tens" can be stored in static arrays, the "magnitudes" (thousand, million, billion, ..., undecillion, ...) are not fixed in number. This requires a dynamically sized data structure to store them. To top it off, the dictionary can also contain custom entries. For example, "42" could be mapped to "Shrek", meaning "42000" would then be displayed as:
```
Shrek thousand
```

## Usage

> [!WARNING]
> The IO for this project is implemented on top of UNIX syscalls, which means that you will need a UNIX system (like Linux or MacOS) to be able to compile and run it.

### Building the project

```shell
make
```

### Convert a Number to English

```shell
./rush-02 <number-to-convert>
```

### Start REPL Mode

```shell
./rush-02 -
```

### Use a Custom Dictionary

```shell
./rush-02 <path-to-dictionary> <number-to-convert>
```

## Features

- Converting numbers to words
  - (with broken grammar though, sorry 🤷‍♂️)
- Load dictionary from a file
- Support custom dictionaries provided via command-line arguments
- Esperanto dictionary
- Dictionary validation
- REPL mode

## The Team

Our team for this Rush consisted of ldeutsch, tmattela, and myself (lwicket). There were no major gaps in our understanding, which allowed us to distribute the workload evenly without worrying too much about mentoring and reviewing each other.
- ldeutsch worked on dictionary parsing
- tmattela implemented the number-to-words conversion logic
- I handled the more framework-oriented parts: data structures and I/O utilities

## Implementation details

### Data Structure
The main difficulty of this project was parsing the dictionary file and storing its contents in a way that would make it easy to work with later. We started by defining the following data structure:

```c
typedef struct s_dict
{
	char	*ones[20];
	char	*tens[11];
	t_list	*magnitudes;
	t_list	*customs;
}	t_dict;
```
#### Fixed-Size Categories
- `ones`: numbers from 0 to 19
- `tens`: multiples of ten (10, 20, ..., 90)
  - We arbitrarily included 100 in this category because it didn't really fit anywhere else in our model.

These categories have a fixed and known size, so we store them directly as arrays inside the struct. This gives us:
- O(1) lookup
- No mallocs 😤
- Simple completeness validation (just check for NULL)

#### Dynamic Categories

- magnitudes (thousand, million, billion, …, undecillion, …)
- customs (user-defined overrides, e.g. 42 -> "Shrek")

These categories can theoretically go on forever. Since the size is unknown, we need a dynamic data structure to hold them. We opted for linked lists because we expected the size to be small enough that the lack of random access wouldn't be problematic. The nice thing about linked lists is that they are the topic of the C12 project of the Piscine, meaning we already had most of the work done.

Linked lists are really easy to expand, you just allocate the new node, change two pointers, and you're done. The downside is that there is no random access, you have to go through the list element by element in order to find anything. This simplified populating the data structure, probably the hardest part of the project, but made retrieving the numbers to display much harder. In retrospect, a vector might have been a better fit. I hate linked lists.

### Parsing & Validation

Parsing follows a "fallback" strategy:
1. Try to classify the entry as a ones
2. If that fails, try tens
3. Then magnitudes
4. If nothing matches, store it as a custom entry

Parsing both populates and validates the dictionary. I've heard that the validation part is where most Pisciners fail. According to the assignment PDF, a dictionary entry should look exactly like this:
```
[a number][0 to n spaces]:[0 to n spaces][any printable characters]\n
```
This is where `strspn` and `strcspn` kick in, the low-key hero duo of parsing in C. `strspn` computes how many characters you can go forward in a string while only encountering characters from a given set (a given *span*, that's where the name comes from). Conversely, `strcspn` ("contrary span") computes the length you can traverse without encountering any characters from the span. This means you can skip whitespace like this:
```c
str += ft_strspn(str, " \t\n\r\v\f");
```
or extract a token like that:
```c
substr_len = ft_strcspn(str, " \t\n\r\v\f);
substr = ft_strndup(str, substr_len);
str += substr_len;
```
Looking back at the project, the entire validation process was repeated for every single type of entry. This could have easily been simplified.

#### Completeness Checks

The assignment states:
> The dictionary will always have at least the keys contained in the reference dictionary. Their values can be modified, more entries can be added, but the initial keys can’t be removed.

That means we must verify:
- All ones are defined
- All tens are defined
- All required magnitudes exist

For ones and tens, this is easy:
1. Initialize the arrays with zeroes
2. Populate during parsing
3. At the end, check for any remaining NULL

For magnitudes, it's trickier. We don't store magnitudes as integers internally, but we rely on the length of the numeric key. Each magnitude corresponds to:
```
1 followed by (3n) zeroes
```
So we check for lengths:
```
4 → 7 → 10 → ... → 37
```
- 4 → 1000
- 7 → 1,000,000
- ...
- 37 → 1 followed by 36 zeroes (undecillion)

We start at 4 and increment by 3 each time. For each expected length, we scan the linked list using [`magnitude_cmp`](./ex00/src/dict/cmp_fns.c). If any expected magnitude is missing, validation fails.

Although the assignment doesn't mention anything about it, we also forbid duplicate entries. Before insertion, we scan the list to see if the number already exists. If it does, parsing fails.

### Number-to-Words Conversion

The conversion logic is based on "triads", that is, groups of three digits processed from left to right.

```
1234567
→ 1 | 234 | 567
```

Each triad is converted independently, then followed by the appropriate magnitude (thousand, million, ...).

#### 1. Edge Cases First

Before any decomposition:
1. Validate the input
2. Handle optional + / - (not required by the assignment)
3. Handle "0" explicitly. We realized too late that we hadn't handled it, so we put it there to avoid further tweaking of the logic.
4. Check if the entire number matches a custom entry

If a full custom match exists, we print it directly and exit. No triads involved.

#### 2. Processing Triads

Inside number_to_words, we iterate over the string:
- `next_triad` extracts the next 1-3 digits.
- `get_magnitude` determines the magnitude based on remaining length.

If a required magnitude is missing, we abort with "Dict Error".

Zero triads are skipped entirely.
That avoids things like "one million zero thousand five".

#### 3. Printing a Triad

`print_triad` handles values from 0 to 999:
- If `n >= 100`, print:
  - the hundreds digit
  - the word for "hundred" (stored in `tens[10]`)
- Then delegate the remaining two digits to `print_sub_100`.

`print_sub_100`:
- First checks for a custom override.
- Otherwise:
  - If `n >= 20`, print the tens.
  - Then print the ones (if non-zero).

## The -O3 Incident

During the evaluation, we were horrified to discover that our project didn't compile on the reviewer's machine.

We were able to prove that it worked perfectly fine on the Pisciners' computers, so we still received full marks. Still, the incident made me twice as cautious about compiler flags, and allowed me to learn a few interesting things:
- On some clusters (like ours), `cc` is an alias for `clang`; on others, it points to `gcc`.
- Ubuntu patches `gcc` to define `_FORTIFY_SOURCE=3` automatically when compiling with `-O` flags.
- When `_FORTIFY_SOURCE` is enabled, the return value of `write` cannot be ignored.

Do you see where this is going?
```
error: ignoring return value of 'write' declared with attribute 'warn_unused_result'
```