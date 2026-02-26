# 42 Piscine: February 2026

These are my solutions to the exercises of the Piscine held at [42 Belgium](https://42belgium.be/en/) in Brussels in February 2026 (from February 2nd to February 27th).

## 🛟 What is the Piscine?

The *Piscine* (French for "swimming pool") is a teaching method developed by the French engineering school EPITA in the 1980s. It consists of a period of several days dedicated to intensive, group-based learning of a programming language. The goal is to learn as much as possible in a limited time, while strengthening group cohesion and providing a unique experience.

The term most likely comes from the expression "to be thrown into the deep end" (*sauter dans le grand bain*). The idea is to drop students into a difficult environment with no prior instruction, to see who learns to "swim" (code/survive) and who "drowns" (ragequits).

At 42 School, the Piscine is the final step of the admissions process before acceptance. It takes the form of a one-month-long bootcamp, seven days a week, dedicated to solving problems in the C programming language (with a bit of shell scripting during the first two days). There are no teachers, lectures, or courses; everything relies entirely on peer learning. Exercises are first assessed by other "Pisciners", then graded by a series of unit tests known as the dreaded *Moulinette*.

## 🗓️ Calendar

|            |Monday  |Tuesday |Wednesday|Thursday|Friday    |Saturday|Sunday |
|------------|--------|--------|---------|--------|----------|--------|-------|
|**1st Week**|Shell 00|Shell 01|C 00     |C 01    |Exam 00   |Rush 00 |Rush 00|
|**2nd Week**|C 02    |C 03    |C 04     |C 05    |Exam 01   |Rush 01 |Rush 01|
|**3rd Week**|C 06    |C 07    |C 08     |C 09    |Exam 02   |Rush 02 |Rush 02|
|**4th Week**|C 10    |C 11    |C 12     |C 13    |Final Exam|        |       |

"Bonus" project: BSQ

## 📋 Coding Style

My coding style conforms to the [Norm](./norm.en.pdf), a set of strict styling guidelines enforced for all C exercises, which all Pisciners must follow under penalty of a zero grade.

Beyond purely cosmetic considerations, the Norm also forbids the following language constructs:

- `for` loops
- `do … while` loops
- `switch` statements
- `goto`
- the ternary operator
- declarations with initialization
- assignments inside controlling expressions

(non-exhaustive list)

> [!TIP]
> You can find the latest version of the Norm in the [Norminette repository](https://github.com/42School/norminette) – the program for checking conformity to the Norm. The version of the Norm embedded in this repo is the one in use during my Piscine.
