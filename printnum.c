#include <stdio.h>
#include "main.h"

/**
 * printnum_to_buffer - Converts an integer.
 *
 * @x: The integer to convert.
 * @buffer: The buffer to store the string.
 * @index: A pointer to the current index in the buffer.
 */

void printnum_to_buffer(int x, char *buffer, int *index)
{
	int a = x;

	if (a == INT_MIN)
	{
		buffer[(*index)++] = '-';
		a = -(a + 1);
	}
	if (a < 0)
	{
		buffer[(*index)++] = '-';
		a = -a;
	}
	if (a / 10)
	{
		printnum_to_buffer(a / 10, buffer, index);
	}
	buffer[(*index)++] = (a % 10) + '0';
}
