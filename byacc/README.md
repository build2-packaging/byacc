# byacc

Berkeley yacc is a parser generator utility that reads a grammar specification
from a file and generates an LR(1) parser for it. The parsers consist of a set
of LALR(1) parsing tables and a driver routine written in the C programming
language. It has a public domain license which includes the generated C.

This package is configured with backtracking enable which makes it reasonably
compatible with GNU bison.
