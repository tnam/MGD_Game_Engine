#include "btBulletDynamicsCommon.h"
#include "Mesh.h"


class PhysicComponent {
	btRigidBody *rigidBody;

	PhysicComponent(Mesh* mesh);
	~PhysicComponent();

};