#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
	Shader(const char *vert_path, const char *frag_path);
	~Shader();

	void enable() const;
	void disable() const;

	GLuint get_id() const { return m_id; }
	GLint getAttribLocation(const char *name);

	void enableVertexAttribArray(const GLchar *name);
	void disableVertexAttribArray(const GLchar *name);

	void setUniform1f(const GLchar *name, const float val);
	void setUniform1i(const GLchar *name, const int val);
	void setUniform2f(const GLchar *name, const glm::vec2& val);
	void setUniform3f(const GLchar *name, const glm::vec3& val);
	void setUniform4f(const GLchar *name, const glm::vec4 &val);
	void setUniform4fv(const GLchar *name, GLsizei count, const GLfloat *val);
	void setUniformMat4(const GLchar *name, const glm::mat4& val);

private:
	GLuint load();
	GLint getUniformLocation(const GLchar *name);

	GLuint m_id;
	const char *m_vertpath;
	const char *m_fragpath;
};


#endif //SHADER_H
