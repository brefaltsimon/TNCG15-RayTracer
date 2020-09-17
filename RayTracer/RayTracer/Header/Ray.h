#pragma once
#include "definitions.h"

class Ray {
public:
	Ray() = delete;
	Ray(vec3 Start, vec3 End, colorDbl Color) : start{ Start }, end{ End }, color{ Color } { };


private:
	vec3 start, end;
	colorDbl color;
};