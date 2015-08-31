#include <GL/glew.h>

#include "Renderer.h"
#include "Mesh.h"

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::AddRenderable(const Renderable* renderable)
{
	m_Renderables.push_back(renderable);
}

void Renderer::Draw(const Renderable* renderable)
{
	if (renderable)
	{
		Mesh* mesh = renderable->GetMesh();
		Shader* shader = renderable->GetShader();

		glBindVertexArray(mesh->GetVAO());
		glDrawElements(GL_TRIANGLES, mesh->GetNumIndices(), GL_UNSIGNED_SHORT, 0);
		glBindVertexArray(0);
	}
}
