# byacc

Berkeley yacc is a parser generator utility that reads a grammar specification
from a file and generates an LR(1) parser for it. The parsers consist of a set
of LALR(1) parsing tables and a driver routine written in the C programming
language. It has a public domain license which includes the generated C.

This package is configured with backtracking enable which makes it reasonably
compatible with GNU bison.

Note that for better compatibility with bison, byacc supports the
`--defines=<defines_file>` and `--output=<output_file>` options as alternatives
for `-H <defines_file>` and `-o <output_file>`. For example:

```
byacc --defines=parse.h --output=parse.c parse.y
```

Note also that the `byacc` executable provides `build2` metadata.
