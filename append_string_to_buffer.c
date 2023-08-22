#include <stdio.h>

/**
 * append_string_to_buffer - Appends a string to a buffer.
 * @s: The string to append.
 * @buffer: The buffer to append the string to.
 * @index: Pointer to the current index in the buffer.
 */

void append_string_to_buffer(const char *s, char *buffer, int *index)
{
	while (*s != '\0')
	{
		buffer[(*index)++] = *s;
		s++;
	}
}
