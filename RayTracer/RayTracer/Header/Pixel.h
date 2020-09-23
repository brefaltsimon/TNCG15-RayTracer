#pragma once

#include "definitions.h"
#include "Ray.h"
#include <vector>

class Pixel {
public:

	Pixel();

	vec3 getMidOfPixel(int y, int z);

	void addRay(Ray& ray);
	vec3  GetColor() const { return pixelColor; };

private:
	colorDbl pixelColor;
	std::vector<Ray> rayList;
	//Ray rayList;
};