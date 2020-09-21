#include "Pixel.h"

Pixel::Pixel()
{
	rayColor = vec3(0.0, 0.0, 0.0);
	Ray rayFromEye(vec3(0,0,0), vec3(0,0,0));
	rayList.push_back(rayFromEye);
}

vec3 Pixel::getMidOfPixel(int y, int z)
{
	vec3 intersectionPointCameraPlane = vec3(0.0, -1.0 + y*0.0025 + 0.00125, -1.0 + z * 0.0025 + 0.00125); // tar frammitten av pixel f�r respektive y och z

	return intersectionPointCameraPlane;
}
