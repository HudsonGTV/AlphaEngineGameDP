#include "Enemy.h"
#include "GraphicsEngine.h"

Enemy::Enemy(char *texturePath, int frameCount, ColliderType ctype, float width, float height, float textureWidth, float textureHeight) : Entity(texturePath, frameCount, ctype, width, height, textureWidth, textureHeight) {

}

void Enemy::SetHealth(float health) {
	m_health = health;
}

void Enemy::Update() {

	if(m_health <= 0.0f) {
		return;
	}

	Graphics::DrawMesh(this, &m_mesh, &m_texture, m_frameCount);

	if (ENABLE_DEBUG_LINES) {
		Graphics::DrawMesh(this, &m_debugMesh, &m_debugTexture, 1, 5.0f);
	}

	SetPosition(m_velocity);

	m_input->Update(this, false, 0.0f);

}

float Enemy::GetHealth() const {
	return m_health;
}
