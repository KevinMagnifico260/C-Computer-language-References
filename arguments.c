
/*
 *	Filename : arguments.c
 *	Author & Copyright (c) : Kevin C. Magnifico
 *	Date created : 2021-11-16
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

static void warning_message();  // This is a warning message every syntax error.
static void help_message();     // Help the user
static void version_message();  // Version and Date release of this program
static void about_message();    // About this program

void warning_message()
{
	printf("Undefined options.\n");
	printf("Add option --help to give you a guide.\n");
}

void help_message()
{
	printf("Syntax or Usage : program [OPTION]\n");
	printf("Description : This is a sample program for console application\n\n");
	printf("[OPTION]\n");
	printf("\t-h | --help - It uses to help the user.\n");
	printf("\t-v | --version - Version of this program release.\n");
	printf("\t-a | --about - About this program.\n");
}

void version_message()
{
	printf("Date released : 2021-11-16\n");
	printf("Version : v1.0\n");
}

void about_message()
{
	printf("             +-------+\n");
	printf("             | About |\n");
	printf("+------------+-------+------------+\n");
	printf("| Created by : Kevin C. Magnifico |\n");
	printf("+-------+-------------------------+\n");
}

int main(int argc, char * argv[])
{
	if (argc == 2)
	{
		if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
		{
			help_message();
		}
		else if (strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0)
		{
			version_message();
		}
		else if (strcmp(argv[1], "--about") == 0 || strcmp(argv[1], "-a") == 0)
		{
			about_message();
		}
		else
		{
			warning_message();
		}
	}
	else
	{
		warning_message();
	}
	return 0;
}



