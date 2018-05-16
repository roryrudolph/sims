#ifndef COLOR_H
#define COLOR_H


#include <GL/glew.h>
#include <glm/glm.hpp>

struct Color : public glm::vec4
{
	Color() : glm::vec4(1.0f, 1.0f, 1.0f, 1.0f) { }
	Color(float r, float g, float b) : glm::vec4(r, g, b, 1.0f) { }
	Color(float r, float g, float b, float a) : glm::vec4(r, g, b, a) { }

	glm::vec4 getGLM()
	{
		return glm::vec4(this->r, this->g, this->b, this->a);
	}
};


#endif //COLOR_H
