#pragma once
#include "definitions.h"

//Class not used for now, is replaced by a typedef in definitions.h
class Direction {
public:
	Direction() = delete;
	Direction(vec3 dir) : direction{ dir } {};


private:
	vec3 direction;
};