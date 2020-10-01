#pragma once
#include <glm/glm.hpp>

typedef glm::vec3 vec3;
typedef glm::dvec3 dvec3;
typedef glm::dvec3 colorDbl; //color vector
typedef glm::vec3 direction; //direction vector

const int DIFFUSE = 0;
const int MIRROR = 1;
const int LIGHTSOURCE = 2;
const int TRANSPARENT = 3;