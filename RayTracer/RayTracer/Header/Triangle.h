#ifndef Triangle_HEADER
#define Triangle_HEADER

#include <array>

#include "definitions.h"
#include "Ray.h"

class Triangle {
public:

	Triangle() = delete;
	Triangle(vec3 v0, vec3 v1, vec3 v2, colorDbl clr);
	colorDbl getColor() const { return color; };

	vec3 getMid();

	bool RayIntersection(const Ray& arg, vec3& intersection);

private:
	std::array<vec3, 3> positions;
	direction normal;
	colorDbl color;
};

#endif