#include <stdio.h>

#define STRING char *
typedef char * String;

enum _Color
{
	Red = 0xFF0000,
	Green = 0xFBA0AA,
	Blue = 0xCCA098,
	Black = 0,
	Yarok = 0xCCA6098
};
typedef enum _Color Color;
typedef Color *PColor; //Creating an Alias

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
	struct Person *father;
	struct Person *mother;
	Rectangle myRect;
};
typedef struct _Person Person;

void PrintRectangle(Rectangle *r)
{
	printf("This is a %dx%d rectangle, colored %s\n", r->height, r->width, r->color);
}

void main(void)
{
	Rectangle r1 = { 10,10, "Red" };
	Rectangle r2 = { 10,10, "Blue" };

	PrintRectangle(&r1);
	PrintRectangle(&r2);

	r1.width = 30;
	r2.height = r1.width;
	r2.color = "Blue";

	Person me;
	me.myRect.height = 100;
	//me.father->name = "Dad";

	printf("%i", sizeof(Person));

	//STRING c = "Hello", y = "World"; not a really good way to define but it works
	String c = "Hello", y = "World";

	enum Color color, backgroud;
	PColor pc = &backgroud;

	color = Red;
	color = Blue;
	color = Black;

	backgroud = Yarok;

	if (color == Green)
	{
		printf("The color is Green");
	}

	switch (color)
	{
	case Green:
		printf("Green");
		break;

	case Red:
		printf("Red");
		break;

	case Blue:
		printf("Blue");
		break;

	case Yarok:
		printf("Yarok");
		break;

	default:
		printf("Just print White");
	}

}