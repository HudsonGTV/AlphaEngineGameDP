#include "PhysicsEngine.h"
#include "Collider.h"

void PhysicsEngine::Init(std::vector<Entity *> *entityList) {
	m_entities = entityList;
}

void PhysicsEngine::Update(double dt) {
	for(int i = 0; i < static_cast<int>(m_entities->size()); ++i) {
		(*m_entities)[i]->GetCollider()->Update(m_entities, i, dt);
	}
}
