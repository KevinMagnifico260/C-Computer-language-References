/*
 *	Filename : login_validation.c
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

#define STR_SIZE 50

#define STATIC_USERNAME "admin"
#define STATIC_PASSWORD "admin"

struct Login
{
	char username[STR_SIZE];
	char password[STR_SIZE];
};

static struct Login * login_new();
static void login_release(struct Login * self);
static void login_input(struct Login * self);
static void login_authenticate(struct Login * self);

struct Login * login_new()
{
	struct Login * self = (struct Login *)malloc(sizeof(*self));
	strcpy(self->username, "");
	strcpy(self->password, "");
	return self;
}

void login_release(struct Login * self)
{
	if (self != NULL)
	{
		free(self);
		self = NULL;
	}
}

void login_input(struct Login * self)
{
	printf("Enter your username : ");
	scanf("%50s", self->username);
	printf("Enter your password : ");
	scanf("%50s", self->password);
}

void login_authenticate(struct Login * self)
{
	unsigned int username_len = strlen(self->username);
	unsigned int password_len = strlen(self->password);
	if (strncmp(self->username, STATIC_USERNAME, username_len) == 0 && 
		strncmp(self->username, STATIC_PASSWORD, password_len) == 0)
	{
		printf("Login successfully.\n");
	}
	else
	{
		printf("Invalid username or password.\n");
	}
}

int main(int argc, char * argv[])
{
	struct Login * login = login_new();
	login_input(login);
	login_authenticate(login);
	login_release(login);
	return 0;
}

