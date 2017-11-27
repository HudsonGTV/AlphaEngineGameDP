#include "Enemy.h"
#include "GraphicsEngine.h"

Enemy::Enemy(std::vector<Entity *> *entityID, char *texturePath, int frameCount, ColliderType ctype, float width, float height, float textureWidth, float textureHeight) : Entity(entityID, 1, texturePath, frameCount, ctype, width, height, textureWidth, textureHeight) {
	m_name = "Enemy";
}

void Enemy::Update() {

	if(!m_objectWasRemovedByID && !m_isDead) {

		if(m_health <= 0.0f) {
			m_isDead = true;
			m_objectWasRemovedByID = true;
			ObjectManager::removeEntityByID(m_entityID, m_id);
			return;
		}

		Graphics::DrawMesh(this, &m_mesh, &m_texture, m_frameCount);

		if(ENABLE_DEBUG_LINES) {
			Graphics::DrawMesh(this, &m_debugMesh, &m_debugTexture, 1, 5.0f);
		}

		SetPosition(m_velocity);

		m_input->Update(this, false, 0.0f);

	}

}

void Enemy::AiUpdate(std::vector<Entity *> *entityID) {

	if(!m_objectWasRemovedByID && !m_isDead) {

		math::vec2 currPos(m_position.x, m_position.y);

		Entity *player = ObjectManager::getEntityByName(entityID, "Player");

		// GET PLAYER DIRECTION
		if(player != nullptr) {

			math::vec2 playerPos(player->GetPosition().x, player->GetPosition().y);
			math::vec2 vec = playerPos - currPos;

			float angle = atan2(vec.y, vec.x);

			math::vec3 vel = math::vec3(cos(angle) * 0.75f, sin(angle) * 0.75f, 0.0f);

			SetVelocity(vel);

		}

	}

}
