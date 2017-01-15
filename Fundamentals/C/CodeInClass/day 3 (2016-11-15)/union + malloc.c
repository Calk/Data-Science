#include <stdio.h>
#include <string.h>

union _ShapeDimensions
{
	int wh[2];
	double diameter;
	int length;
};

typedef union _ShapeDimensions ShapeDimensions;

enum ShapeType
{
	Circle,
	Square,
	Rectangle
};

struct _Shape
{
	enum ShapeType type;
	ShapeDimensions dimensions;
};

typedef struct _Shape Shape;

void PrintShape(Shape *s)
{
	if (s)
	{
		switch (s->type)
		{
		case Square:
			printf("This is a square, length is %d.\n", s->dimensions.length);
			break;

		default:
			printf("Unknown shape.\n");
		}
	}
}

int g;

void main(void)
{
	int numberOfShapes;
	scanf("%d", &numberOfShapes);
	Shape *shapes = (Shape *)malloc(numberOfShapes * sizeof(Shape));

	if (shapes != NULL)
	{
		if (numberOfShapes >= 1)
		{
			shapes[0].type = Rectangle;
			shapes[0].dimensions.wh[0] = 1000;
			shapes[0].dimensions.wh[1] = 6000;
		}

		if (numberOfShapes >= 2)
		{
			shapes[1].type = Circle;
			shapes[1].dimensions.diameter = 8.0;
		}

		if (numberOfShapes >= 3)
		{
			shapes[2].type = Square;
			shapes[2].dimensions.length = 10;
		}

		PrintShape(&(shapes[0]));

		free(shapes);
	}
}