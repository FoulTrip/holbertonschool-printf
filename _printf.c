#include <stdio.h>
#include <stdarg.h>

// Function for print a chain of characters in the standard output
int print_char(char c)
{
    putchar(c);
    return (1);
}

// Auxiliary function for print a chain of characters in the standard output
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

// Auxiliary function for print a Integer
int print_int(int num)
{
    return (printf("%d", num));
}

// Principal function _printf
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0; // Cuento los caracteres impresos

    while (*format)
    {
        if (*format == '%')
        {
            format++; // Avanzo despues del '%'
            char specifier = *format;

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
                // Si encuentro un carácter no reconocido después del '%', lo imprimo
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
    _printf("Hello, world!\n");
    _printf("A character: %c\n", 'A');
    _printf("A string: %s\n", "Hello");
    _printf("A percent sign: %%\n");
    _printf("Integer: %d\n", 42);

    return (0);
}