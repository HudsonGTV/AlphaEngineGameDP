#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include "Entity.h"
#include "Math.h"

class PhysicsEngine {

private:

public:
	void Init(Entity *entityID[ENTITY_COUNT]);
	void Update(double dt);

};

#endif