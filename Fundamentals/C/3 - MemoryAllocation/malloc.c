#include <stdio.h>
#include <string.h>

//Unions are a lmited portion of memory for all the properties of the 'struct'
//Changing one property can change the others. Its called Recycling.
//The size of a shape is the size of the biggest property, in this case would be 8 bytes
//Unions are not typeSafe, very dangerous to use.
union _ShapeDimensions
{
	int wh[2];
	double diameter;
	int lengh;

};
typedef union _ShapeDimensions ShapeDimensions;

enum ShapeType
{
	Circle, 
	Rectangle, 
	Square
};

struct _Shape
{

	enum ShapeType type;
	ShapeDimensions dimensions;
};
typedef struct _Shape Shape;

void PrintShapes(Shape *s);

void main(void)
{

	//Structure of dynamic allocation of memory;
	int numberOfShapes;
	scanf("%d", &numberOfShapes);

	Shape *shapes = (Shape *)malloc(numberOfShapes * sizeof(Shape));

	//Guaratees that there is enough heap space in order for the program to run.
	if (shapes)
	{
		//It's possible to face shapes2 as an array;
		//Malloc uses a Memory Manager injected in every project by VS.
		if (numberOfShapes >= 1)
		{
			shapes[0].type = Rectangle;
			shapes[0].dimensions.wh[0] = 1000;
			shapes[0].dimensions.wh[1] = 6000;
			PrintShapes(&shapes[0]);
		}

		if (numberOfShapes >= 2)
		{
			shapes[1].type = Circle;
			shapes[1].dimensions.diameter = 8.0;
			PrintShapes(&shapes[1]);
		}

		if (numberOfShapes >= 3)
		{
			shapes[2].type = Square;
			shapes[2].dimensions.lengh = 500;
			PrintShapes(&shapes[2]);
		}

		free(shapes);
	}
}

void PrintShapes(Shape *s) 
{
	//If *s is not NULL
	if (s)
	{
		switch (s->type)
		{
			case Rectangle:
				printf("rectangle of dimension1 %i and dimension2 %i\n", s->dimensions.wh[0], s->dimensions.wh[1]);
				break;

			case Circle:
				printf("circle of dimension %f\n", s->dimensions.diameter);
				break;

			case Square:
				printf("square of dimension %i\n", s->dimensions.lengh); 
				break;

			default:
				printf("Unknown Shape\n");
				break;
		}
	}
}

