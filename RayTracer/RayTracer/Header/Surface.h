#pragma once
#include "definitions.h"




class Surface {
public:
	Surface(const colorDbl &surfaceColor = colorDbl(0.0, 0.0, 0.0), const int& reflModel = DIFFUSE);

	const colorDbl& GetColor() const { return color; };
	const int& GetRelf() const { return reflectionModel; };

private:
	colorDbl color;
	double reflectionCoefficient = 0.9f;
	int reflectionModel;

};

/*
type fun(type) {

	if (hitObject().transparent()) {
		2rays = true;
	}

	fun(type); //reflected
	if (2rays) {
		fun(type); //refracted
	}

}
*/