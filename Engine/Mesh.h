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
	Mesh(const std::vector<Vertex>& vertices = {}, const std::vector<GLuint>& indices = {}, GLuint texture = 0);
	~Mesh();

	void Enable();
	void Disable();

	inline GLsizei GetNumVertices() const { return m_Vertices.size(); }
	inline GLsizei GetNumIndices() const { return m_Indices.size(); }
	inline GLuint GetVAO() const { return m_VAO; }
	inline const std::vector<Vertex>& GetVertices() const { return m_Vertices; }

	void SetVertices(const std::vector<Vertex>& vertices);

	void Init();

private:
	GLuint m_VAO, m_VBO, m_EBO;

	std::vector<Vertex> m_Vertices;
	std::vector<GLuint> m_Indices;
	GLuint m_Texture;
	//std::vector<Texture> m_Textures;
};