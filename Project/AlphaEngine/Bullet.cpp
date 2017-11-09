#include "Bullet.h"
#include "GraphicsEngine.h"

Bullet::Bullet(char *texturePath, int frameCount, math::vec3 position) : Entity(texturePath, frameCount) {
	SetWorldPosition(position);
}

Bullet::~Bullet() {
	
}

void Bullet::Update() {

	Graphics::DrawMesh(this, &m_mesh, &m_texture, m_frameCount);

	m_input->Update(this, false, 0.0f);

}

void Bullet::Destory(int index, std::vector<Bullet *> *entityBullets) {

	entityBullets->erase(entityBullets->begin() + index);
	delete this;

}
