#pragma once

#include <GL/glew.h>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Texture.h"

struct Vertex {
	glm::vec3 m_Position;
	glm::vec3 m_Normal;
	glm::vec2 m_TexCoords;
};

class Mesh
{
public:
	Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices = {}, std::vector<Texture> textures = {});
	~Mesh();

	inline GLsizei GetNumIndices() const { return m_NumIndices; }
	inline GLuint GetVAO() const { return m_VAO; }

private:
	void Init();

private:
	GLuint m_VAO, m_VBO, m_EBO;

	std::vector<Vertex> m_Vertices;
	std::vector<GLuint> m_Indices;
	std::vector<Texture> m_Textures;
	
	GLsizei m_NumVertices;
	GLsizei m_NumIndices;
	GLsizei m_numVertexPositionElements;

	GLsizei m_NumColorElements;
	GLsizei m_VertexStride;
};