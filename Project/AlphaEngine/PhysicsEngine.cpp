#include "PhysicsEngine.h"
#include "Collider.h"

void PhysicsEngine::Init(std::vector<Entity *> *entityID) {
	m_entities = entityID;
}

void PhysicsEngine::Update(double dt) {
	for(int i = 0; i < m_entities->size(); ++i) {
		(*m_entities)[i]->GetCollider()->Update(m_entities, i, dt);
	}
}
