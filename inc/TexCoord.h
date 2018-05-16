#ifndef TEXCOORD_H
#define TEXCOORD_H


#include <GL/glew.h>
#include <glm/glm.hpp>

struct TexCoord : public glm::vec2
{
	TexCoord() : glm::vec2() { }
	TexCoord(float x, float y) : glm::vec2(x, y) { }
};


#endif //TEXCOORD_H
