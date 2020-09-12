#pragma once
#include "definitions.h"

class Vertex {
public:
	Vertex() {
		vertex = vec3(0, 0, 0);
		w = 1;
	}
	Vertex(vec3 vert, int h) : vertex{ vert }, w{ h } {}

private:
	vec3 vertex;
	int w;
};