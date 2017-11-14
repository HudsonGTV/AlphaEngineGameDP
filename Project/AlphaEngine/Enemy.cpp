#include "Enemy.h"
#include "GraphicsEngine.h"

Enemy::Enemy(char *texturePath, int frameCount, ColliderType ctype, float width, float height, float textureWidth, float textureHeight) : Entity(texturePath, frameCount, ctype, width, height, textureWidth, textureHeight) {

}

void Enemy::SetHealth(float health) {
	m_health = health;
}

void Enemy::Update() {

	if(m_health > 0.0f || m_isDead) {

		Graphics::DrawMesh(this, &m_mesh, &m_texture, m_frameCount);

		if(ENABLE_DEBUG_LINES) {
			Graphics::DrawMesh(this, &m_debugMesh, &m_debugTexture, 1, 5.0f);
		}

		SetPosition(m_velocity);

		m_input->Update(this, false, 0.0f);

	}

}

void Enemy::AiUpdate(Entity *entityID[ENTITY_COUNT]) {

	math::vec2 currPos(m_position.x, m_position.y);

	// GET PLAYER DIRECTION
	math::vec2 playerPos(entityID[ID_PLAYER]->GetPosition().x, entityID[ID_PLAYER]->GetPosition().y);
	math::vec2 vec = playerPos - currPos;

	double angle = atan2(vec.y, vec.x);

	math::vec3 vel = math::vec3(cos(angle) * 0.75, sin(angle)* 0.75, 0);

	SetVelocity(vel);

}

float Enemy::GetHealth() const {
	return m_health;
}
