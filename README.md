# ft_printf

`ft_printf` is a project from the 42 school curriculum. The goal is to reimplement, in C, a simplified version of the standard `printf` function, handling formatted output and variadic arguments.

## What it is
- Recreates core behavior of `printf` using only allowed standard C functions
- Parses a format string and prints values accordingly
- Demonstrates handling of variadic arguments with `stdarg.h`

## Why it exists
This exercise teaches:
- Parsing and formatting of strings
- Robust handling of different data types
- Safe and structured coding practices in C

## Usage (example)
```c
int len = ft_printf("Hello %s %d\n", "world", 42);
```

## Notes
- This is an educational reimplementation and may support a subset of the full `printf` specification as defined by project requirements.
- Behavior aims to mimic the standard `printf` where applicable within the constraints of the project.


