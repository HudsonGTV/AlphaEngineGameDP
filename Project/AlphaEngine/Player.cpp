#include <string>

#include "Player.h"
#include "GraphicsEngine.h"

Player::Player(std::vector<Entity *> *entityID, char *texturePath, int frameCount, float width, float height) : Entity(entityID, ID_PLAYER, texturePath, frameCount, COLLIDER_BOX, width, height) {
	m_input = new InputManager(entityID, &m_entityBullets);
	m_name = "Player";
}

void Player::Update() {

	//AESysPrintf("Player ID: %i", m_id);

	Graphics::DrawMesh(this, &m_mesh, &m_texture, m_frameCount);

	if(ENABLE_DEBUG_LINES) {
		Graphics::DrawMesh(this, &m_debugMesh, &m_debugTexture);
	}

	m_input->Update(this, true, 1.5f);

	SetPosition(m_velocity);

	// DEBUG STRING OUTPUT
	std::string tempPos = std::to_string(m_position.x) + ", " + std::to_string(m_position.y);

	// UPDATE BULLETS
	for(int i = 0; i < m_entityBullets.size(); ++i) {

		if(m_entityBullets[i]->m_objectWasRemovedByID == true) {
			m_entityBullets.erase(m_entityBullets.begin() + i);
			break;
		}

		m_entityBullets[i]->Update();

	}

	//OutputDebugStringA("Player Position: ");
	//OutputDebugStringA(tempPos.c_str());
	//OutputDebugStringA("\n");

}
