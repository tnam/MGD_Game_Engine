#include "Camera.h"

const int Camera::SPEED = 3.0f;
const glm::vec3 Camera::UP = glm::vec3(0.0f, 1.0f, 0.0f);

Camera::Camera(glm::vec3 position, GLfloat ratio, glm::vec3 up, GLfloat yaw, GLfloat pitch, GLfloat fov, GLfloat near, GLfloat far)
	: m_Position(position)
	, m_AspectRatio(ratio)
	, m_Up(up)
	, m_Yaw(yaw)
	, m_Pitch(pitch)
	, m_FOV(fov)
	, m_Near(near)
	, m_Far(far)
	, m_Forward(glm::vec3(0.0f, 0.0f, -1.0f))
	, m_bUpdated(true)
	, m_Frustum(*this)
{
	Update();
}

void Camera::Update()
{
	if (m_bUpdated)
	{
		glm::vec3 front;

		front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
		front.y = sin(glm::radians(m_Pitch));
		front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
		m_Forward = glm::normalize(front);

		m_Right = glm::normalize(glm::cross(m_Forward, UP));
		m_Up = glm::normalize(glm::cross(m_Right, m_Forward));

		m_ViewMatrix = glm::lookAt(m_Position, m_Position + m_Forward, m_Up);

		m_bUpdated = false;
	}
}

void Camera::MoveUp()
{
	// TODO

	Update();

	m_bUpdated = true;
}

void Camera::MoveDown()
{
	// TODO

	Update();

	m_bUpdated = true;
}

void Camera::MoveLeft()
{
	// TODO

	Update();

	m_bUpdated = true;
}

void Camera::MoveRight()
{
	// TODO

	Update();

	m_bUpdated = true;
}
