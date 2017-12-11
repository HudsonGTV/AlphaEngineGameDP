#include <string>

#include "Player.h"
#include "GraphicsEngine.h"

Player::Player(std::vector<Entity *> *entityList, char *texturePath, int frameCount, float width, float height) : Entity(entityList, /* IDs should be automatic: 0, */ texturePath, frameCount, COLLIDER_BOX, width, height) {
	
	m_input = new InputManager(entityList, &m_entityBullets);
	m_name = "Player";

	Graphics::CreateMesh(&m_meshDead, &m_textureDead, "entity/player/playerDead.png", 2);

}

void Player::Update() {

	// CAMERA POSITION
	s32 mX = 0;
	s32 mY = 0;
	float nmX = 0.0f;
	float nmY = 0.0f;
	AEInputGetCursorPosition(&mX, &mY);
	//AEGfxConvertScreenCoordinatesToWorld(mX, mY, &nmX, &nmY);
	float cX = (AEGfxGetWinMaxX() - AEGfxGetWinMinX()) / 2;
	float cY = (AEGfxGetWinMaxY() - AEGfxGetWinMinY()) / 2;
	nmX = -mX - cX - AEGfxGetWinMinX() + AEGfxGetWinMaxX();
	nmY = -mY - cY - AEGfxGetWinMinY() + AEGfxGetWinMaxY();

	AEGfxSetCamPosition(GetPositionX() - nmX / 14, GetPositionY() + nmY / 14);

	if(!m_objectWasRemovedByID && !m_isDead) {

		if(m_health <= 0.0f && !m_objectWasRemovedByID) {
			if(!m_isInvincible) {
				m_isDead = true;
				//m_objectWasRemovedByID = true;
				SetGroup("GroupEntityDead");
				m_ctype = COLLIDER_NONE;
				//ObjectManager::removeEntityByID(m_entityList, m_id);
				return;
			}
		}

		Graphics::DrawMesh(this, &m_mesh, &m_texture, m_zOrder, m_frameCount);

		if(ENABLE_DEBUG_LINES) {
			Graphics::DrawMesh(this, &m_debugMesh, &m_debugTexture, 5.0f);
		}

		m_input->Update(this, true, 2.0f);

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

	} else {
		Graphics::DrawMesh(this, &m_meshDead, &m_textureDead, m_zOrder, 2);
	}

}
