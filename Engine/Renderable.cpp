#include "Renderable.h"
#include <glm/gtc/matrix_transform.hpp>
#include "Mesh.h"


Renderable::Renderable()
	: m_pMesh(nullptr)
{
}


Renderable::~Renderable()
{
}

void Renderable::SetModelMatrix(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
{
	glm::mat4 model;
	model = glm::translate(model, position);

	model = glm::rotate(model, rotation.z, glm::vec3(1.0f, 0.3f, 0.5f));
	model = glm::rotate(model, rotation.x, glm::vec3(1.0f, 0.3f, 0.5f));
	model = glm::rotate(model, rotation.y, glm::vec3(1.0f, 0.3f, 0.5f));

	model = glm::scale(model, scale);

	// TODO: Replace temp axes

	m_ModelMatrix = model;
}

void Renderable::SetTexture(GLuint texture)
{
	m_Texture = texture;
}

void Renderable::SetMesh(Mesh* mesh)
{
	m_pMesh = mesh;
}

void Renderable::ApplyModelMatrix()
{
	std::vector<Vertex> vertices = m_pMesh->GetVertices();

	for (int i = 0; i < vertices.size(); ++i)
	{
		glm::vec4 vertex = m_ModelMatrix * glm::vec4(vertices[i].position, 1.0f);
		vertices[i].position = glm::vec3(vertex.x, vertex.y, vertex.z);
	}

	m_pMesh->SetVertices(vertices);
}