#pragma once
#include "definitions.h"

class Direction {
public:
	Direction() = delete;
	Direction(vec3 dir) : direction{ dir } {};


private:
	vec3 direction;
};