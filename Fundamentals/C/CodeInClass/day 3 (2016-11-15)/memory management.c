#include <stdio.h>
#include <string.h>

struct _Person
{
	char *name;
	size_t age;
};

typedef struct _Person Person;

Person *CreatePerson(char *name, size_t age)
{
	Person *p = malloc(sizeof(Person));

	if (p)
	{
		p->name = malloc((name ? strlen(name) : 0) + 1);
		if (p->name)
		{
			strcpy(p->name, name ? name : "");
			p->age = age;
		}
		else
		{
			/* handle out of memory error. */
			free(p);
			p = NULL;
		}
	}

	return p;
}

void FreePerson(Person *p)
{
	if (p)
	{
		free(p->name);
		free(p);
	}
}
#define BUF_SIZE 100

Person *AddPerson()
{
	char buffer[BUF_SIZE];
	size_t age;

	printf("Please enter a person's name: ");
	scanf_s("%s", buffer, BUF_SIZE);

	printf("Please enter %s's age: ", buffer);
	scanf("%d", &age);

	return CreatePerson(buffer, age);
}

Person *people[10] = { 0 };

void AddPeople()
{
	people[0] = AddPerson();
	people[1] = AddPerson();
	people[3] = AddPerson();
}

void main(void)
{
	AddPeople();

	Person *p2 = people[2];

	/* Deallocate whole DB - problematic */
	for (size_t index = 0; index < 10; ++index)
	{
		FreePerson(people[index]);
	}

	/* Deallocate single object - problematic */
	free(p2);
}