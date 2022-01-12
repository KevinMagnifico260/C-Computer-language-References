
/*
 *	Filename : file_io.c
 *	Author & Copyright (c) : Kevin C. Magnifico
 *	Date created : 2021-11-19
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

#define MIT_LICENSE "MIT License\n" \
                    "\n" \
                    "Copyright (c) 2021 Kevin C. Magnifico\n" \
                    "\n" \
                    "Permission is hereby granted, free of charge, to any person obtaining a copy\n" \
                    "of this software and associated documentation files (the \"Software\"), to deal\n" \
                    "in the Software without restriction, including without limitation the rights\n" \
                    "to use, copy, modify, merge, publish, distribute, sublicense, and/or sell\n" \
                    "copies of the Software, and to permit persons to whom the Software is\n" \
                    "furnished to do so, subject to the following conditions:\n" \
                    "\n" \
                    "The above copyright notice and this permission notice shall be included in all\n" \
                    "copies or substantial portions of the Software.\n" \
                    "\n" \
                    "THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n" \
                    "IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n" \
                    "FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n" \
                    "AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n" \
                    "LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n" \
                    "OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE\n" \
                    "SOFTWARE.\n"

#define MENU "+----------------------------------+\n" \
             "|                                  |\n" \
             "+----------------------------------+\n" \
             "|                                  |\n" \
             "|       1. Write a License         |\n" \
             "|                                  |\n" \
             "|       2. Read a License          |\n" \
             "|                                  |\n" \
             "|                                  |\n" \
             "+----------------------------------+\n"

static void menu_display();
static bool	file_exist(FILE * file, const char * file_path);
static long int file_size(FILE * file, const char * file_path);
static void write_file(FILE * file, const char * file_path);
static void read_file(FILE * file, const char * file_path);

void menu_display()
{
	printf("%s\n", MENU);
}

bool file_exist(FILE * file, const char * file_path)
{
	return ((file = fopen(file_path, "r")) != NULL) ? true : false;
}

long int file_size(FILE * file, const char * file_path)
{
	file  = fopen(file_path, "r");
	fseek(file, 0L, SEEK_END);
    long int block_size = ftell(file);
    fclose(file);
    file = NULL;
	return block_size;
}

void write_file(FILE * file, const char * file_path)
{
	if (!file_exist(file, file_path))
	{
		file = fopen(file_path, "w");
		fprintf(file, "%s", MIT_LICENSE);
		fclose(file);
		file = NULL;
		printf("File was successfully write..\n");
		printf("---------------------------------------------\n\n");
		printf("%s", MIT_LICENSE);
	}
	else
	{
		printf("File already exist...\n");
	}
}

void read_file(FILE * file, const char * file_path)
{
	if (file_exist(file, file_path))
	{
		char * line = (char *)malloc((sizeof(char) * file_size(file, file_path)) + OFFSET_NULL);
		file = fopen(file_path, "r");
		while (true)
		{
			fgets(line, sizeof(line), file);
			if (feof(file))
			{ 
				break; 
			}
			printf("%s", line);
		}
		fclose(file);
		file = NULL;
		free(line);
		line = NULL;
	}
	else
	{
		fprintf(stderr, "Unable to open this file : %s\n", file_path);
	}
}

int main()
{
	const char * FILE_PATH = "./resources/LICENSE.txt";
	FILE * file = NULL;
	int choose = 0;
	menu_display();
	printf("Choose : ");
	scanf("%d", &choose);
	switch (choose)
	{
		case 1:
			write_file(file, FILE_PATH);
			break;
		case 2:
			read_file(file, FILE_PATH);
			break;
		default:
			printf("Invalid input !\n");
			break;
	}
	return 0;
}
