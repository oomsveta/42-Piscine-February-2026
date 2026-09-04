## Project Overview

C 10 is one of the projects available once you have finished C 09. You *don't* have to finish it in order to validate C 11 and C 12.

C 10 is a combination of everything you've learned so far. You'll have to write complete programs, making use of strings, memory allocation, I/O, command-line arguments, headers, and more, and compile those programs using Makefiles.

**This module was made to fuck you up.** Move on to C 11 or C 12, and only come back to C 10 once you've finished *everything* else.

> [!CAUTION]
> When I attempted C 10, the Moulinette test suite was full of "bugs" that had allegedly been around for years. Some people believe these problems are known and deliberately left unresolved, to put a stop to the progress of the too-good Pisciners. Because of these bugs, passing C 10 on the first try is nearly impossible. You have to submit your project, figure out what unspecified behavior the Moulinette is secretly expecting from your program by reading the traces, adapt your code, rinse and repeat.

## Contents

### ex00: display_file

This exercise teaches you how to deal with files. You'll learn how to open a file, read from it, and then close it once you're done.

The goal is to create a program that receives a path to a file through its command-line arguments and prints the contents of that file to the terminal. It's like a very simplified version of the [`cat`](https://www.man7.org/linux/man-pages/man1/cat.1.html) command.

### ex01: cat

Same principle as before, but you now have to mimic the behavior of the `cat` command. You don't have to handle options such as `-e`. The big difference from the previous exercise is that if the command is called with several paths, all corresponding files will be printed one after another. `cat` can also read from `stdin` if no files are provided, or if the file name is `-`.

I'm not sure whether we're expected to handle reading from `stdin`, but I did it anyway.

At the time I passed the Piscine, there was an error in the Moulinette test suite. It appears that you must **NOT** call `basename` on the program's name, even though it is one of the allowed functions:

```text
= ex01 =========================================================================
= Test 1 ===================================================
$> ./e2v7cn4yau8p4ish0sjy6x3r dummy
$> ./e2v7cn4yau8p4ish0sjy6x3r dummy
$> diff -U 3 user_output_test1 test1.output | cat -e
--- user_output_test1	2026-02-25 16:32:01.266648428 +0000$
+++ test1.output	2026-02-25 16:32:01.302648562 +0000$
@@ -1 +1 @@$
-e2v7cn4yau8p4ish0sjy6x3r: dummy: No such file or directory$
+./e2v7cn4yau8p4ish0sjy6x3r: dummy: No such file or directory$

Diff KO :(
```

This makes `basename` completely useless in the context of that exercise. I'm not sure why it's listed among the allowed functions, but its presence is currently very misleading.

I couldn't reproduce this behavior of NOT cleaning up the program name on either Linux or macOS. I'm not really sure what 42 used at the time to generate the expected output, but it doesn't seem to be aligned with the behavior of common implementations of `cat` anymore.

### ex02: tail

TODO

```
= ex02 =========================================================================
= Test 1 ===================================================
$> ./hu4gdz6e2jzaozzl2q8uvpj1 -c 10 dummy
$> ./hu4gdz6e2jzaozzl2q8uvpj1 -c 10 dummy
$> diff -U 3 user_output_test1 test1.output | cat -e
--- user_output_test1	2026-02-26 18:02:19.395788045 +0000$
+++ test1.output	2026-02-26 18:02:19.431787917 +0000$
@@ -1 +1 @@$
-./hu4gdz6e2jzaozzl2q8uvpj1: dummy: No such file or directory$
+./hu4gdz6e2jzaozzl2q8uvpj1: cannot open 'dummy' for reading: No such file or directory$

Diff KO :(
```

### exo3: hexdump

TODO
