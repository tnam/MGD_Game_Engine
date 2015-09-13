#pragma once

#include <GL/glew.h>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Texture.h"

struct Vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoords;
};

class Mesh
{
public:
	Mesh(const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices = {}, const std::vector<Texture>& textures = {});
	~Mesh();

	void Enable();
	void Disable();

	inline GLsizei GetNumIndices() const { return m_Indices.size(); }
	inline GLuint GetVAO() const { return m_VAO; }

	void Init();

private:
	GLuint m_VAO, m_VBO, m_EBO;

	std::vector<Vertex> m_Vertices;
	std::vector<GLuint> m_Indices;
	std::vector<Texture> m_Textures;
};