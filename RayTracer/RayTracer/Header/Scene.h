#pragma once
#include "definitions.h"
#include "Triangle.h"

#include <vector>
#include <array>


class Scene {
public:

	Scene(); //doesnt need any arguments because the scene wont change so we will make it pre-defined aka hardcoded ish
	void CreateRoom();
	void AddObjects();

private:
	std::vector<Triangle> sceneTriangles;
	//std::vector<Triangle> sceneObjectTriangles;

};