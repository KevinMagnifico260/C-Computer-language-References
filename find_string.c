
/*
 *	Filename : find_string.c
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
#include <string.h>
#include <stdbool.h>

#define OFFSET_NULL 1

static bool find_str(char * str, char * find_str, unsigned int str_len, unsigned int find_str_len);

bool find_str(char * str, char * find_str, unsigned int str_len, unsigned int find_str_len)
{
	bool found = false;
	unsigned int count = 0;
	char tmp[find_str_len + OFFSET_NULL];

	if (find_str_len <= str_len)
	{
		for (unsigned int i = 0; i < find_str_len + OFFSET_NULL; i++)
		{
			tmp[i] = '\0';
		}

		for (unsigned int i = 0; i < str_len; i++)
		{
			printf("Searching -> ");
			for (unsigned int j = i; j < i + find_str_len; j++)
			{
				tmp[count] = str[j];
				if (j == find_str_len) tmp[count + OFFSET_NULL] = '\0';
				printf("%d ", j);
				count++;
			}
			count = 0;
			printf("= %s\n", tmp);
			if (strlen(tmp) < find_str_len)
			{
				break;
			}
			if (strncmp(tmp, find_str, find_str_len) == 0)
			{
				found = true;
				break;
			}
		}
	}
	else
	{
		fprintf(stderr, "%s are greater than %s\n", find_str, str);
	}
	return found;
}

int main()
{
	char * name = "Kevin Magnifico";
	char * find = "aga";
	printf("String  = %s\n", name);
	printf("Find    = %s\n", find);
	printf("----------------------------\n");
	bool found = find_str(name, find, strlen(name), strlen(find));
	printf("----------------------------\n");
	printf("Found : %d\n", found);
	return 0;
}



