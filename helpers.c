#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_char - Print a character to the output
 * @c: The character to be printed
 * 
 * This function prints the provided character to the standard output.
 * 
 * @c: The character to be printed.
 * 
 * Return: Returns 1 if the character was printed successfully.
 */
int print_char(char c) 
{
    putchar(c);
    return (1);
}

/**
 * print_string - Print a string to the output
 * @str: Pointer to the string to be printed
 * 
 * This function prints the given string to the standard output.
 * It iterates through the characters of the string and prints 
 * each character using putchar().
 * The function continues until it reaches the null-terminating 
 * character ('\0') of the string.
 * 
 * @str: Pointer to the null-terminated string to be printed.
 * 
 * Return: Returns the number of characters printed.
 */
int print_string(const char *str)
{
    int count = 0;
    while (*str)
    {
        putchar(*str);
        str++;
        count++;
    }
    return (count);
}

/**
 * print_int - Prints an integer to the output
 * @num: The integer to be printed
 * 
 * This function prints the provided integer to 
 * the standard output using the printf function.
 * 
 * @num: The integer to be printed.
 * 
 * Return: Returns the number of characters printed 
 *         (excluding the null byte used to end 
 *         output to strings).
 */
int print_int(int num)
{
    int is_negative, i;
    char digits[12];

    if (num == 0) 
    {
        putchar('0');
    }

    if (num < 0)
    {
        is_negative = 1;
        num = -num;
    }

    while (num > 0) 
    {
        digits[i++] = '0' + (num % 10);
        num /= 10;
    }

    if (is_negative)
    {
        digits[i++] = '-';
    }

    while (i > 0)
    {
        putchar(digits[--i]);
    }

    return (i);
}

/**
 * _printf - Print formatted output based on the provided
 *           format string and arguments.
 * @format: A pointer to the format string containing format 
 *          specifiers.
 * 
 * This function prints formatted output to the standard output 
 * based on the provided format string and the corresponding arguments. 
 * The format string may contain special format specifiers starting 
 * with '%', which will be replaced by the corresponding argument values.
 * 
 * @format: The format string containing format specifiers.
 * 
 * Return: The total number of characters printed.
 */
int _printf(const char *format, ...)
{
    char specifier;
    int count = 0; /*count the print characters */

    va_list args;
    va_start(args, format); 

    while (*format)
    {
        if (*format == '%')
        {
            format++; /* Avanzo despues del '%' */
            specifier = *format;

            switch (specifier)
            {
            case 'c':
            {
                char c = va_arg(args, int);
                count += print_char(c);
                break;
            }
            case 's':
            {
                char *str = va_arg(args, char *);
                count += print_string(str);
                break;
            }
            case '%':
            {
                count += print_char('%');
                break;
            }
            case 'i':
            case 'd':
            {
                int num = va_arg(args, int);
                count += print_int(num);
                break;
            }
            default:
            {
                /* If i find an unrecognized character after the '%', i print it. */
                count += print_char('%');
                count += print_char(*format);
                break;
            }
            }
        }
        else
        {
            count += print_char(*format);
        }

        format++;
    }

    va_end(args);
    return (count);
}
