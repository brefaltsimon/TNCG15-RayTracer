#pragma once

#include "definitions.h"
#include "Ray.h"
#include <vector>

class Pixel {
public:

	Pixel();

	vec3 getMidOfPixel(int y, int z);
	

private:
	colorDbl rayColor;
	std::vector<Ray> rayList;
};