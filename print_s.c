#include <stdio.h>
#include "main.h"

int print_s(char *s, int charCount)
{
    while (*s != '\0') 
    {
        _putchar(*s);
        s++;
        charCount++;
    }
    
    return (charCount);
}
