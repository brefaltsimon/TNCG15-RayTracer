#pragma once
#include "Vertex.h"
#include "ColorDbl.h"

class Ray {
public:
	Ray() = delete;
	Ray(Vertex Start, Vertex End, ColorDbl Color) : start{ Start }, end{ End }, color{ Color } { };


private:
	Vertex start, end;
	// or direction?
	ColorDbl color;
};