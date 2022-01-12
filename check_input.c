
/*
 *	Filename : check_input.c
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

bool is_integer(char * val)
{
	bool result = true;
	for (int i = 0; i < strlen(val); i++)
	{
		if (isalpha(val[i]) || isspace(val[i]) || val[i] == '.')
		{
			result = false;
			break;
		}
	}
	return result;
}

bool is_float(char * val)
{
	bool result = true;
	for (int i = 0; i < strlen(val); i++)
	{
		if (isalpha(val[i]) || isspace(val[i]))
		{
			result = false;
			break;
		}
	}
	return result;
}

int main()
{
	char num[50];
	bool result;
	
	printf("Enter an integer : ");
	scanf("%s", num);
	
	if (is_integer(num))
	{
		printf("It\'s an integer\n");
	}
	else
	{
		printf("It\'s not an integer\n");
	}
	
	if (is_float(num))
	{
		printf("It\'s a float\n");
	}
	else
	{
		printf("It\'s not a float\n");
	}
	
	if (!is_integer(num) && !is_float(num))
	{
		printf("it\'s a string\n");
	}
	
	return 0;
}
