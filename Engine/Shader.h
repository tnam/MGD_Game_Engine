#pragma once

#include <GL/glew.h>

class Shader
{
public:
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	~Shader();

	void Use();
	void Disable();

private:
	GLint Load();

private:
	GLuint m_ProgramID;
	const GLchar* m_VertexPath;
	const GLchar* m_FragmentPath;
};

