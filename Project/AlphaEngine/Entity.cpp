#include "Entity.h"

Entity::Entity() {

	m_input = new InputManager();

}

void Entity::SetWorldPosition(math::vec3 pos) {
	m_position = pos;
}

void Entity::SetPosition(math::vec3 pos) {
	m_position += pos;
}

void Entity::Update() {

	m_input->Update(this, false);

}

math::vec3 Entity::GetPosition() const {
	return m_position;
}

float Entity::GetPositionX() const {
	return m_position.x;
}

float Entity::GetPositionY() const {
	return m_position.y;
}

float Entity::GetPositionZ() const {
	return m_position.z;
}
