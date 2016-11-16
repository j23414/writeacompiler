# writeacompiler

This is my brief forey through compiler writing. Main text are:

* Compilers Principles, Techniques, and Tools (Dragon book)
* Engineering a Compiler

The First example for the Dragon book needed some modification to work on my computer.

* changed cc to g++
* added missing include libraries
* created header files instead of implicit definitions

**Example run:**
```
$ a.out
4+2-3*5 (PRESS ENTER)
token 256, tokenval 4
token 256, tokenval 2
+
token 256, tokenval 3
token 256, tokenval 5
*4+5 (PRESS ENTER)
*
token 256, tokenval 4
*
-
token 256, tokenval 5
```