
/*
 *	Filename : struct.c
 *	Author & Copyright (c) : Kevin C. Magnifico
 *	Date created : 2021-10-20
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

#define OFFSET_NULL 1 // this offset null is to avoid over flow into memory

// ----------------- USER STRUCT -----------------------

typedef struct USER_STRUCT // structure of user
{
	char * username; // user username
	char * password; // user password
} User;

// allocate the user object into heap memory
static User * user_create_new(char * username, char * password);

// deallocate the user object into heap memory
static void user_release(User * self);

User * user_create_new(char * username, char * password)
{
	// allocate the user object
	User * self = (User *)malloc(sizeof(* self));

	// get the username length into parameter
	size_t username_size = (strlen(username) + OFFSET_NULL);
	
	// get the password length into paramter
	size_t password_size = (strlen(password) + OFFSET_NULL);

	// allocate the user object username (self->username) size into memory heap
	// to recognize the size of the username parameter
	self->username = (char *)malloc((sizeof(char) * username_size));

	// allocate the user object password (self->password) size into memory heap
	// to recognize the size of the password parameter
	self->password = (char *)malloc((sizeof(char) * password_size));
	
	// copy the username parameter into user object username
	strncpy(self->username, username, username_size);
	
	// copy the password  parameter into user object password
	strncpy(self->password, password, password_size);

	// return the user object
	return self;
}

void user_release(User * self)
{
	// check if user object is not NULL into heap memory
	// if it is a NULL they wont deallocate into heap memory because they can have memory leaks
	// or if it is not they can deallocate the user object into heap memory
	// Note : this condition "self != NULL" is to avoid memory leaks
	if (self != NULL)
	{
		// check the username object if it is not NULL to avoid memory leaks
		if (self->username != NULL)
		{ 
			// deallocate the username from the user object
			free(self->username);
			self->username = NULL;
		} 

		// check the password object if it is not NULL to avoid memory leaks
		if (self->password != NULL)
		{
			// deallocate the password from the user object
			free(self->password);
			self->password = NULL;
		} 

		free(self); // deallocate the user object
		self = NULL;
	}
}

// check the user information
void user_check_info(User * self)
{
	printf("Username : %s\n", self->username);
	printf("Password : %s\n", self->password);
}

// ----------------------------------------------

int main()
{
	User * user = user_create_new("admin", "admin");
	user_check_info(user);
	user_release(user);
	return 0;
}
