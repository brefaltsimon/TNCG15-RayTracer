#pragma once
#include "definitions.h"

class Ray {
public:
	Ray() = default;
	Ray(vec3 start, vec3 end);
	//Ray(vec3 Start, vec3 End, colorDbl Color) : start{ Start }, end{ End }, color{ Color } { };

	vec3 getStart();
	vec3 getEnd();

private:
	vec3 start, end;
	colorDbl color;
	//binary tree???
	//reference till triangel som blivit intersected
};