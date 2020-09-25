#pragma once
#include "definitions.h"

const int DIFFUSE = 0;
const int MIRROR = 1;
const int LIGHTSOURCE = 2;
const int TRANSPARENT = 3;


class Surface {
public:
	Surface(const colorDbl &surfaceColor = colorDbl(0.0, 0.0, 0.0), const int& reflModel = DIFFUSE);

	const colorDbl& GetColor() const;

private:
	colorDbl color;
	double reflectionCoefficient = 0.9f;
	int reflectionModel;

};