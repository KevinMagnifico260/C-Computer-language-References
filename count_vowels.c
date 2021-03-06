
/*
 *	Filename : count_vowels.c
 *	Author & Copyright (c) : Kevin C. Magnifico
 *	Date created : 2021-11-10
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
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool is_vowel(char val)
{
	bool result = false;
	val = tolower(val);
	switch (val)
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			result = true;
			break;
	}
	return result;
}

unsigned int count_vowels(char * val)
{
	int count = 0;
	unsigned int val_len = strlen(val);
	for (unsigned int i = 0; i < val_len; i++)
	{
		if (is_vowel(val[i]))
		{
			count++;
		}
	}
	return count;
}

int main()
{
	char str[50];
	int result = 0;
	printf("Enter a string : ");
	scanf("%[^\n]s", str);
	result = count_vowels(str);
	printf("Vowels count = %d\n", result);
	return 0;
}
