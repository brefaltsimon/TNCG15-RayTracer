#pragma once

#include "definitions.h"
#include "Pixel.h"
#include "Scene.h"

#include <array>
#include <vector>
#include <iostream>

class Camera {
public:
	Camera();

	colorDbl ShootRay(Ray& ray,  Scene& Scene);
	void Render(Scene& scene);
	void CreateImage(Scene& theScene);
	void ShootShadowRay(Ray& ray);
	bool InShade(vec3& rayEnd, Scene& scene);

private:
	float pixeLength = 0.0025f;
	vec3 eye1 = vec3(-1,0,0);
	//vec3 eye2 = vec3(-1,0,0);
	vec3 cameraPlaneVrtx[2][2];

	Pixel** viewPlane = new Pixel*[800]; //
	//std::array<std::array<Pixel, 800>, 800> viewPlane; fyller stack
};