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
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -c main.c
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -c helpers.c
gcc -o _printf main.o helpers.o
```
To run the program, execute the compiled binary:
```bash
./_printf
```

# Examples
```c
#include "main.h"

int main(void)
{
    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;

    _printf("Length:[%d, %i]\n", len, len);
    _printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    _printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    _printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    _printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    _printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    _printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    _printf("Unknown:[%r]\n");
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
