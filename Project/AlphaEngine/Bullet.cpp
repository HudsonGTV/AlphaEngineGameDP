#include "Bullet.h"
#include "GraphicsEngine.h"

Bullet::Bullet(char *texturePath, int frameCount, std::vector<Bullet *> *entityBullets, math::vec3 position) : Entity(texturePath, frameCount) {

	m_texturePath = texturePath;
	m_frameCount = frameCount;

	Graphics::CreateMesh(this, &m_mesh, &m_texture, m_texturePath, m_frameCount);

	m_input = new InputManager();

	m_entityBullets = entityBullets;

	// GIVE THIS BULLET A UNIQUE ID

	int id = 0;

	for (int j = 1; id != 0; ++j) {
		for (int i = 0; i < m_entityBullets->size(); ++i) {
			if ((*m_entityBullets)[i]->m_BulletID != j) {
				id = j;
			}
		}
	}

	m_BulletID = id;

	//m_entityBullets->push_back(this);

	SetWorldPosition(position);

}

Bullet::~Bullet() {
	// TODO: SUBMITING BROKEN SHITTY LOOKING CODE IS NOT ALLOWED
	for(int i = 0; this->m_entityBullets != nullptr && i < m_entityBullets->size(); ++i) {
		if((*m_entityBullets)[i]->m_BulletID == this->m_BulletID) {
			m_entityBullets->erase(m_entityBullets->begin() + i);
			break;
		}
	}
}

void Bullet::Update() {

	Graphics::DrawMesh(this, &m_mesh, &m_texture, m_frameCount);

	m_input->Update(this, false, 0.0f);

}
