#include "Renderable.h"
#include <glm/gtc/matrix_transform.hpp>


Renderable::Renderable()
	: m_pMesh(nullptr), m_pShader(nullptr)
{
}


Renderable::~Renderable()
{
}

void Renderable::SetModelMatrix(glm::vec3 position, glm::vec3 rotation /*, glm::vec3 scale */)
{
	glm::mat4 model;
	model = glm::translate(model, position);

	model = glm::rotate(model, rotation.z, glm::vec3(1.0f, 0.3f, 0.5f));
	model = glm::rotate(model, rotation.x, glm::vec3(1.0f, 0.3f, 0.5f));
	model = glm::rotate(model, rotation.y, glm::vec3(1.0f, 0.3f, 0.5f));

	// TODO: Add scale and axes

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
