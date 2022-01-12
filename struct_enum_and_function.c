
/*
 *	Filename : struct_enum_and_function.c
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

#define NULL_OFFSET 1

enum Position
{
	POSITION_JUNIOR_SOFTWARE_DEVELOPER = 001,
	POSITION_SENIOR_SOFTWARE_DEVELOPER = 002,
	POSITION_SOFTWARE_ARCHITECT = 003,
	POSITION_SOFTWARE_ENGINEER = 004,
	POSITION_SOFTWARE_MANAGER = 005,
};

struct Person
{
	char * firstname;
	char middleinitial;
	char * lastname;
	unsigned int age;
	unsigned int years_experience;
	char ** skills;
	unsigned int skills_len;
};

struct Employee
{
	unsigned int emp_id;
	enum Position position;
	struct Person * person;
};

// ------------------ Employee struct functionality start ------------------

// Create or Allocating
static struct Employee * employee_create_new();

// Destroy or Deallocating
static void employee_release(struct Employee * self);

// Setter
static void employee_set_emp_id(struct Employee * self, unsigned int emp_id);
static void employee_set_position(struct Employee * self, enum Position position);
static void employee_set_person(struct Employee * self, struct Person * person);

// Getter
static struct Employee * employee_get(struct Employee * self);
static unsigned int employee_get_emp_id(struct Employee * self);
static enum Position employee_get_position(struct Employee * self);
static char * employee_get_position_str(struct Employee  * self);
static struct Person * employee_get_person(struct Employee * self);

// ------------------ Employee struct functionality end ------------------

// ------------------ Person struct functionality start ------------------

// Create or Allocating
static struct Person * person_create_new(char * firstname, char middleinitial, char * lastname);

// Destroy or Deallocating
static void person_release(struct Person * self);

// Setter
static void person_set_fullname(struct Person * self, char * firstname, char middleinitial, char * lastname);
static void person_set_age(struct Person * self, unsigned int age);
static void person_set_years_experience(struct Person * self, unsigned int years_experience);
static void person_set_skills(struct Person * self, char * skills[], unsigned int skills_len);

// Getter
static struct Person * person_get(struct Person * self);
static char * person_get_firstname(struct Person * self);
static char person_get_middleinitial(struct Person * self);
static char * person_get_lastname(struct Person * self);
static char * person_get_fullname(struct Person * self);
static unsigned int person_get_age(struct Person * self);
static unsigned int person_get_years_experience(struct Person * self);
static char ** person_get_skills(struct Person * self);
static char * person_get_skill(struct Person * self, unsigned int index);
static unsigned int person_get_skills_length(struct Person * self);

// ------------------ Person struct functionality end ------------------

// ------------------ Employee functionality declaration start ------------------

struct Employee * employee_create_new()
{
	struct Employee * self = (struct Employee *)malloc(sizeof(*self));
	return self;
}

void employee_release(struct Employee * self)
{
	if (self != NULL)
	{
		free(self);
		self = NULL;
	}
}

void employee_set_emp_id(struct Employee * self, unsigned int emp_id)
{
	self->emp_id = emp_id;
}

void employee_set_position(struct Employee * self, enum Position position)
{
	self->position = position;
}

void employee_set_person(struct Employee * self, struct Person * person)
{
	self->person = person;
}

struct Employee * employee_get(struct Employee * self)
{
	return (self != NULL) ? self : NULL;
}

unsigned int employee_get_emp_id(struct Employee * self)
{
	return self->emp_id;
}

enum Position employee_get_position(struct Employee * self)
{
	return self->position;
}

char * employee_get_position_str(struct Employee * self)
{
	/*
		POSITION_JUNIOR_SOFTWARE_DEVELOPER = 001,
		POSITION_SENIOR_SOFTWARE_DEVELOPER = 002,
		POSITION_SOFTWARE_ARCHITECT = 003,
		POSITION_SOFTWARE_ENGINEER = 004,
		POSITION_SOFTWARE_MANAGER = 005,
	*/
	char * pos_str = (char *)malloc(sizeof(char) * 30);
	switch (self->position)
	{
		case POSITION_JUNIOR_SOFTWARE_DEVELOPER:
			strcpy(pos_str, "Junior Software Developer");
			break;
		case POSITION_SENIOR_SOFTWARE_DEVELOPER:
			strcpy(pos_str, "Senior Software Developer");
			break;
		case POSITION_SOFTWARE_ARCHITECT:
			strcpy(pos_str, "Software Architect");
			break;
		case POSITION_SOFTWARE_ENGINEER:
			strcpy(pos_str, "Software Engineer");
			break;
		case POSITION_SOFTWARE_MANAGER:
			strcpy(pos_str, "Software Manager");
			break;
	}
	return pos_str;
}

struct Person * employee_get_person(struct Employee * self)
{
	return (self->person != NULL) ? self->person : NULL;
}

// ------------------ Employee functionality declaration end ------------------

// ------------------ Person functionality declaration start ------------------

struct Person * person_create_new(char * firstname, char middleinitial, char * lastname)
{
	struct Person * self = (struct Person *)malloc(sizeof(*self));
	unsigned int init_firstname_len = strlen(firstname) + NULL_OFFSET;
	unsigned int init_lastname_len = strlen(lastname) + NULL_OFFSET;
	self->firstname = (char *)malloc(sizeof(char) * init_firstname_len);
	self->lastname = (char *)malloc(sizeof(char) * init_lastname_len);
	strncpy(self->firstname, firstname, init_firstname_len);
	self->middleinitial = middleinitial;
	strncpy(self->lastname, lastname, init_lastname_len);
	self->skills_len = 0;
	return self;
}

void person_release(struct Person * self)
{
	if (self != NULL)
	{
		if (self->firstname != NULL)
		{
			free(self->firstname);
			self->firstname = NULL;
		}
		if (self->lastname != NULL)
		{
			free(self->lastname);
			self->lastname = NULL;
		}
		if (self->skills != NULL)
		{
			free(self->skills);
			self->skills = NULL;
		}
		free(self);
		self = NULL;
	}
}


void person_set_fullname(struct Person * self, char * firstname, char middleinitial, char * lastname)
{
	unsigned int firstname_len = strlen(firstname) + NULL_OFFSET;
	unsigned int lastname_len = strlen(lastname) + NULL_OFFSET;
	
	self->firstname = (char *)realloc(self->firstname, sizeof(char) * firstname_len);
	self->lastname = (char *)realloc(self->lastname, sizeof(char) * lastname_len);
	
	strncpy(self->firstname, firstname, firstname_len);
	self->middleinitial = middleinitial;
	strncpy(self->lastname, lastname, lastname_len);
}

void person_set_age(struct Person * self, unsigned int age)
{
	self->age = age;
}

void person_set_years_experience(struct Person * self, unsigned int years_experience)
{
	self->years_experience = years_experience;
}

void person_set_skills(struct Person * self, char * skills[], unsigned int skills_len)
{
	self->skills_len = skills_len;
	self->skills = (char **)malloc((sizeof(char *) * self->skills_len));
	for (unsigned int i = 0; i < skills_len; i++)
	{
		self->skills[i] = (char*)skills[i];
	}
}

struct Person * person_get(struct Person * self)
{
	return (self != NULL) ? self : NULL;
}

char * person_get_firstname(struct Person * self)
{
	return (self->firstname != NULL) ? self->firstname : "";
}

char person_get_middleinitial(struct Person * self)
{
	return self->middleinitial;
}

char * person_get_lastname(struct Person * self)
{
	return (self->lastname != NULL) ? self->lastname : "";
}

char * person_get_fullname(struct Person * self)
{
	const unsigned int SPACE_SIZE = 2;
	char middleinitial_str_tmp[2] = { self->middleinitial, '\0' };
	unsigned int fullname_len = (strlen(self->firstname) + sizeof(middleinitial_str_tmp) + strlen(self->lastname) + SPACE_SIZE) + NULL_OFFSET;
	char * fullname = (char *)malloc(sizeof(char) * fullname_len);
	strcpy(fullname, self->firstname);
	strcat(fullname, " ");
	strcat(fullname, middleinitial_str_tmp);
	strcat(fullname, " ");
	strcat(fullname, self->lastname);
	return fullname;
}

unsigned int person_get_age(struct Person * self)
{
	return self->age;
}

unsigned int person_get_years_experience(struct Person * self)
{
	return self->years_experience;
}

char ** person_get_skills(struct Person * self)
{
	return self->skills;
}

char * person_get_skill(struct Person * self, unsigned int index)
{
	return self->skills[index];
}

unsigned int person_get_skills_length(struct Person * self)
{
	return self->skills_len;
}

// ------------------ Person functionality declaration end ------------------

void release_str(char * value)
{
	if (value != NULL)
	{
		free(value);
		value = NULL;
	}
}

int main()
{
	const unsigned int ARR_SIZE = 5;
	struct Person * per[ARR_SIZE];
	struct Employee * emp[ARR_SIZE];
	
	// Person
	
	for (unsigned int i = 0; i < ARR_SIZE; i++)
	{
		per[i] = person_create_new("\0", '\0', "\0");
	}
	
	person_set_fullname(per[0], "Kevin", 'C', "Magnifico");
	person_set_fullname(per[1], "Gilbert", 'F', "Kawolski");
	person_set_fullname(per[2], "Dimitri", 'A', "Mendeliv");
	person_set_fullname(per[3], "Boris", 'J', "Salweha");
	person_set_fullname(per[4], "Angel", 'E', "Mabilata");
	
	person_set_age(per[0], 21);
	person_set_age(per[1], 28);
	person_set_age(per[2], 23);
	person_set_age(per[3], 25);
	person_set_age(per[4], 22);
	
	person_set_years_experience(per[0], 3);
	person_set_years_experience(per[1], 5);
	person_set_years_experience(per[2], 1);
	person_set_years_experience(per[3], 2);
	person_set_years_experience(per[4], 1);
	
	person_set_skills(per[0], 
	(char *[])
	{
		"Desktop App Developer", 
		"Embedded Software Developer", 
		"Android App Developer", 
		"Game Developer", 
		"Computer Researcher"
	}
	, 5);
	
	person_set_skills(per[1], 
	(char *[])
	{
		"Desktop App Developer", 
		"Web Developer", 
		"Android App Developer", 
	}
	, 3);
	
	person_set_skills(per[2], 
	(char *[])
	{
		"Desktop App Developer", 
		"Embedded Software Developer", 
		"Computer Researcher"
	}
	, 3);
	
	person_set_skills(per[3], 
	(char *[])
	{
		"Desktop App Developer",
		"Android App Developer", 
		"Computer Researcher"
	}
	, 3);
	
	person_set_skills(per[4], 
	(char *[])
	{
		"Desktop App Developer", 
		"Web Developer", 
		"Android App Developer", 
		"Game Developer", 
	}
	, 4);
	
	// Employee
	
	for (unsigned int i = 0; i < ARR_SIZE; i++)
	{
		emp[i] = employee_create_new();
	}
	
	for (unsigned int i = 0; i < ARR_SIZE; i++)
	{
		employee_set_emp_id(emp[i], (i + 100));
	}
	
	employee_set_position(emp[0], POSITION_SOFTWARE_ARCHITECT);
	employee_set_position(emp[1], POSITION_JUNIOR_SOFTWARE_DEVELOPER);
	employee_set_position(emp[2], POSITION_SOFTWARE_ENGINEER);
	employee_set_position(emp[3], POSITION_SENIOR_SOFTWARE_DEVELOPER);
	employee_set_position(emp[4], POSITION_SOFTWARE_MANAGER);
	
	for (unsigned int i = 0; i < ARR_SIZE; i++)
	{
		employee_set_person(emp[i], per[i]);
	}
	
	// Display Output
	
	for (unsigned int i = 0; i < ARR_SIZE; i++)
	{	
		char * employee_fullname = person_get_fullname(employee_get_person(emp[i]));
		char * employee_position = employee_get_position_str(emp[i]);
		unsigned int skills_len = person_get_skills_length(employee_get_person(emp[i]));
		
		printf(" ----------------Employee----------------\n\n");
		printf("  ID        : %d\n", employee_get_emp_id(emp[i]));
		printf("  Name      : %s\n", employee_fullname);
		printf("  Posiition : %s\n", employee_position);
		printf("  Skills    : %d\n\n", skills_len);
		for (unsigned int j = 0; j < skills_len; j++)
		{
			printf("    * %s\n", person_get_skill(employee_get_person(emp[i]), j));
		}
		printf("\n ----------------------------------------\n\n\n");
		
		release_str(employee_fullname);
		release_str(employee_position);
	}
	
	// Deallocating
	
	for (unsigned int i = 0; i < ARR_SIZE; i++)
	{
		employee_release(emp[i]);
	}
	
	for (unsigned int i = 0; i < ARR_SIZE; i++)
	{
		person_release(per[i]);
	}
	
	return 0;
}

