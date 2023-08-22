#include <stdio.h>
#include "main.h"

/**
 * printhex_to_buffer - Converts to hexadecimal and stores it in a buffer.
 *
 * @x: The unsigned integer to convert.
 * @uppercase: uppercase (1) or lowercase (0).
 * @buffer: The buffer to store the hexadecimal string.
 * @index: A pointer to the current index in the buffer.
 */

void printhex_to_buffer(unsigned int x,
		int uppercase, char *buffer, int *index)
{
	char hex_digits_lower[] = "0123456789abcdef";
	char hex_digits_upper[] = "0123456789ABCDEF";
	char *hex_digits = uppercase ? hex_digits_upper : hex_digits_lower;

	if (x > 15)
	{
		printhex_to_buffer(x / 16, uppercase, buffer, index);
	}
	buffer[(*index)++] = hex_digits[x % 16];
}
