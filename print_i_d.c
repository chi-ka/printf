#include <stdio.h>
#include "main.h"

int print_i_d(int num,int charCount)
{
	int i;
	int divisor;
	int digit;
	int numDigits;
	int tempNum;

	divisor = 1;
	if (num == INT_MIN) 
	{
		_putchar('-');
		charCount++;
		num = -(num + 1);
	}
	if (num < 0)
	{
		_putchar('-');
		charCount++;
		num = -num;
	}
	numDigits = (num == 0) ? 1 : 0;
	tempNum = num;
	while (tempNum > 0)
	{
		tempNum /= 10;
		numDigits++;
	}
	charCount += numDigits;

	divisor = 1;
	for (i = 1; i < numDigits; i++)
	{
		divisor *= 10;
	}
	while (divisor > 0)
	{
		digit = num / divisor;
		_putchar('0' + digit);
		num %= divisor;
		divisor /= 10;
	}
	return (charCount);
}
