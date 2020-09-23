#pragma once

#include "definitions.h"
#include "Ray.h"
#include <vector>

class Pixel {
public:

	Pixel();

	vec3 getMidOfPixel(int y, int z);

	void addRay(Ray& ray);

private:
	colorDbl rayColor;
	std::vector<Ray> rayList;
};