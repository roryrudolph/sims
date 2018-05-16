#ifndef FACE_H
#define FACE_H

#include <GL/glew.h>
#include <glm/glm.hpp>

struct Face
{
	glm::uvec3 positionIndices;
	glm::uvec3 texcoordIndices;
	glm::uvec3 normalIndices;

	Face() { }
	Face(
		unsigned int px, unsigned int py, unsigned int pz,
		unsigned int tx, unsigned int ty, unsigned int tz,
		unsigned int nx, unsigned int ny, unsigned int nz)
		: positionIndices(px, py, pz),
		  texcoordIndices(tx, ty, tz),
		  normalIndices(nx, ny, nz)
	{ }
};

#endif //FACE_H
