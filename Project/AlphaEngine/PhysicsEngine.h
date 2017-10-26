#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include "Entity.h"
#include "Math.h"

class PhysicsEngine {

private:
	Entity **m_entities;
	int m_entcount;

public:
	void Init(Entity **entityID, int count);
	void Update(double dt);

};

#endif