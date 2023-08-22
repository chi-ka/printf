#include <stdio.h>
#include "main.h"

/**
 * printbin_to_buffer - Convert to binary and stores it in a buffer.
 *
 * @x: The unsigned integer to convert.
 * @buffer: The buffer to store the binary string.
 * @index: A pointer to the current index in the buffer.
 */

void printbin_to_buffer(unsigned int x, char *buffer, int *index)
{
	if (x > 1)
	{
		printbin_to_buffer(x / 2, buffer, index);
	}
	buffer[(*index)++] = (x % 2) + '0';
}

