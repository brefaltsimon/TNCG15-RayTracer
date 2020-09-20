#include <array>

#include "definitions.h"
//#include "ColorDbl.h"
#include "Ray.h"

class Triangle {
public:

	Triangle() = delete;
	Triangle(vec3 v0, vec3 v1, vec3 v2, colorDbl clr);


	bool RayIntersection(Ray arg, float &u, float &v);

private:
	std::array<vec3, 3> positions;
	direction normal;
	colorDbl color;
};