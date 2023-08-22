#include <stdio.h>
#include "main.h"

/**
 * printunum_to_buffer - Converts to a string.
 *
 * @x: The unsigned integer to convert.
 * @buffer: The buffer to store the string.
 * @index: A pointer to the current index in the buffer.
 */

void printunum_to_buffer(unsigned int x, char *buffer, int *index)
{
	if (x == 0)
	{
		buffer[(*index)++] = '0';
		return;
	}
	if (x / 10)
	{
		printunum_to_buffer(x / 10, buffer, index);
	}
	buffer[(*index)++] = (x % 10) + '0';
}
