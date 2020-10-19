#include "Header/Pixel.h"

Pixel::Pixel()
{
	pixelColor = vec3(0.0, 0.0, 0.0);
	Ray rayFromEye(vec3(0,0,0), vec3(0,0,0));
	rayList.push_back(rayFromEye);
}

vec3 Pixel::getPointFromPixel(int y, int z, int k, int l, int raysperpixel)
{
	
	float displacement = (float)rand() / RAND_MAX;

	float tminy = 0.0f + 0.00125*l;
	float tmaxy = 0.00125f + 0.00125 * l;
	float tminz = 0.0f + 0.00125 * k;
	float tmaxz = 0.00125f + 0.00125 * k;

	float displacementY = displacement * (tmaxy - tminy) + tminy;
	float displacementZ = displacement * (tmaxz - tminz) + tminz;
	

	vec3 intersectionPointCameraPlane = vec3(0.0f, 1.0f - y* 0.0025f - displacementY, 1.0 - z * 0.0025f - displacementZ); // tar frammitten av pixel för respektive y och z

	return intersectionPointCameraPlane;
}

void Pixel::addRay(Ray& ray)
{
	pixelColor = ray.GetColor();
	*rayList.begin() = ray;
}
