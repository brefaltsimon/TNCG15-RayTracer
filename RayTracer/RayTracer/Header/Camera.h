#pragma once

#include "definitions.h"
#include "Pixel.h"

#include <array>
#include <vector>

class Camera {
public:

	void Render();

private:
	vec3 eye1;
	//vec3 eye2; add laterrr
	//Pixel viewPlane[800][800];
	Pixel** viewPlane = new Pixel*[800];

};