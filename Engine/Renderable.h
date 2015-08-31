#pragma once

#include <glm/glm.hpp>

class Mesh;
class Shader;

class Renderable
{
public:
	Renderable();
	~Renderable();

	inline Mesh* GetMesh() const { return m_pMesh; }
	inline Shader* GetShader() const { return m_pShader; }

private:
	Mesh* m_pMesh;
	Shader* m_pShader;
	glm::mat4 m_ModelMatrix;
};

