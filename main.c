#include "main.h"

/**
 * main - The main function of the program.
 * 
 * This is the main function that demonstrates
 * the usage of the custom _printf function.
 * It calls _printf multiple times with different 
 * format specifiers and arguments to print various 
 * types of data.
 * 
 * Return: Always returns 0.
 */
int main(void)
{
    _printf("Let's try to printf a simple sentence.\n");
    _printf("String:[%s]\n", "I am a string !");
    _printf("Percent:[%%]\n");
    _printf("Unknown:[%r]\n");
    _printf("Int:[%i]\n", 24);

    return (0);
}