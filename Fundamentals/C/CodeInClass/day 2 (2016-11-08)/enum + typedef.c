#include <stdio.h>

#define STRING char *
typedef char * String;

void main(void)
{
	//STRING x = "Hello", y = "World"; /* Wrong!!! */
	String x = "Hello", y = "World";

	enum _Color
	{
		Red = 0xFF0000,
		Green = 0x00FF00,
		Blue = 0x0000FF,
		Yarok = Green,
		Black = 0
	};

	typedef enum _Color Color;
	typedef Color * PColor;

	Color background, color;
	PColor pc = &background;
	color = Red;
	color = Black;
	background = Yarok;

	if (color == Green)
	{
		printf("");
	}

	switch (color)
	{
	case Green:
		printf("Kermit\n");
		break;

	case Blue:
		printf("Cookie Monster\n");
		break;

	case Red:
		printf("Elmo\n");
		break;

	default:
		printf("Unknown color\n");
	}
}