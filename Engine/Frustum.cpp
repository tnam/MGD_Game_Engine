#include "Frustum.h"

Frustum::Frustum()
{
}

void Frustum::Init(float fov, float ratio, float near, float far)
{
	m_NearDistance = near;
	m_FarDistance = far;

	float tang = glm::tan(glm::radians(fov * 0.5f));

	m_NearHeight = near * tang;
	m_NearWidth = m_NearHeight * ratio;
	m_FarHeight = far * tang;
	m_FarWidth = m_FarHeight * ratio;
}

void Frustum::BuildPlanes(const glm::vec3& position, const glm::vec3& forward, const glm::vec3& right, const glm::vec3& up)
{
	glm::vec3 nearCenter = position + (forward * m_NearDistance);
	glm::vec3 farCenter = position + (forward * m_FarDistance);

	m_NearTopLeft = nearCenter - right * m_NearWidth + up * m_NearHeight;
	m_NearBottomLeft = nearCenter - right * m_NearWidth - up * m_NearHeight;
	m_NearTopRight = nearCenter + right * m_NearWidth + up * m_NearHeight;
	m_NearBottomRight = nearCenter + right * m_NearWidth - up * m_NearHeight;

	m_FarTopLeft = farCenter - right * m_FarWidth + up * m_FarHeight;
	m_FarBottomLeft = farCenter - right * m_FarWidth - up * m_FarHeight;
	m_FarTopRight = farCenter + right * m_FarWidth + up * m_FarHeight;
	m_FarBottomRight = farCenter + right * m_FarWidth - up * m_FarHeight;
}