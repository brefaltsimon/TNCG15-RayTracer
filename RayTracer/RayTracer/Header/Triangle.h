#pragma once

#include <array>

#include "definitions.h"
//#include "Direction.h"
#include "definitions.h"
#include "ColorDbl.h"
#include "Ray.h"

class Triangle {
public:

	Triangle() = delete;
	Triangle(vec3 v0, vec3 v1, vec3 v2);
	
	//Triangle(Vertex vert0, Vertex vert1, Vertex vert2, ColorDbl clr, Direction normal);



	vec3 RayIntersection(Ray arg);

private:
	std::array<vec3, 3> positions;
	//Vertex v0, v1, v2;
	direction normal;
	ColorDbl color;
};