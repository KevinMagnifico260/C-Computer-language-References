
/*
 *	Filename : input_validation.c
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

#define NUM_SIZE 5

bool is_float (char * val)
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

void new_line_buffer()
{
	getchar();
	fflush(stdin);	
}

void disp_farr_output(float num[], unsigned int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("Count = %d,\tIndex = %d,\tValue = %.2f\n", (i + 1), i, num[i]);
	}
}

int main()
{
	float num[NUM_SIZE];
	char input[50];
	
	for (int i = 0; i < NUM_SIZE; i++)
	{
		printf("Enter your number %d : \n", (i + 1));
		while (true)
		{
			printf("> ");
			if (scanf("%50[^\n]s", input) && is_float(input))
			{
				num[i] = atof(input);
				new_line_buffer();
				break;
			}
			else
			{
				new_line_buffer();
			}
		}
	}
	disp_farr_output(num, NUM_SIZE);
	return 0;
}
