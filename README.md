# writeacompiler

This is my brief foray through compiler writing. The main text I will be using are:

* Compilers Principles, Techniques, and Tools (Dragon book)
* Engineering a Compiler

The first example for the Dragon book needed some modification to work on my computer.

* changed cc to g++
* added missing include libraries
* created header files instead of implicit definitions

**Example run:**
```
$ cd src
$ make
$ ./basic < input.txt
```

** Bison Tutorial ** : http://alumni.cs.ucr.edu/~lgao/teaching/bison.html