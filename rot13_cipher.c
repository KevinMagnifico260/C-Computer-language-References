
/*
 *	Filename : rot13_cipher.c
 *	Author & Copyright (c) : Kevin C. Magnifico
 *	Date created : 2021-12-10
 *	Written in : C
 *
 *	---------------------------------------------------------------------------------
 *
 *	MIT License
 *
 *	Copyright (c) 2021 Kevin C. Magnifico
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in all
 *	copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 *
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NULL_OFFSET 1

static char * rot13_cipher(char * value);
static char rot13_cipher_buffer_switcher(char value);

char rot13_cipher_buffer_switcher(char value)
{
	// ABCDEFGHIJKLM
	// NOPQRSTUVWXYZ
	
	char result;
	char tmp_value = tolower(value);
	switch (tmp_value)
	{
		case 'a':
			result = 'n';
			break;
		case 'b':
			result = 'o';
			break;
		case 'c':
			result = 'P';
			break;
		case 'd':
			result = 'q';
			break;
		case 'e':
			result = 'r';
			break;
		case 'f':
			result = 's';
			break;
		case 'g':
			result = 't';
			break;
		case 'h':
			result = 'u';
			break;
		case 'i':
			result = 'v';
			break;
		case 'j':
			result = 'w';
			break;
		case 'k':
			result = 'x';
			break;
		case 'l':
			result = 'y';
			break;
		case 'm':
			result = 'z';
			break;
		// ----------------------------------
		case 'n':
			result = 'a';
			break;
		case 'o':
			result = 'b';
			break;
		case 'p':
			result = 'c';
			break;
		case 'q':
			result = 'd';
			break;
		case 'r':
			result = 'e';
			break;
		case 's':
			result = 'f';
			break;
		case 't':
			result = 'g';
			break;
		case 'u':
			result = 'h';
			break;
		case 'v':
			result = 'i';
			break;
		case 'w':
			result = 'j';
			break;
		case 'x':
			result = 'k';
			break;
		case 'y':
			result = 'l';
			break;
		case 'z':
			result = 'm';
			break;
		default:
			result = value;
			break;
	}
	return (isupper(value)) ? toupper(result) : tolower(result);
}

char * rot13_cipher(char * value)
{
	unsigned long int result_len = (strlen(value) + NULL_OFFSET);
	char * result = (char *)malloc(sizeof(char) * result_len);
	for (unsigned long int i = 0; i < result_len; i++)
	{
		*(result + i) = rot13_cipher_buffer_switcher(*(value + i));
	}
	return result;
}

int main()
{
	char * message = "Kevin C. Magnifico";
	
	printf("Plain Text  : %s\n", message);
	char * e_result = rot13_cipher(message);
	printf("Cipher Text : %s\n", e_result);
	
	printf("---------------------------------\n");
	
	printf("Cipher Text : %s\n", e_result);
	char * d_result = rot13_cipher(e_result);
	printf("Plain Text  : %s\n", d_result);
	
	// Dealloate the encrypted result from heap memory
	free(e_result);
	e_result = NULL;
	
	// Dealloate the decrypted result from heap memory
	free(d_result);
	d_result = NULL;
	
	return 0;
}
