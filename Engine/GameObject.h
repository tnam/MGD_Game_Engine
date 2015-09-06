#include <vector>
#include <glm/glm.hpp>

#include "Mesh.h"
#include "Texture.h"


class GemeObject {
public:
	glm::vec3 position;
	glm::vec3 orientation;
	Mesh* mesh;
	Texture* texture;
	PhysicComponent* physic;

};