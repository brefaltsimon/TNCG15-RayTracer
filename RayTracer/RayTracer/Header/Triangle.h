#pragma once

#include <array>

#include "definitions.h"
#include "Vertex.h"
#include "Direction.h"
#include "ColorDbl.h"
#include "Ray.h"

class Triangle {
public:

	Triangle() = delete;
	Triangle(Vertex vert0, Vertex vert1, Vertex vert2, ColorDbl clr, Direction normal);



	Vertex RayIntersection(Ray arg);

private:
	std::array<vec3, 3> positions;
	Vertex v0, v1, v2;
	Direction n;
	ColorDbl color;
};