#pragma once

#include "definitions.h"
#include "Pixel.h"

#include <array>
#include <vector>

class Camera {
public:

	void Render();

private:
	vec3 eye1 = vec3(-2,0,0);
	//vec3 eye2 = vec3(-1,0,0);
	vec3 cameraPlaneVrtx[2][2];

	Pixel** viewPlane = new Pixel*[800];
};