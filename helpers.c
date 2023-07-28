#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <limits.h>

/**
 * print_char - Print a character to the output
 * @c: The character to be printed
 *
 * This function prints the provided character to the standard output.
 *
 * Return: return 1 if the character was printed successfully.
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
 * Return: Returns the number of characters printed.
 *
 */
int print_string(const char *str)
{
	int count = 0;

	if (str == NULL)
	{
		const char *nullStr = "(null)";

		while (*nullStr)
		{
			putchar(*nullStr);
			nullStr++;
			count++;
		}
	}
	else
	{
		while (*str)
		{
			putchar(*str);
			str++;
			count++;
		}
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
 * Return: Returns the number of characters printed
 *         (excluding the null byte used to end
 *         output to strings).
 */
int print_int(int num)
{
	char digits[12];
	int digitsNumbers = 0;

	if (num == 0)
	{
		digits[digitsNumbers++] = '0';

	}
	else
	{
		int isNegative = 0;

		if (num < 0)
		{
			isNegative = 1;
			num = -num;
		}

		while (num > 0)
		{
			digits[digitsNumbers++] = '0' + (num % 10);
			num /= 10;
		}

		if (isNegative)
		{
			digits[digitsNumbers++] = '-';
		}
	}

	while (digitsNumbers > 0)
	{
		putchar(digits[--digitsNumbers]);
	}

	return (digitsNumbers);
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
 * Return: The total number of characters printed.
 */
int _printf(const char *format, ...)
{
	int count;
	va_list args;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	count = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);

			if (*format == 'c')
				count += print_char(va_arg(args, int));
			else if (*format == 's')
				count += print_string(va_arg(args, char *));
			else if (*format == '%')
				count += print_char('%');
			else if (*format == 'i' || *format == 'd')
				count += print_int(va_arg(args, int));
			else
				count += print_char('%') + print_char(*format);
		}
		else
			count += print_char(*format);
		format++;
	}
	va_end(args);
	return (count);
}
