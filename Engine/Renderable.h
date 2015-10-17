#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>

class Mesh;
class Shader;

class Renderable
{
public:
	Renderable();
	~Renderable();

	inline Mesh* GetMesh() const { return m_pMesh; }
	inline GLuint GetTexture() const { return m_Texture; }
	inline const glm::mat4& GetModelMatrix() const { return m_ModelMatrix; }

	void SetModelMatrix(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
	void SetTexture(GLuint texture);
	void SetMesh(Mesh* mesh);
	void ApplyModelMatrix();

private:
	Mesh* m_pMesh;
	GLuint m_Texture;
	glm::mat4 m_ModelMatrix;
};

