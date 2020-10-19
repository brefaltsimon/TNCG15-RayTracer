#pragma once

#include "definitions.h"
#include "Triangle.h"

#include <vector>

class Light {
public:
	Light() : radiance{ 20.0f } {
	//    Seen from below light:
	//    a-----b           ^ y
	//    | \   |           |
	//    |   \ |           ----> x
	//    c-----d
		vec3 a{4.5f, 0.5f, 4.99f};
		vec3 b{5.5f, 0.5f, 4.99f};
		vec3 c{4.5f, -0.5f, 4.99f};
		vec3 d{5.5f, -0.5f, 4.99f};

		const Surface white(colorDbl(1.0f), LIGHTSOURCE);
		triangles.push_back(Triangle(a, d, b, white));
		triangles.push_back(Triangle(a, c, d, white));

	};

	std::vector<Triangle> getTriangles() { return triangles; };
	const float getRadiance() { return radiance; };

private:
	std::vector<Triangle> triangles;
	float radiance; //wat to do
};