
/*
 *	Filename : swap_string.c
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

void swap_str(char ** str1, char ** str2)
{
	char * tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}

int main()
{
	char * str1 = "String1";
	char * str2 = "String2";
	
	printf("%s %s\n", str1, str2);
	
	swap_str(&str1, &str2);
	
	printf("%s %s\n", str1, str2);
	
	return 0;
}