#ifndef NORMAL_H
#define NORMAL_H


#include <GL/glew.h>
#include <glm/glm.hpp>

struct Normal : public glm::vec3
{
	Normal() : glm::vec3() { }
	Normal(float x, float y, float z) : glm::vec3(x, y, z) { }
};


#endif //NORMAL_H
