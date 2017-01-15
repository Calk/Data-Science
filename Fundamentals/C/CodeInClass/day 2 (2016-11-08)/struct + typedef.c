#include <stdio.h>

struct _Rectangle
{
	size_t width;
	size_t height;
	char *color;
};

typedef struct _Rectangle Rectangle;

struct _Person
{
	char gender;
	char *name;
	unsigned char age;
	size_t height;
	struct _Person *father;
	struct _Person *mother;
	Rectangle myRect;
};

typedef struct _Person Person;

void PrintRectangle(Rectangle *r)
{
	printf("This is a %dx%d rectangle, colored %s.\n",
		r->width, r->height, r->color);
}

void main(void)
{
	Rectangle r1 = { 10, 20, "Red"};
	Rectangle r2;

	r2.width = 30;
	r2.height = r1.width;
	r2.color = "Mother of pearl";

	PrintRectangle(&r1);
	Person me;
	me.myRect.height = 100;
	//me.father->name = "Dad";

	size_t size = sizeof(Person);
}