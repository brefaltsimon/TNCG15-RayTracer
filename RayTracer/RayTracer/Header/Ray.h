

#pragma once
#include "definitions.h"

class Ray {
public:
	Ray() = default;
	Ray(vec3 start, vec3 dir);
	//Ray(vec3 Start, vec3 End, colorDbl Color) : start{ Start }, end{ End }, color{ Color } { };

	void SetDirection(const vec3& dir) { direction = dir; };
	void setColor(const colorDbl& Raycolor) { color = Raycolor; };

	vec3  GetStart() const { return start; };
	vec3  GetDirection() const { return direction; };
	vec3  GetColor() const { return color; };
	Ray   Bounce(const vec3& position, const vec3& normal, const bool reflect, const float& breakIndex) const;
	

private:
	vec3 start;
	colorDbl color;
	direction direction;
	//binary tree???
	//reference till triangel som blivit intersected
};