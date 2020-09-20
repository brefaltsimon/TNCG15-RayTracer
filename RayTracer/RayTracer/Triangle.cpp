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

bool Triangle::RayIntersection(Ray arg, float &v, float &u)
{
	//Variabler för Möller
	vec3 E_1 = positions[1] - positions[0];
	vec3 E_2 = positions[2] - positions[0];
	vec3 T = arg.getStart() - positions[0];
	vec3 D = arg.getEnd() - arg.getStart();
	vec3 Q = glm::cross(T, E_1);
	vec3 P = glm::cross(D, E_2);
	float t = glm::dot(Q,E_2 ) / glm::dot(P, E_1);

	float utest = glm::dot(P,T) / glm::dot(P, E_1);
	float vtest = glm::dot(Q,D) / glm::dot(P, E_1);

	if (utest >= 0 && vtest >= 0 && (utest + vtest <= 1))
	{
		u = utest;
		v = vtest;
		return true;
		//do the something;
	}
	return false;
	
	// t = intersektion punkten?  så T = (1 - u - v)v_0 + u*v_1 + v*v_2
}

int main() {
	
	return 0;
}
