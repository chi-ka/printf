#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
#define BUFFER_SIZE 1024

int _printf(const char *format, ...)
{
	va_list args;
	int num, c, i, num_spaces, nindex;
	char *s;
	int count = 0, index = 0, field_width = 0, left_align = 0;
	char buffer[BUFFER_SIZE];
	char num_buffer[BUFFER_SIZE];
	char length_modifier;
	int num_index = 0;
	unsigned long u_num;


	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) != '%')
		{
			format++;
			if (*format == '-')
			{
				format++;
				count++;
			}
			if (*format == '+')
			{
				buffer[index++] = '+';
				format++;
				count++;
			}
			if (*format == ' ')
			{
				buffer[index++] = ' ';
				format++;
				count++;
			}
			if (*format == '#')
			{
				if (*(format + 1) == 'x' || *(format + 1) == 'p' )
				{
					buffer[index++] = '0';
					buffer[index++] = 'x';
				}
				else if (*(format + 1) == 'X')
				{
					buffer[index++] = '0';
					buffer[index++] = 'X';
				}
				else if (*(format + 1) == 'o')
				{
					buffer[index++] = '0';
				}
				format++;
				count++;
			}
			if (*format == 'l' || *format == 'h' )
			{
				length_modifier = *format;
				format++;
				count++;
			}
			if (*format >= '1' && *format <= '9')
			{
				field_width = atoi(format);
				while (*format >= '0' && *format <= '9')
				{
					format++;
					count++;
				}
			}
			if (*format == 'c' )
			{
				c = va_arg(args, int);
				buffer[index++] = c;
				count++;
			}
			else if (*format == 'S' || *format == 's')
			{
				s = va_arg(args, char*);

				while (*s != '\0')
				{
					if (*s < 32 || *s >= 127) 
					{
						append_char_to_buffer('\\', buffer, &index);
						append_char_to_buffer('x', buffer, &index);
						printhex_to_buffer((unsigned int)*s, 1, buffer, &index);
					} 
					else 
					{
						append_char_to_buffer(*s, buffer, &index);
					}
					s++;
					count++;
				}
			}
			else if (*format == 'd' || *format == 'i')
			{
				nindex = index;

				if (length_modifier == 'h') 
				{
					num = (short)va_arg(args, int);
				} 
				else 
				{
					num = va_arg(args, int);
				}


				printnum_to_buffer(num, num_buffer, &num_index);

				nindex = num_index; 
				num_spaces = field_width - nindex;

				if (num_spaces > 0) 
				{
					if (left_align == 1)
					{
						append_string_to_buffer(num_buffer, buffer, &index);
						for (i = 0; i < num_spaces; i++)
						{
							append_char_to_buffer(' ', buffer, &index);
						}
					}
					else 
					{
						for (i = 0; i < num_spaces; i++) 
						{
							append_char_to_buffer(' ', buffer, &index);
						}
						append_string_to_buffer(num_buffer, buffer, &index);
					}
				} 
				else 
				{

					append_string_to_buffer(num_buffer, buffer, &index);
				}

				count++;

			}

			else if (*format == 'b' )
			{
				num = va_arg(args, int);
				printbin_to_buffer(num, buffer, &index);
				count++;
			}
			else if (*format == 'u')
			{
				if (length_modifier == 'h')
				{
					u_num = (unsigned short)va_arg(args, int);
					printunum_to_buffer(u_num, buffer, &index);
				}
				else if (length_modifier == 'l')
				{
					u_num = va_arg(args, unsigned long);
					printunum_to_buffer(u_num, buffer, &index);
				}
				else
				{
					u_num = va_arg(args, unsigned int);
					printunum_to_buffer(u_num, buffer, &index);
				}
				count++;
			}

			else if (*format == 'o')
			{
				if (length_modifier == 'h')
				{
					u_num = (unsigned short)va_arg(args, int);
					printoct_to_buffer(u_num, buffer, &index);
				}
				else if (length_modifier == 'l')
				{
					u_num = va_arg(args, unsigned long);
					printoct_to_buffer(u_num, buffer, &index);
				}
				else
				{
					u_num = va_arg(args, unsigned int);
					printoct_to_buffer(u_num, buffer, &index);
				}
				count++;
			}

			else if (*format == 'x' )
			{
				if (length_modifier == 'h')
				{
					u_num = (unsigned short)va_arg(args, int);
					printhex_to_buffer(u_num, 0, buffer, &index);
				}
				else if (length_modifier == 'l')
				{
					u_num = va_arg(args, unsigned long);
					printhex_to_buffer(u_num, 0, buffer, &index);
				}
				else
				{
					u_num = va_arg(args, unsigned int);
					printhex_to_buffer(u_num, 0, buffer, &index);
				}
				count++;
			}

			else if (*format == 'X')
			{
				if (length_modifier == 'h')
				{
					u_num = (unsigned short)va_arg(args, int);
					printhex_to_buffer(u_num, 1, buffer, &index);
				}
				else if (length_modifier == 'l')
				{
					unsigned long u_num;
					u_num = va_arg(args, unsigned long);
					printhex_to_buffer(u_num, 1, buffer, &index);
				}
				else
				{
					u_num = va_arg(args, unsigned int);
					printhex_to_buffer(u_num, 1, buffer, &index);
				}
				count++;
			}

			else if (*format == '%')
			{
				buffer[index++] = '%';
				count++;
			}
			else if (*format == 'p')
			{
				void *ptr = va_arg(args, void *);
				printptr_to_buffer(ptr, buffer, &index);
				count++;
			}
			else
			{
				buffer[index++] = *format;
				count++;
			}
		}
		else
		{
			buffer[index++] = *format;
			count++;
		}

		format++;
	}
	va_end(args);
	write(1, buffer, index);

	return (count);
}
