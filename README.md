# Calculator

This is a small command-line calculator written in C. It keeps the flow simple: pick an operation, enter two numbers, and get the result.

## Features

- Addition
- Subtraction
- Multiplication
- Division
- Basic input validation
- Protection against division by zero

## Build

Use any C compiler. With GCC:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -o calculator.exe calculator.c
```

## Run

On Windows:

```bash
calculator.exe
```

On Linux or macOS, build and run with:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -o calculator calculator.c
./calculator
```

## Files

- `calculator.c` - Main calculator program
