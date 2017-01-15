#include <stdio.h>
#include <string.h>
#include "Person.h"
//#include "../PreCourseCExercises/Person.h" using path notation

//The CPU can't make operations in memory, just copy from memory to register and then write to memory.
//Its is possible to see the intermediarty code generated before
//the linking proccess setting the preprocessor setting of copying to a file before linking

//Compile + Link = Build

//Modularity is good for large project where we don't want to recompile everything all the time, just the files that change.

//It is possible to compile without declaring all the promises
void NoTaxRaises();
void FullEmployement();

//Just for Preventing Cycle Reference
struct Parent;
struct Child
{
	struct Parent *p;
};
struct Parent
{
	struct Child *c;
};

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
	for (size_t i = 0; i < 10 ; i++)
	{
		FreePerson(people[i]);
	}
}

	
