#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>


#define BUFFER_SIZE 1024

void printoct_to_buffer(unsigned int x, char *buffer, int *index);
void printunum_to_buffer(unsigned int x, char *buffer, int *index);
void printnum_to_buffer(int x, char *buffer, int *index);
void printbin_to_buffer(unsigned int x, char *buffer, int *index);
void printhex_to_buffer(unsigned int x, int uppercase, char *buffer, int *index);
void printptr_to_buffer(void *ptr, char *buffer, int *index);
void append_char_to_buffer(char c, char *buffer, int *index);
void append_string_to_buffer(const char *s, char *buffer, int *index);
int _atoi(const char *str);
int _printf(const char *format, ...);
int _putchar(int c);
int print_s(char *s, int charCount);
int print_i_d(int num,int charCount);

#endif 
