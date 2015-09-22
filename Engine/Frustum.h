#pragma once

#include <glm/glm.hpp>

class Plane
{
public:
	void Set3Points(const glm::vec3& a, const glm::vec3& b, const glm::vec3& c);
	void BuildPlane(const glm::vec3& point, const glm::vec3& normal);

	inline bool IsInFront(const glm::vec3& point) const
	{
		return glm::dot(m_Normal, point) >= m_D;
	}

private:
	glm::vec3 m_A, m_B, m_C;
	glm::vec3 m_Normal;
	float m_Distance;
};

class Frustum
{
public:
	Frustum();

private:
	void Init(float fov, float ratio, float near, float far);
	void BuildPlanes(const glm::vec3& position, const glm::vec3& forward, const glm::vec3& right, const glm::vec3& up);

private:
	enum class EPlane {TOP = 0, BOTTOM, LEFT, RIGHT, NEAR, FAR, NUM_PLANES};
	Plane m_Planes[static_cast<int>(EPlane::NUM_PLANES)];

	float m_NearWidth, m_NearHeight;
	float m_FarWidth, m_FarHeight;
	float m_NearDistance, m_FarDistance;

	// Frustum corners
	glm::vec3 m_NearTopLeft, m_NearBottomLeft, m_NearTopRight, m_NearBottomRight;
	glm::vec3 m_FarTopLeft, m_FarBottomLeft, m_FarTopRight, m_FarBottomRight;
};

