#ifndef RENDERER_H
#define RENDERER_H

#include "Vertex.h"
#include "Shader.h"
#include "Material.h"
#include "Object.h"
#include "Mesh.h"
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include <unordered_map>

#define MESH_MAX_INDICES         1000000
#define MESH_MAX_BUFFER_BYTES    1000000

#define SHADER_INDEX_POSITION    0
#define SHADER_INDEX_UV          1
#define SHADER_INDEX_COLOR       2
#define SHADER_INDEX_NORMAL      3

class Object;

class Renderer
{
public:
	Renderer(Shader *shader);
	~Renderer();

	void submit(const Object *object);
	void flush(const glm::vec3 &eyePosition);

private:

	struct MeshInfo
	{
		unsigned int numIndices;
		unsigned int materialIndex;
	};

	Shader *m_shader;
	GLuint m_vao;
	GLuint m_vbo;
	GLuint m_ibo;
	unsigned int m_numGpuVertices;
	unsigned int m_numGpuIndices;
	std::vector<MeshInfo> m_meshInfo;
	std::vector<Material> m_materials;
	std::vector<glm::mat4> m_transformations;

};


#endif //RENDERER_H
