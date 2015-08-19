#include "Mesh.h"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures)
{
	m_Vertices = vertices;
	m_Indices = indices;
	m_Textures = textures;

	Init();
}

Mesh::~Mesh()
{
	if (m_VAO != 0)
		glDeleteVertexArrays(1, &m_VAO);
	if (m_VBO != 0)
		glDeleteBuffers(1, &m_VBO);
	if (m_EBO != 0)
		glDeleteBuffers(1, &m_EBO);
}

void Mesh::Init()
{
	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);

	glBindVertexArray(m_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

	glBufferData(GL_ARRAY_BUFFER, m_Vertices.size() * sizeof(Vertex), &m_Vertices[0], GL_STATIC_DRAW);

	if (!m_Indices.empty())
	{
		glGenBuffers(1, &m_EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Indices.size() * sizeof(GLuint), &m_Indices[0], GL_STATIC_DRAW);
	}

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, m_Normal));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, m_TexCoords));

	glBindVertexArray(0);
}

void Mesh::Enable()
{
	glBindVertexArray(m_VAO);
}

void Mesh::Disable()
{
	glBindVertexArray(0);
}
