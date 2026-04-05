# CE-On-Calc-Compiler
(Vibe) Porting rui314/chibicc to work on the ti84+ce family of calculators.

## What it does
This is a C compiler that runs **directly on the TI-84+CE calculator**. It reads C source code from a TI AppVar, compiles it, and outputs eZ80 assembly to another AppVar.

## Building
To build, you need the [CE toolchain](https://ce-programming.github.io/toolchain/) and in the main directory run `make`.

## Usage
1. Store your C source code in a TI AppVar (e.g., `MYSRC`)
2. Run: `CC MYSRC` (output goes to `OUTASM` by default)
3. Or: `CC MYSRC MYOUT` (specify output AppVar name)

## Architecture

### eZ80 Code Generation
The code generator targets the eZ80 CPU in ADL mode (24-bit):

- **Registers**: HL (accumulator), DE (secondary), IX (frame pointer)
- **Calling convention**: Arguments pushed right-to-left on stack, return in HL
- **Type sizes**: char=1, short=2, int=3 (24-bit), long=4, pointer=3

### Supported C features
- Integer types (char, short, int, long) - signed and unsigned
- Pointers and arrays
- Structs and unions
- Functions with parameters and return values
- Control flow (if/else, for, while, do-while, switch/case)
- All integer operators (+, -, *, /, %, bitwise, shifts, comparisons)
- Type casts
- Global and local variables
- String literals
- Preprocessor (#define, #ifdef, #if, etc.)

### Not yet supported
- Floating point (eZ80 has no FPU)
- `#include` (no filesystem on calculator)
- Variadic functions (va_args)
- 64-bit integers

## License
(I would have chosen a gnu license but chibicc uses the mit license so that is what I am going to use)
