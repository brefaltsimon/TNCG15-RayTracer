#include "Header/Ray.h"


Ray::Ray(vec3 startPoint, vec3 dir)
{
	start = startPoint;
	direction = dir;
	color = vec3(0.0, 0.0, 0.0);
}

