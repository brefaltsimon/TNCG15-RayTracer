#pragma once

#include "definitions.h"
#include "ColorDbl.h"

class Ray {
public:
	Ray() = delete;
	Ray(vec3 Start, vec3 End, ColorDbl Color) : start{ Start }, end{ End }, color{ Color } { };


private:
	vec3 start, end;
	// or direction?
	ColorDbl color;
};