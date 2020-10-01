#include "Header/Ray.h"


Ray::Ray(vec3 startPoint, vec3 dir)
{
	start = startPoint;
	direction = dir;
	color = vec3(0.0, 0.0, 0.0);
}

Ray Ray::Bounce(const vec3& position, const vec3& normal, const bool reflect, const float& breakIndex) const {
	
	vec3 newDirection(0.0f);

	if (reflect) {
		newDirection = glm::reflect(direction, normal);
	}
	else {
		newDirection = glm::refract(direction, normal, breakIndex);
	}

	Ray r(position, newDirection);
	
	return r;
}

