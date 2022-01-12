
/*
 *	Filename : reverse_string_array.c
 *	Author & Copyright (c) : Kevin C. Magnifico
 *	Date created : 2021-11-17
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

static void swap_str(char ** str1, char ** str2);
static void reverse_str(char ** str_arr, unsigned int length);

void swap_str(char ** str1, char ** str2)
{
	char * tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}

void reverse_str(char ** str_arr, unsigned int length)
{
	for (unsigned int x = 0; x < length; x++)
	{
		for (unsigned int y = 0; y < x; y++)
		{
			swap_str(&str_arr[x], &str_arr[y]);
		}
	}
}

int main()
{
	char * str_arr[] = {"Array 1", "Array 2", "Array 3", "Array 4", "Array 5", "Array 6"};
	
	for (unsigned int i = 0; i < (sizeof(str_arr) / sizeof(*str_arr)); i++)
	{
		printf("%s\n", str_arr[i]);
	}
	
	printf("--------------------------------\n");
	unsigned int str_arr_len = (sizeof(str_arr) / sizeof(*str_arr));
	reverse_str(str_arr, str_arr_len);
	
	for (unsigned int i = 0; i < str_arr_len; i++)
	{
		printf("%s\n", str_arr[i]);
	}
	
	return 0;
}







