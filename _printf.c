#include <stdio.h>
#include <stdarg.h>

/* Function for print a chain of characters in the output */
int print_char(char c) 
{
    putchar(c);
    return (1);
}

/* Auxiliary function for print a chain of characters in the output */
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

/* Auxiliary function for print a Integer */
int print_int(int num)
{
    return (printf("%d", num));
}

/* Principal function _printf */
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

int main()
{
    /* Examples outputs */
    _printf("Let's try to printf a simple sentence.\n");
    _printf("String:[%s]\n", "I am a string !");
    _printf("Percent:[%%]\n");
    _printf("Unknown:[%r]\n");
    _printf("Int:[%i]\n", 24);

    return (0);
}
