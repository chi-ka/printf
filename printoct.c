#include <stdio.h>
#include "main.h"

/**
 * printoct_to_buffer - Converts to an octal string.
 *
 * @x: The unsigned integer to convert.
 * @buffer: The buffer to store the octal string.
 * @index: A pointer to the current index in the buffer.
 */

void printoct_to_buffer(unsigned int x, char *buffer, int *index)
{
	if (x == 0)
	{
		buffer[(*index)++] = '0';
		return;
	}
	if (x / 8)
	{
		printoct_to_buffer(x / 8, buffer, index);
	}
	buffer[(*index)++] = (x % 8) + '0';
}

