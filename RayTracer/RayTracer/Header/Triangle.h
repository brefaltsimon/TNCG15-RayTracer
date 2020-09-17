#include <array>

#include "definitions.h"
//#include "ColorDbl.h"
#include "Ray.h"

class Triangle {
public:

	Triangle() = delete;
	Triangle(vec3 v0, vec3 v1, vec3 v2, colorDbl clr);


	vec3 RayIntersection(Ray arg);

private:
	std::array<vec3, 3> positions;
	direction normal;
	colorDbl color;
};