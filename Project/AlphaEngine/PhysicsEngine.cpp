#include "PhysicsEngine.h"
#include "Collider.h"

void PhysicsEngine::Init(Entity **entityID, int count) {
	m_entities = entityID;
	m_entcount = count;
}

void PhysicsEngine::Update(double dt) {
	for (int i = 0; i < m_entcount; ++i) {
		m_entities[i]->GetCollider()->Update(m_entities, m_entcount, i);
	}
}
