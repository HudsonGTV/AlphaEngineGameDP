#include <string>

#include "Player.h"
#include "GraphicsEngine.h"

Player::Player(char *texturePath, int frameCount, float width, float height) : Entity(texturePath, frameCount, COLLIDER_BOX, width, height) {

	m_texturePath = texturePath;
	m_frameCount = frameCount;

	Graphics::CreateMesh(this, &m_mesh, &m_texture, m_texturePath, m_frameCount);



	m_input = new InputManager(&m_entityBullets);

}

void Player::Update() {

	Graphics::DrawMesh(this, &m_mesh, &m_texture, m_frameCount);

	m_input->Update(this, true, 1.5f);

	// DEBUG STRING OUTPUT
	std::string tempPos = std::to_string(m_position.x) + ", " + std::to_string(m_position.y);
	// UPDATE BULLETS
	for(auto &bullet : m_entityBullets) {

		bullet->Update();

	}

	OutputDebugStringA("Player Position: ");
	OutputDebugStringA(tempPos.c_str());
	OutputDebugStringA("\n");

}
