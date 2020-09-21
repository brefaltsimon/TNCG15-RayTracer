#pragma once

#include "definitions.h"
#include "Pixel.h"
#include "Scene.h"

#include <array>
#include <vector>

class Camera {
public:
	Camera();

	void ShootRay();
	void Render();
	void CreateImage(Scene theScene);


private:
	float pixeLength = 0.0025f;
	vec3 eye1 = vec3(-2,0,0);
	//vec3 eye2 = vec3(-1,0,0);
	vec3 cameraPlaneVrtx[2][2];

	Pixel** viewPlane = new Pixel*[800];
};