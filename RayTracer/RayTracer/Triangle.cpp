#include "Header/Triangle.h"
#include "Header/definitions.h"
#include "Header/Pixel.h"

#include <iostream>
#include <vector>
#include <array>


Triangle::Triangle(vec3 v0, vec3 v1, vec3 v2, colorDbl clr)
{
	positions[0] = v0;
	positions[1] = v1;
	positions[2] = v2;
	color = clr;
	direction v0v1 = v1 - v0;
	direction v1v2 = v1 - v2;
	normal = glm::cross(v1v2,v0v1);
}

vec3 Triangle::RayIntersection(Ray arg)
{

	return vec3();
}

int main() {
	
	return 0;
}
