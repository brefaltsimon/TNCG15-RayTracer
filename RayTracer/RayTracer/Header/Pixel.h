#pragma once

#include "definitions.h"
#include "Ray.h"
#include <vector>

class Pixel {
public:

	Pixel();

	vec3 getPointFromPixel(int y, int z, int k, int l, int raysperpixel);

	void addRay(Ray& ray);
	void setColor(const colorDbl& color) { pixelColor = color; };
	vec3  GetColor() const { return pixelColor; };

private:
	colorDbl pixelColor;
	std::vector<Ray> rayList;
	//Ray rayList;
};