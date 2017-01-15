#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 255

struct _Person
{
	char *name;
	int age;
};
typedef struct _Person Person;

Person *CreatePerson(char *name, size_t age)
{
	Person *p = malloc(sizeof(Person));

	if (p)
	{
		p->name = malloc((name? strlen(name):0) + 1);
		if (p->name)
		{
			//Cant't copy NULL into a name
			strcpy(p->name, name? name : "");
			p->age = age;
		}
		else
		{
			//Handle Memory Error;
			//Case to treat a memory leak, because the Person has already been allocated
			free(*p);
			p = NULL;
		}
	}

	return p;
}

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

Person *people[10] = { 0 };

void AddPeople()
{
	people[0] = AddPerson();
	people[1] = AddPerson();
	people[2] = AddPerson();

}

void main(void)
{
	AddPeople();

	//Person *p2 = people[2];
	//Cannot free(*p2) because its a shared variable with the array of peoples.

	//One of the top problems is memory leak because people free some variable used somewhere else
	//or proggramers with fear of freeing variables believing that this could be used in another place.
	for (size_t i = 0; i < sizeof(people) ; i++)
	{
		FreePerson(people[i]);
	}

}

	
