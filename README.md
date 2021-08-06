# CLOX

This is a c implementation of the lox language defined on the book crafting interpreters.

On this implementation we use c to create a compiler instead of an interpreters, where it generates a bytecode of
the instructions instead of navigating through the AST.

To build the compiler you can use `make all` and it will generate a binary called `clox`. You can execute this
binary using `./clox`.
