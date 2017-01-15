
#ifndef _PERSON_H_
#define	_PERSON_H_

typedef unsigned int size_t;

struct _Person
{
	char *name;
	int age;
};
typedef struct _Person Person;

Person *CreatePerson(char *name, size_t age);
Person *AddPerson();
void FreePerson(Person *p);

#endif
