#pragma once
#include "definitions.h"
#include "Triangle.h"
#include "Tetrahedron.h"
#include "Sphere.h"
#include "Ray.h"

#include <iostream>
#include <vector>
#include <array>


class Scene {
public:

	Scene(); //doesnt need any arguments because the scene wont change so we will make it pre-defined aka hardcoded ish
	void CreateRoom();
	void AddObjects();

	Triangle whichIsHit(const Ray &aRay, vec3& intersection);

	bool SphereHit(Ray& r, float& distToIntersection, vec3& intersection, Sphere& s);

private:
	std::vector<Triangle> sceneTriangles;
	std::vector<Sphere> sceneSpheres;
	//std::vector<Triangle> sceneObjectTriangles;

};