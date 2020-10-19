#pragma once
#include "definitions.h"
#include "Surface.h"

class Sphere {
public:
	Sphere() : r{ 1.0f }, center{ vec3(10.0f, 0.0f, 0.0f) }, theSurf{} {};
	Sphere(float radius, vec3 pos, Surface surf = Surface()) : r{ radius }, center{ pos }, theSurf{surf} {};

	vec3 getCenter() {return center; };
	vec3 getNormal(const vec3& point) { return glm::normalize(point - center); };
	float getRadius() {return r; };
	Surface getSurface() {return theSurf;};
	bool isHit();

private:

	float r;
	vec3 center;
	Surface theSurf;

};