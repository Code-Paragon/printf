#  _printf – Custom C Library Implementation of `printf`

A feature-rich reimplementation of the standard C `printf` function from scratch. This project showcases advanced formatting, custom flags, size specifiers, and modular print handlers — making it an ideal learning and interview preparation tool for low-level systems programming in C.

##  Overview

This project redefines the standard `printf` functionality under the name `_printf`, replicating most of its capabilities while extending the logic with:

- Buffer-based character writing
- Flag and width parsing
- Length/size modifiers
- Format-specific print handlers
- Graceful handling of unknown specifiers

It supports nearly all classic `printf` features such as `%d`, `%s`, `%x`, `%p`, etc., and extends it to include:

- **ROT13 encoding** via `%R`
- **String reversal** via `%r`
- **Hex representation for non-printable characters** via `%S`

##  Features

- Format specifiers: `%c`, `%s`, `%d`, `%i`, `%u`, `%x`, `%X`, `%o`, `%p`, `%b`, `%r`, `%R`, `%S`
- Flags: `+`, `-`, `0`, `#`, and space
- Width and precision support
- Length modifiers: `l`, `h`
- Buffer writing for performance
- Print handlers implemented modularly
- Extended support: ROT13, string reversal, non-printable ASCII

##  Key Files

| File                                             | Purpose                                                       |
|--------------------------------------------------|---------------------------------------------------------------|
| `_printf.c`                                      | Core loop for parsing and dispatching format specifiers       |
| `main.h`                                         | Declarations, macros, structs for handlers and flags          |
| `handle_print.c`                                 | Dispatcher that routes each specifier to its handler          |
| `function.c` & `function1.c`                     | Handlers for `char`, `string`, `int`, `binary`, `unsigned`, `octal`, `hex` |
| `function2.c`                                    | Handles pointer printing, ROT13, and reverse                  |
| `write_handlers.c`                               | Internal low-level formatting and padding logic               |
| `get_flags.c`, `get_width.c`, `get_precision.c`, `get_size.c` | Format parser helpers                             |
| `utils.c`                                        | Helper functions like size casting, print checks              |
| `main_test1.c`, `Test_Files/main_test.c`         | Sample tests comparing `_printf` with `printf`                |

##  Example Usage

```
_printf("Character: [%c]\n", 'H');
_printf("String: [%s]\n", "Custom printf");
_printf("Integer: [%d]\n", 1024);
_printf("Binary: [%b]\n", 5);
_printf("Pointer: [%p]\n", (void *)main);
_printf("Reverse: [%r]\n", "Hello");
_printf("ROT13: [%R]\n", "Hello");
```

##  Learning Objectives

- Deepen knowledge of variadic functions and argument handling in C
- Explore buffer management and custom string formatting
- Implement modular code and handler-based logic for extensibility
- Gain practical experience with parsing, memory, and error management

##  Build & Test

**Build:**
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o test_printf
```

**Run sample:**
```
./test_printf
```
Or compile and test against provided test files.

##  Limitations

- Not 100% compatible with all edge cases of the standard `printf`
- Floating-point formats (`%f`, `%e`, `%g`) are **not implemented**
- Locale and multi-byte/wide character support not included
- Error reporting is minimal — invalid formats may cause undefined behavior


