#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include "Entity.h"
#include "Math.h"

class PhysicsEngine {

private:
	std::vector<Entity *> *m_entities;

public:
	void Init(std::vector<Entity *> *entityID);
	void Update(double dt);

};

#endif