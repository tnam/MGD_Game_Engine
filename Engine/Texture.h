#pragma once

#include <GL\glew.h>

class Texture
{
public:
	Texture(const std::string& filename);
	~Texture();

	inline GLuint GetID() { return m_ID; }

	void Bind() const;
	void Unbind() const;

private:
	GLuint Load();

private:
	GLuint m_ID;
	std::string m_Filename;
	int m_Width, m_Height;
};

