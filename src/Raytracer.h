#ifndef RAYTRACER_H
#define RAYTRACER_H


#include "Sphere.h"
#include "Vector3.h"
#include "Object.h"
#include <vector>

class Raytracer
{
public:
	Raytracer(unsigned int width, unsigned int height, float fov, unsigned int numThreads);
	~Raytracer();

	void render(
		glm::vec3 camPos,
		const std::vector<Object *> &objects
	);


private:
	unsigned int m_width;
	unsigned int m_height;
	unsigned int m_numThreads;
	float m_fov;
	float m_aspectRatio;
	float m_invertedWidth;
	float m_invertedHeight;
	float m_angle;
	Vector3f *m_image;

};


#endif //RAYTRACER_H
