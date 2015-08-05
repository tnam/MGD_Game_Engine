#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), 
		   glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), 
		   GLfloat   yaw = -90.0f, 
		   GLfloat   pitch = 0.0f,
		   GLfloat   fov = 45.0f,
		   GLfloat   near = 0.1f,
		   GLfloat   far = 100.0f
		   );

	// Camera getters
	inline glm::mat4 GetViewMatrix() const { return m_ViewMatrix; }
	inline GLfloat GetNear() const { return m_Near; }
	inline GLfloat GetFar() const { return m_Far; }
	inline GLfloat GetFOV() const { return m_FOV; }

	// TODO: Camera movement
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

private:
	void Update(); // TODO: Replace Euler angles with quaternions 

private:
	glm::mat4 m_ViewMatrix;

	glm::vec3 m_Position;
	glm::vec3 m_Forward;
	glm::vec3 m_Up;
	glm::vec3 m_Right;

	GLfloat m_Yaw;
	GLfloat m_Pitch;
	//GLfloat m_Roll;

	GLfloat m_Near;
	GLfloat m_Far;
	GLfloat m_FOV;

private:
	static const glm::vec3 UP;
	static const int SPEED;
};