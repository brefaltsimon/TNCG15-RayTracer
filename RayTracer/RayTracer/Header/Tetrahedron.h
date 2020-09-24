#pragma once
#include "definitions.h"
#include "Triangle.h"

#include <vector>

class Tetrahedron {
public:

	Tetrahedron(colorDbl color);
	Tetrahedron(vec3 position, float sideLength);


	const std::vector<Triangle>& getTriangles() const;

private:

	std::vector<Triangle> triangles;


};