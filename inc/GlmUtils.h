#ifndef GLMUTILS_H
#define GLMUTILS_H

#include <glm/glm.hpp>

glm::vec3 &operator/(glm::vec3 &lhs, float rhs)
{
	lhs.x /= rhs;
	lhs.y /= rhs;
	lhs.z /= rhs;
	return (lhs);
}


#endif //GLMUTILS_H
