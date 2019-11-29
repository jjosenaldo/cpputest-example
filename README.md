# CppUTest example

This is an example project using some features of the [CppUTest](https://cpputest.github.io/) tool, which is used for unit-testing and tdd-ing C/C++ code. It has the implementation of a stack, with its basic operations of push, pop and top, and a calculator having only the addition operation.

The project was part of an assignment of the DIM0436 - ESPECIFICACAO E VERIFICACAO DE PROGRAMAS (program specification and verification) course, in which the students had to present tools for automated testing of C code.

## Prerequisites

* CppUTest (obviously)
* gcc and g++ compilers

## Usage

First of all, you need to change the [Makefile](test/Makefile). Set the `PROJECT_DIR` variable to the path of this repo on your machine. If you installed CppUTest via `apt-get` or the like, remove the line that declares the `CPPUTEST_HOME` variable. Otherwise, change it to the installation folder of CppUTest on your pc.

Enter the [test](test/) directory. Run `make test` for executing the test files in the [test/calc](test/calc) and [test/stack](test/stack) dirs. For generating reports based on the [gcov](https://gcc.gnu.org/onlinedocs/gcc/Gcov.html) tool, run `make gcov`.

## Authors

* Josenaldo Júnior
* Shirley Freitas