#include "Bullet.h"
#include "GraphicsEngine.h"

Bullet::Bullet(std::vector<Entity *> *entityID, char *texturePath, int frameCount, math::vec3 position) : Entity(entityID, -1, texturePath, frameCount, COLLIDER_BOX, 10.0f, 10.0f, 10.0f, 10.0f) {

	m_name = "Bullet";

	GameObjects::giveUniqueID(entityID, m_id);

	entityID->push_back(this);

	SetWorldPosition(position);

}

Bullet::~Bullet() {
	//entityBullets->erase(entityBullets->begin() + index);
}

void Bullet::Update() {

	Graphics::DrawMesh(this, &m_mesh, &m_texture, m_frameCount);

	if(ENABLE_DEBUG_LINES) {
		Graphics::DrawMesh(this, &m_debugMesh, &m_debugTexture, 1, 5.0f);
	}

	SetPosition(m_velocity);

	m_input->Update(this, false, 0.0f);

}
