#include "Bullet.h"
#include "GraphicsEngine.h"

Bullet::Bullet(char *texturePath, std::vector<Entity *> *entityID, int frameCount, math::vec3 position) : Entity(-1, texturePath, frameCount, COLLIDER_BOX, 10.0f, 10.0f, 10.0f, 10.0f) {

	for(int i = 0; i < entityID->size() + 1; ++i) {

		for(int j = 0; j < entityID->size(); ++j) {
			if((*entityID)[j]->m_id != i) {
				m_id = i;
			} else {
				m_id = -1;
				break;
			}
		}

		if(m_id != -1) {
			break;
		}

	}

	if(m_id == -1) {
		m_id = entityID->size() + 1;
	}

	entityID->push_back(this);

	SetWorldPosition(position);

}

Bullet::~Bullet() {
	
}

void Bullet::Update() {

	Graphics::DrawMesh(this, &m_mesh, &m_texture, m_frameCount);

	if(ENABLE_DEBUG_LINES) {
		Graphics::DrawMesh(this, &m_debugMesh, &m_debugTexture, 1, 5.0f);
	}

	SetPosition(m_velocity);

	m_input->Update(this, false, 0.0f);

}

void Bullet::Destory(int index, std::vector<Bullet *> *entityBullets) {

	entityBullets->erase(entityBullets->begin() + index);
	delete this;

}
