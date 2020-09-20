#include "Ray.h"


Ray::Ray(vec3 start, vec3 end)
{

	color = vec3(0.0, 0.0, 0.0);
}

vec3 Ray::getStart()
{
	return start;
}

vec3 Ray::getEnd()
{
	return end;
}