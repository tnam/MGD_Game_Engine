#include <GL/glew.h>
#include <algorithm>

#include "Renderer.h"
#include "Mesh.h"
#include "Renderable.h"
#include "Shader.h"

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::Init()
{
	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);

	glBindVertexArray(m_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texCoords));

	glBindVertexArray(0);
}

void Renderer::Begin(SortType sortType)
{
	m_SortType = sortType;
	m_Renderables.clear();
	m_BatchQueue.clear();
}

void Renderer::End()
{
	SortRenderables();
	CreateBatch();
}

void Renderer::SortRenderables()
{
	switch (m_SortType)
	{
	case SortType::NONE:
		break;
	case SortType::FRONT_TO_BACK:
		// TODO
		break;
	case SortType::BACK_TO_FRONT:
		// TODO
		break;
	case SortType::TEXTURE:
		std::stable_sort(m_Renderables.begin(), m_Renderables.end(), compareTextures);
		break;
	default:
		break;
	}
}

void Renderer::CreateBatch()
{
	std::vector<Vertex> vertices;

	if (!m_Renderables.empty())
	{
		int offset = 0;
		Mesh* pMesh = m_Renderables[0]->GetMesh();
		m_BatchQueue.emplace_back(offset, pMesh->GetNumVertices(), m_Renderables[0]->GetTexture(), m_Renderables[0]->GetModelMatrix());
		vertices.insert(vertices.end(), pMesh->GetVertices().begin(), pMesh->GetVertices().end());
		offset += pMesh->GetNumVertices();

		for (int i = 1; i < m_Renderables.size(); ++i)
		{
			pMesh = m_Renderables[i]->GetMesh();
			if (m_Renderables[i]->GetTexture() != m_Renderables[i - 1]->GetTexture())
			{
				m_BatchQueue.emplace_back(offset, pMesh->GetNumVertices(), m_Renderables[i]->GetTexture(), m_Renderables[i]->GetModelMatrix());
			}
			else
			{
				m_BatchQueue.back().m_NumVertices += pMesh->GetNumVertices();
			}
			vertices.insert(vertices.end(), pMesh->GetVertices().begin(), pMesh->GetVertices().end());
			offset += pMesh->GetNumVertices();
		}

		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), nullptr, GL_DYNAMIC_DRAW);
		glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size() * sizeof(Vertex), vertices.data());

		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}

void Renderer::AddRenderable(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale, Mesh* mesh, GLuint texture)
{
	Renderable* renderable = new Renderable;

	renderable->SetMesh(mesh);
	renderable->SetModelMatrix(position, rotation);
	renderable->SetTexture(texture);

	m_Renderables.push_back(renderable);
}

void Renderer::Render(Shader& shader)
{
	glBindVertexArray(m_VAO);

	for (int i = 0; i < m_BatchQueue.size(); ++i)
	{
		glBindTexture(GL_TEXTURE_2D, m_BatchQueue[i].m_Texture);
		shader.SetUniform("model", m_BatchQueue[i].m_ModelMatrix);

		glDrawArrays(GL_TRIANGLES, m_BatchQueue[i].m_Offset, m_BatchQueue[i].m_NumVertices);
	}
}

bool Renderer::compareTextures(const Renderable* a, const Renderable* b)
{
	return (a->GetTexture() < b->GetTexture());
}