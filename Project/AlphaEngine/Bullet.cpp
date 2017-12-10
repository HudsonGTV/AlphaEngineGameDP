#include "Bullet.h"
#include "GraphicsEngine.h"

Bullet::Bullet(std::vector<Entity *> *entityList, std::vector<Bullet *> *entityBullets, char *texturePath, int frameCount, math::vec3 position) : Entity(entityList, /* IDs should be automatic: -1, */ texturePath, frameCount, COLLIDER_BOX, 10.0f, 10.0f, 10.0f, 10.0f) {

	m_entityBullets = entityBullets;
	m_name = "Bullet";

	entityList->push_back(this);

	SetWorldPosition(position);

}

void Bullet::Update() {

	Graphics::DrawMesh(this, &m_mesh, &m_texture, m_zOrder, m_frameCount);

	if(ENABLE_DEBUG_LINES) {
		Graphics::DrawMesh(this, &m_debugMesh, &m_debugTexture, 5.0f);
	}

	SetPosition(m_velocity);

	m_input->Update(this, false, 0.0f);

}
