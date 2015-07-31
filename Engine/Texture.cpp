#include <string>

#include "Texture.h"
#include "Utility.h"

Texture::Texture(const std::string& filename)
	: m_Filename(filename)
{
	m_ID = Load();
}

Texture::~Texture()
{
	
}

GLuint Texture::Load()
{
	unsigned char* image = Utility::LoadTexture(m_Filename.c_str(), &m_Width, &m_Height);

	GLuint result;
	glGenTextures(1, &result);
	glBindTexture(GL_TEXTURE_2D, result);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

	Utility::FreeImageData(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	return result;
}

void Texture::Bind() const
{
	glBindTexture(GL_TEXTURE_2D, m_ID);
}

void Texture::Unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
