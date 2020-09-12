#pragma once

#include "definitions.h"

class ColorDbl {
public:
	ColorDbl() {
		color = dvec3(1.0, 1.0, 1.0);
	}
	ColorDbl(dvec3 clr) : color{ clr } {};

private:
	dvec3 color;
};