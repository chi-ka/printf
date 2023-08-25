#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - printsinput to standard output
 *
 * @format: the identifier
 *
 * Return: Returns count of the string.
 */

int _printf(const char *format, ...) 
{
	va_list args;

	va_start(args, format);

	int charCount = 0; 

	while (*format != '\0')
	{
		if (*format == '%') 
		{
			format++;
			switch (*format)
			{
				case 'c': 
					{
						char c;
						c = (char)va_arg(args, int);
						_putchar(c);
						charCount++;
						break;
					}
				case 's': 
					{
						char *s 
							s = va_arg(args, char *);
						while (*s != '\0') 
						{
							_putchar(*s);
							s++;
							charCount++;
						}
						break;
					}
				case '%':
					{
						_putchar('%');
						charCount++;
						break;
					}
			}
		}
		else
		{
			_putchar(*format);
			charCount++;
		}
		format++;
	}

	va_end(args);

	return charCount;
}


