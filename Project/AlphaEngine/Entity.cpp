#include "Entity.h"
#include "Collider.h"
#include "GraphicsEngine.h"

Entity::Entity(char *texturePath, int frameCount) {

	m_texturePath = texturePath;
	m_frameCount = frameCount;

	Graphics::CreateMesh(this, &m_mesh, &m_texture, m_texturePath, m_frameCount);

	m_input = new InputManager();
	m_collider = new Collider();
}

Entity::~Entity() {

	AEGfxMeshFree(m_mesh);
	AEGfxTextureUnload(m_texture);

	delete m_input;

}

void Entity::SetWorldPosition(math::vec3 pos) {
	m_position = pos;
}

void Entity::SetPosition(math::vec3 pos) {
	m_position += pos;
}

void Entity::Update() {

	Graphics::DrawMesh(this, &m_mesh, &m_texture, m_frameCount);

	m_input->Update(this, false);

}

math::vec3 Entity::GetPosition() const {
	return m_position;
}

Collider *Entity::GetCollider() const {
	return m_collider;
}

ColliderType Entity::GetColliderType() const
{
	return m_ctype;
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
