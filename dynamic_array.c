
/*
 *	Filename : dynamic_array.c
 *	Author & Copyright (c) : Kevin C. Magnifico
 *	Date created : 2021-11-25
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

struct Person
{
	char firstname[50];
	char lastname[50];
};

static void persons_input(struct Person * persons, unsigned int persons_len);
static void persons_display_info(struct Person * persons, unsigned int persons_len);

void persons_input(struct Person * persons, unsigned int persons_len)
{
	for (unsigned int i = 0; i < persons_len; i++)
	{
		printf("Enter your firstname : ");
		scanf("%50s", persons[i].firstname);
		printf("Enter your lastname : ");
		scanf("%50s", persons[i].lastname);
	}
}

void persons_display_info(struct Person * persons, unsigned int persons_len)
{
	for (unsigned int i = 0; i < persons_len; i++)
	{
		printf("%d. Name : %s %s\n", (i+1), persons[i].firstname, persons[i].lastname);
	}
}

int main()
{	
	unsigned int persons_len;
	
	printf("How many persons do you wan\'t : ");
	scanf("%d", &persons_len);
	
	struct Person * persons = (struct Person *)malloc(sizeof(struct Person) * persons_len);
	
	persons_input(persons, persons_len);
	persons_display_info(persons, persons_len);
	
	free(persons);
	persons = NULL;
	
	return 0;
}



















