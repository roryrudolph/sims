#ifndef LAYER_H
#define LAYER_H


#include "Object.h"
#include "Renderer.h"
#include "Shader.h"
#include <glm/glm.hpp>

class Layer
{
public:
	Layer(Shader *shader);
	~Layer();

	void add(Object *object);
	void render(const glm::vec3 &eyePosition);

	const std::vector<Object *> &getObjects();
	Object *getObject(int index);

protected:
	Layer(Renderer *renderer, Shader *shader);

	Renderer *m_renderer;
	std::vector<Object *> m_objects;
	Shader *m_shader;
};


#endif //LAYER_H
