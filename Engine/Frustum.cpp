#include "Frustum.h"

void Plane::BuildPlane(const glm::vec3& point, const glm::vec3& normal)
{
	m_Normal = glm::normalize(normal);
	m_Distance = glm::dot(m_Normal, point);
}

Frustum::Frustum() 
	: m_NearTopLeft(0), m_NearTopRight(0), m_NearBottomLeft(0), m_NearBottomRight(0)
	, m_FarTopLeft(0), m_FarTopRight(0), m_FarBottomLeft(0), m_FarBottomRight(0)
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

	// Define the 8 frustum's corners
	m_NearTopLeft = nearCenter - right * m_NearWidth + up * m_NearHeight;
	m_NearBottomLeft = nearCenter - right * m_NearWidth - up * m_NearHeight;
	m_NearTopRight = nearCenter + right * m_NearWidth + up * m_NearHeight;
	m_NearBottomRight = nearCenter + right * m_NearWidth - up * m_NearHeight;

	m_FarTopLeft = farCenter - right * m_FarWidth + up * m_FarHeight;
	m_FarBottomLeft = farCenter - right * m_FarWidth - up * m_FarHeight;
	m_FarTopRight = farCenter + right * m_FarWidth + up * m_FarHeight;
	m_FarBottomRight = farCenter + right * m_FarWidth - up * m_FarHeight;

	// Build Near plane
	m_Planes[static_cast<int>(EPlane::NEAR)].BuildPlane(nearCenter, forward);

	// Build Far plane
	m_Planes[static_cast<int>(EPlane::FAR)].BuildPlane(farCenter, -forward);

	glm::vec3 aux, normal;

	// Build Top plane
	aux = glm::normalize((nearCenter + up * m_NearHeight) - position);
	normal = glm::cross(aux, right);
	m_Planes[static_cast<int>(EPlane::TOP)].BuildPlane((nearCenter + up * m_NearHeight), normal);

	// Build Bottom plane
	aux = glm::normalize((nearCenter - up * m_NearHeight) - position);
	normal = glm::cross(right, aux);
	m_Planes[static_cast<int>(EPlane::BOTTOM)].BuildPlane((nearCenter - up * m_NearHeight), normal);

	// Build Left plane
	aux = glm::normalize((nearCenter - right * m_NearWidth) - position);
	normal = glm::cross(aux, up);
	m_Planes[static_cast<int>(EPlane::LEFT)].BuildPlane((nearCenter - right * m_NearWidth), normal);

	// Build Right plane
	aux = glm::normalize((nearCenter + right * m_NearWidth) - position);
	normal = glm::cross(aux, up);
	m_Planes[static_cast<int>(EPlane::RIGHT)].BuildPlane((nearCenter + right * m_NearWidth), normal);
}