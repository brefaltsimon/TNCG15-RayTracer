#include "Header/Triangle.h"
#include "Header/definitions.h"
#include "Header/Pixel.h"
#include "Header/Scene.h"

#include <iostream>
#include <vector>
#include <array>

//Triangle::Triangle(vec3 v0, vec3 v1, vec3 v2, colorDbl clr, const Surface &surf)
Triangle::Triangle(vec3 v0, vec3 v1, vec3 v2, const Surface &surf)
{
	positions[0] = v0;
	positions[1] = v1;
	positions[2] = v2;
	surface = surf;
	//color = clr;
	direction v0v1 = v1 - v0;
	direction v1v2 = v1 - v2;
	normal = glm::normalize(glm::cross(v1v2, v0v1));
}

vec3 Triangle::getMid()
{

	return vec3((positions[0].x + positions[1].x + positions[2].x)/3, (positions[0].y + positions[1].y + positions[2].y)/3, (positions[0].z + positions[1].z + positions[2].z)/3);
}

bool Triangle::RayIntersection(const Ray& arg, vec3 &intersection)
{
	//med vinkeln på ray arg, räkna intersection
	//Variabler för Möller
	const float EPSILON = 0.00001f;
	float u{};
	float v{};
	vec3 Edge_1 = positions[1] - positions[0];
	vec3 Egde_2 = positions[2] - positions[0];
	vec3 T = arg.GetStart() - positions[0]; //punkt p triangeln rayToVertex
	vec3 Direction = glm::normalize(arg.GetDirection()); //riktning s detta blir en in variabel?

	vec3 Q = glm::cross(T, Edge_1);
	vec3 P = glm::cross(Direction, Egde_2);

	float t = glm::dot(Q, Egde_2) / glm::dot(P, Edge_1);

	float utest = glm::dot(P,T) / glm::dot(P, Edge_1);
	float vtest = glm::dot(Q, Direction) / glm::dot(P, Edge_1);

	if (utest >= EPSILON && vtest >= EPSILON && (utest + vtest <= 1)) // u > 0 , v > 0 och u + v <=1
	{

		if (t > EPSILON) {
			u = utest;
			v = vtest;
			intersection = (1.0f - u - v) * positions[0] + u * positions[1] + v * positions[2]; //Räknar ut interktionpunkten
			return true;
		}

	}
	return false;
	
	// t = intersektion punkten?  så T = (1 - u - v)v_0 + u*v_1 + v*v_2
}