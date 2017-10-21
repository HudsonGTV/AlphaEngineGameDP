#include "Entity.h"

Entity::Entity() {



}

void Entity::SetWorldPosition(math::vec3 pos) {
	m_position += pos;
}

void Entity::SetPosition(math::vec3 pos) {
	m_position = pos;
}

math::vec3 Entity::GetPosition() const {
	return m_position;
}
