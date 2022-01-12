
/*
 *	Filename : menu.c
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

#define RUNNING 1

#define MENU "\n\t+----------------------------------+\n" \
             "\t|    Hot Coffee Bending Machine    |\n" \
             "\t+----------------------------------+\n" \
             "\t|                                  |\n" \
             "\t|       <1>. Black Coffee          |\n" \
             "\t|                                  |\n" \
             "\t|       <2>. Brown Coffee          |\n" \
             "\t|                                  |\n" \
             "\t|       <3>. White Coffee          |\n" \
             "\t|                                  |\n" \
             "\t|       <4>. Choco Coffee          |\n" \
             "\t|                                  |\n" \
             "\t|       <5>. About us              |\n" \
             "\t|                                  |\n" \
             "\t+----------------------------------+\n" \
             "\t|       Available Cups :  50       |\n" \
             "\t+----------------------------------+\n"

static void clear_console();
static void console_pause();
static void menu_display();
static void menu_input_choose();
static void run_app();

void clear_console()
{
	#if defined(__linux__) || defined(__unix__)
		system("clear");
	#elif defined(_WIN32) || defined(_WIN64)
		system("cls");
	#endif
}

void console_pause()
{
	printf("\tPress any key to continue...\n");
	getchar();
}

void menu_display()
{
	printf("%s", MENU);
}

void menu_input_choose()
{
	char choose;
	printf("\n\tChoose : ");
	scanf("%c", &choose);
	switch (choose)
	{
		case '1':
			printf("\n\tYou choose black coffee\n\n");
			console_pause();
			getchar();
			break;
		case '2':
			printf("\n\tYou choose brown coffee\n\n");
			console_pause();
			getchar();
			break;
		case '3':
			printf("\n\tYou choose white coffee\n\n");
			console_pause();
			getchar();
			break;
		case '4':
			printf("\n\tYou choose choco coffee\n\n");
			console_pause();
			getchar();
			break;
		case '5':
			printf("\n\tCreated by : Kevin C. Magnifico\n\n");
			console_pause();
			getchar();
			break;
		default:
			printf("\n\tInvalid input !\n\n");
			console_pause();
			if (choose != '\n')
			{
				getchar();
			}
			break;
	}
	clear_console();
}

void run_app()
{
	do
	{
		clear_console();
		menu_display();
		menu_input_choose();
	} while(RUNNING);
}

int main()
{
	run_app();
	return 0;
}

