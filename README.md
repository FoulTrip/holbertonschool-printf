# Custom printf function in C

# Description
This project is a simple implementation of the printf function in C, allowing printing of strings and values with specific formats to the console. It provides a limited set of format specifiers, similar to the standard C library's printf function.

# Functionality
The custom _printf function supports the following format specifiers:
 - '%c': Prints a single character.
 - '%s': Prints a string of characters.
 - '%%': Prints a percent character (%).
 - '%d' or '%i': Prints an integer number in decimal format.

If an unrecognized format specifier is encountered, the '%' character followed by the unknown character will be printed.

# Auxiliary Functions
The project includes three auxiliary functions that are used by the '_print' function:
 1. print_char: Prints a single character to the console.
 2. print_string: Prints a string of characters to the console.
 3. print_int: Prints an integer number in decimal format to the console.

# Compilation and Usage

To compile the project, use the following command:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c -o main
```
To run the program, execute the compiled binary:
```bash
./main
```

# Examples
```c
#include "main.h"

int main(void)
{
    _printf("Hello, world!\n");
    _printf("A character: %c\n", 'A');
    _printf("A string: %s\n", "Hello");
    _printf("A percent sign: %%\n");
    _printf("Integer: %d\n", 42);

    return (0);
}
```
# Author
David vasquez Mahecha
