#include "main.h"

/**
 * int_to_str - converts an interger to a string
 *
 * @num: input number
 * @str: input string
 *
 * Return: (no return)
 *
 */
void int_to_str(int num, char *str)
{
        int i = 0;
        int j;
        int isNegative = 0;
        int len;
        char temp;

        if (num < 0)
        {
        isNegative = 1;
        num = -num;
        }

        while (num != 0)
        {
        str[i++] = '0' + (num % 10);
        num /= 10;
        }

        if (isNegative)
        str[i++] = '-';

        str[i] = '\0';

        len = _strlen(str);

        for (j = 0; j < len / 2; j++)
        {
        temp = str[j];
        str[j] = str[len - j - 1];
        str[len - j - 1] = temp;
        }
}
