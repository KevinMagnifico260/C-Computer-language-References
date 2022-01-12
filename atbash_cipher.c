
/*
 *	Filename : atbash_cipher.c
 *	Author & Copyright (c) : Kevin C. Magnifico
 *	Date created : 2021-12-07
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

static char * atbash_cipher(char * value);
static char atbash_cipher_buffer_switcher(char value);

char atbash_cipher_buffer_switcher(char value)
{
	// ABCDEFGHIJKLMNOPQRSTUVWXYZ
	// ZYXWVUTSRQPONMLKJIHGFEDCBA
	
	char result;
	char tmp_value = tolower(value);
	switch (tmp_value)
	{
		case 'a':
			result = 'z';
			break;
		case 'b':
			result = 'y';
			break;
		case 'c':
			result = 'x';
			break;
		case 'd':
			result = 'w';
			break;
		case 'e':
			result = 'v';
			break;
		case 'f':
			result = 'u';
			break;
		case 'g':
			result = 't';
			break;
		case 'h':
			result = 's';
			break;
		case 'i':
			result = 'r';
			break;
		case 'j':
			result = 'q';
			break;
		case 'k':
			result = 'p';
			break;
		case 'l':
			result = 'o';
			break;
		case 'm':
			result = 'n';
			break;
		case 'n':
			result = 'm';
			break;
		case 'o':
			result = 'l';
			break;
		case 'p':
			result = 'k';
			break;
		case 'q':
			result = 'j';
			break;
		case 'r':
			result = 'i';
			break;
		case 's':
			result = 'h';
			break;
		case 't':
			result = 'g';
			break;
		case 'u':
			result = 'f';
			break;
		case 'v':
			result = 'e';
			break;
		case 'w':
			result = 'd';
			break;
		case 'x':
			result = 'c';
			break;
		case 'y':
			result = 'b';
			break;
		case 'z':
			result = 'a';
			break;
		default:
			result = value;
			break;
	}
	return (isupper(value)) ? toupper(result) : tolower(result);
}

char * atbash_cipher(char * value)
{
	unsigned long int result_len = (strlen(value) + NULL_OFFSET);
	char * result = (char *)malloc(sizeof(char) * result_len);
	for (unsigned long int i = 0; i < result_len; i++)
	{
		*(result + i) = atbash_cipher_buffer_switcher(*(value + i));
	}
	return result;
}

int main()
{
	char * message = "Kevin C. Magnifico";
	
	printf("Plain Text  : %s\n", message);
	char * e_result = atbash_cipher(message);
	printf("Cipher Text : %s\n", e_result);
	
	printf("---------------------------------\n");
	
	printf("Cipher Text : %s\n", e_result);
	char * d_result = atbash_cipher(e_result);
	printf("Plain Text  : %s\n", d_result);
	
	// Dealloate the encrypted result from heap memory
	free(e_result);
	e_result = NULL;
	
	// Dealloate the decrypted result from heap memory
	free(d_result);
	d_result = NULL;
	
	return 0;
}
