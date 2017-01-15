#include <stdio.h>
#include <string.h>
#include "Person.h"

Person *CreatePerson(char *name, size_t age)
{
	Person *p = malloc(sizeof(Person));

	if (p)
	{
		p->name = malloc((name ? strlen(name) : 0) + 1);
		if (p->name)
		{
			//Cant't copy NULL into a name
			strcpy(p->name, name ? name : "");
			p->age = age;
		}
		else
		{
			//Handle Memory Error;
			//Case to treat a memory leak, because the Person has already been allocated
			free(p);
			p = NULL;
		}
	}

	return p;
}

#define BUFFER_SIZE 255

Person *AddPerson()
{
	char buffer[BUFFER_SIZE];
	size_t age;
	printf("Please enter a person's name: ");
	//Scanf will write the null terminator at the end of the string
	scanf("%s", buffer);

	printf("Please enter a person's age: ");
	scanf("%d", &age);

	return CreatePerson(buffer, age);
}

void FreePerson(Person *p)
{
	if (p)
	{
		//Need to free the variable in this order
		free(p->name);
		free(p);
	}
}