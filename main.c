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
	int num1 = 12, num2 = 16;
	int sum = num1 + num2;
	int res = num1 - num2;
	int mul = num1 * num2;
	int div = num1 / num2;
	int porc = num1 % num2;

        _printf("La suma de %i y %d es: %i\n", num1, num2, sum);
        _printf("La resta de %i y %d es: %i\n", num1, num2, res);
        _printf("La division de %i y %d es: %i\n", num1, num2, div);
        _printf("La multiplicacion de %i y %d es: %i\n", num1, num2, mul);
        _printf("El porcentaje entre %i y %d es: %i\n", num1, num2, porc);

        return (0);
}
