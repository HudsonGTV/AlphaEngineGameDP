#include "Entity.h"
#include "Collider.h"
#include "GraphicsEngine.h"

Entity::Entity(char *texturePath, int frameCount, ColliderType ctype, float width, float height) {

	m_texturePath = texturePath;
	m_frameCount = frameCount;

	Graphics::CreateMesh(this, &m_mesh, &m_texture, m_texturePath, m_frameCount);

	if (ctype == COLLIDER_BOX) {
		m_collider = new BoxCollider(width, height);
	} else if (ctype == COLLIDER_CIRCLE) {
		m_collider = new CircleCollider(width);
	} else {
		m_collider = nullptr;
	}

	m_input = new InputManager();
	m_ctype = ctype;
}

Entity::~Entity() {

	AEGfxMeshFree(m_mesh);
	AEGfxTextureUnload(m_texture);

	delete m_input;
	delete m_collider;

}

void Entity::SetWorldPosition(math::vec3 pos) {
	m_position = pos;
}

void Entity::SetPosition(math::vec3 pos) {
	m_position += pos;
}

void Entity::Update() {

	Graphics::DrawMesh(this, &m_mesh, &m_texture, m_frameCount);

	SetPosition(m_velocity.GetVelocity());

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
