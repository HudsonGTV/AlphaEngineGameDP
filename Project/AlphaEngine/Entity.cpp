#include "Entity.h"
#include "Collider.h"
#include "GraphicsEngine.h"

Entity::Entity(char *texturePath, int frameCount, ColliderType ctype, float width, float height) {

	m_texturePath = texturePath;
	m_frameCount = frameCount;

	if (ctype == COLLIDER_BOX) {
		m_collider = new BoxCollider(width, height);
	} else if (ctype == COLLIDER_CIRCLE) {
		m_collider = new CircleCollider(width);
	} else {
		m_collider = nullptr;
	}

	Graphics::CreateMesh(this, &m_mesh, &m_texture, m_texturePath, m_frameCount);
	

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

void Entity::SetVelocity(math::vec3 vel) {
	m_velocity = vel;
}

void Entity::CreateDebugCircle() {

	AEGfxMeshStart();
	AEGfxSphere(m_position.x, m_position.y, m_position.z, m_collider->GetWidth(), 0xFFFF0000, 0xFFFF0000, 1);

	m_debugMesh = AEGfxMeshEnd();

}

void Entity::CreateDebugBox() {

	AEGfxMeshStart();
	AEGfxBox(m_position.x, m_position.y, m_position.z, m_collider->GetWidth(), static_cast<BoxCollider *>(m_collider)->GetHeight(), 1.0f, 0xFFFF0000, 0xFFFF0000);

	m_debugMesh = AEGfxMeshEnd();

}

void Entity::DrawDebugCircle() {

	// PLAYER
	AEGfxSetRenderMode(AE_GFX_MDM_LINES);
	// SET POISITION
	//AEGfxSetPosition(entity->GetPositionX(), entity->GetPositionY());
	AEGfxSetFullTransformWithZOrder(m_position.x, m_position.y, m_position.z, 0.0f, 1.0f, 1.0f);
	// DRAW MESH
	AEGfxSetTransparency(1.0f);
	AEGfxMeshDraw(m_debugMesh, AE_GFX_MDM_LINES);

}

void Entity::DrawDebugBox() {

	// PLAYER
	AEGfxSetRenderMode(AE_GFX_MDM_LINES);
	// SET POISITION
	//AEGfxSetPosition(entity->GetPositionX(), entity->GetPositionY());
	AEGfxSetFullTransformWithZOrder(m_position.x, m_position.y, m_position.z, 0.0f, 1.0f, 1.0f);
	// DRAW MESH
	AEGfxSetTransparency(1.0f);
	AEGfxMeshDraw(m_debugMesh, AE_GFX_MDM_LINES);

}

void Entity::Update() {

	Graphics::DrawMesh(this, &m_mesh, &m_texture, m_frameCount);

	SetPosition(m_velocity);

	m_input->Update(this, false, 0.0f);

}

math::vec3 Entity::GetPosition() const {
	return m_position;
}

math::vec3 Entity::GetVelocity() const
{
	return m_velocity;
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
