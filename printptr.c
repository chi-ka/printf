#include <stdio.h>
#include "main.h"

/**
 * printptr_to_buffer - Converts a pointer to its hexadecimal.
 *
 * @ptr: The pointer to convert.
 * @buffer: The buffer to store the hexadecimal string.
 * @index: A pointer to the current index in the buffer.
 */

void printptr_to_buffer(void *ptr, char *buffer, int *index)
{
	unsigned long address;
	int ptr_width;
	int i;

	address	= (unsigned long)ptr;
	buffer[(*index)++] = '0';
	buffer[(*index)++] = 'x';

	ptr_width = sizeof(void *) * 2;

	for (i = 0; i < ptr_width - (int)(sizeof(address) * 2); i++)
	{
		buffer[(*index)++] = '0';
	}

	printhex_to_buffer(address, 0, buffer, index);
}
