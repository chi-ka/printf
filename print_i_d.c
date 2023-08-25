#include <stdio.h>
#include "main.h"

int print_i_d(int num,int charCount)
{
    int divisor;
    int digit;
    divisor = 1;
        
    if (num < 0)
    {
        _putchar('-');
        charCount++;
        num = -num;
    }

    while (num / divisor > 9)
    {
        divisor *= 10;
    }
    while (divisor > 0)
    {
        digit = num / divisor;
        _putchar('0' + digit);
        charCount++;
        num %= divisor;
        divisor /= 10;
    }
    
    return (charCount);
}
