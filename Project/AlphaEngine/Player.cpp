#include <string>

#include "Player.h"
#include "GraphicsEngine.h"

Player::Player(std::vector<Entity *> *entityID, char *texturePath, int frameCount, float width, float height) : Entity(entityID, /* IDs should be automatic: 0, */ texturePath, frameCount, COLLIDER_BOX, width, height) {
	m_input = new InputManager(entityID, &m_entityBullets);
	m_name = "Player";
}

void Player::Update() {

	if(!m_objectWasRemovedByID && !m_isDead) {

		if(m_health <= 0.0f && !m_objectWasRemovedByID) {
			m_isDead = true;
			m_objectWasRemovedByID = true;
			ObjectManager::removeEntityByID(m_entityID, m_id);
			return;
		}

		Graphics::DrawMesh(this, &m_mesh, &m_texture, m_frameCount);

		if(ENABLE_DEBUG_LINES) {
			Graphics::DrawMesh(this, &m_debugMesh, &m_debugTexture);
		}

		m_input->Update(this, true, 1.5f);

		SetPosition(m_velocity);

		// DEBUG STRING OUTPUT
		std::string tempPos = std::to_string(m_position.x) + ", " + std::to_string(m_position.y);

		// CHECK IF BULLETS SHOUDL BE DELETED
		for(unsigned int i = 0; i < m_entityBullets.size(); ++i) {

			if(m_entityBullets[i]->m_objectWasRemovedByID == true) {
				m_entityBullets.erase(m_entityBullets.begin() + i);
				break;
			}

			//m_entityBullets[i]->Update();

		}

		//OutputDebugStringA("Player Position: ");
		//OutputDebugStringA(tempPos.c_str());
		//OutputDebugStringA("\n");

	}

}
