#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

class Renderable;
class Mesh;
class Shader;

enum class SortType { NONE = 0, FRONT_TO_BACK, BACK_TO_FRONT, TEXTURE };

struct Batch {
	Batch(GLuint offset, GLuint numVertices, GLuint texture) 
		: m_Offset(offset)
		, m_NumVertices(numVertices)
		, m_Texture(texture) 
	{}

	GLuint m_Offset;
	GLuint m_NumVertices;
	GLuint m_Texture;
};

class Renderer
{
public:
	Renderer();
	~Renderer();

	void Init();
	void Begin(SortType sortType = SortType::TEXTURE);
	void End();

	void AddRenderable(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale, Mesh* mesh, GLuint texture);
	void Render();

private:
	void SortRenderables();
	void CreateBatch();
	void ApplyModelMatrix();

	// TODO: Replace with lambda
	static bool compareTextures(const Renderable* a, const Renderable*b);

private:
	GLuint m_VAO, m_VBO, m_EBO;
	SortType m_SortType;

	std::vector<const Renderable*> m_Renderables;
	std::vector<Batch> m_BatchQueue;
};

