#include "perimeter.h"

float r_perimeter(rectangle obj)
{
	float perimeter = obj.a + obj.b + obj.c + obj.d;
	return perimeter;
}

float t_perimeter(triangle obj)
{
	float perimeter = obj.a + obj.b + obj.c;
	return perimeter;
}
