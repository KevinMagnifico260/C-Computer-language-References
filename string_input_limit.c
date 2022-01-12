
/*
 *	Filename : string_input_limit.c
 *	Author & Copyright (c) : Kevin C. Magnifico
 *	Date created : 2021-11-13
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

void new_line_buffer()
{
	getchar();
	fflush(stdin);	
}

int main()
{
	const unsigned int NAME_SIZE = 10;
	char name[NAME_SIZE];
	unsigned int len;
	
	do
	{
		printf("Enter %d characters only : ", NAME_SIZE);
		scanf("%[^\n]s", name);
		len = strlen(name);
		new_line_buffer();
	} while (len > NAME_SIZE);
	
	if (len > NAME_SIZE)
	{
		printf("Name : %s\n", name);
	}
	
	return 0;
}

