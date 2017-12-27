#include "Enemy.h"
#include "GraphicsEngine.h"
#include "Bullet.h"

Enemy::Enemy(std::vector<Entity *> *entityList, char *texturePath, int frameCount, ColliderType ctype, float width, float height, float textureWidth, float textureHeight) : IEntityAi(entityList, /* IDs should be automatic: 1, */ texturePath, frameCount, ctype, width, height, textureWidth, textureHeight) {
	m_name = "Enemy";
}

void Enemy::Update() {

	if(!m_objectWasRemovedByID && !m_isDead) {
		
		if(m_health <= 0.0f && !m_objectWasRemovedByID) {
			m_isDead = true;
			m_objectWasRemovedByID = true;
			ObjectManager::removeEntityByID(m_entityList, m_id);
			return;
		}

		Graphics::DrawMesh(this, &m_mesh, &m_texture, m_zOrder, m_frameCount);

		if(Graphics::CheckDebugLineStatus()) {
			Graphics::DrawMesh(this, &m_debugMesh, &m_debugTexture, 5.0f);
		}

		SetPosition(m_velocity);

		m_input->Update(this, false, 0.0f);

		for(unsigned int i = 0; i < m_entityBullets.size(); ++i) {

			if(m_entityBullets[i]->m_objectWasRemovedByID == true) {
				m_entityBullets.erase(m_entityBullets.begin() + i);
				break;
			}

		}

	}

}

void Enemy::AiUpdate(std::vector<Entity *> *entityList, double dt) {

	if(!m_objectWasRemovedByID && !m_isDead) {

		m_shootTimer -= dt;

		math::vec2 currPos(m_position.x, m_position.y);

		Entity *player = nullptr;

		if(m_playerExists) {
			player = ObjectManager::getEntityByName(entityList, "Player");
		}

		// GET PLAYER DIRECTION
		if(player != nullptr) {

			if(player->GetGroup() != "GroupEntityDead") {

				math::vec2 playerPos(player->GetPosition().x, player->GetPosition().y);
				math::vec2 vec = playerPos - currPos;

				float angle = atan2(vec.y, vec.x);

				math::vec3 vel = math::vec3(cos(angle) * 0.75f, sin(angle) * 0.75f, 0.0f);

				SetVelocity(vel);

				// SHOOTING
				if(m_shootTimer <= 0.0) {

					m_shootTimer = 0.5;

					// FIRE BULLET
					m_entityBullets.push_back(new Bullet(m_entityList, &m_entityBullets, "entity/bullet/Ebullet.png", 1, GetPosition()));

					// SET BULLET NAME AND VELOCITY
					m_entityBullets.back()->SetName("EBullet");
					math::vec3 vel = math::vec3(cos(angle) * static_cast<float>(m_bulletSpeed), sin(angle) * static_cast<float>(m_bulletSpeed), 0);
					m_entityBullets.back()->SetVelocity(vel);

				}

			} else {
				m_playerExists = false;
				SetVelocity(math::vec3(0.0f, 0.0f, 0.0f));
			}

		} else {
			m_playerExists = false;
			SetVelocity(math::vec3(0.0f, 0.0f, 0.0f));
		}

	}

}
