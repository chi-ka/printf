#include <stdio.h>

/**
 * append_char_to_buffer - Appends a character to a buffer.
 * @c: The character to append.
 * @buffer: The buffer to append the character to.
 * @index: Pointer to the current index in the buffer.
 */

void append_char_to_buffer(char c, char *buffer, int *index)
{
	buffer[(*index)++] = c;
}
