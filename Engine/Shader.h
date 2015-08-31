#pragma once

#include <GL/glew.h>

#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	~Shader();

	void Bind();
	void Unbind();

	// TODO: Support other uniforms
	void SetUniform(const GLchar* name, const glm::mat4& matrix);

	GLuint GetProgramID() { return m_ProgramID; }

private:
	GLuint LoadProgram();

private:
	GLuint m_ProgramID;
	const GLchar* m_VertexPath;
	const GLchar* m_FragmentPath;
};

