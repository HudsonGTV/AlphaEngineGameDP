#include <string>

#include "Player.h"
#include "GraphicsEngine.h"

Player::Player(char *texturePath, int frameCount) : Entity(texturePath, frameCount) {

	m_texturePath = texturePath;
	m_frameCount = frameCount;

	Graphics::CreateMesh(this, &m_mesh, &m_texture, m_texturePath, m_frameCount);

	m_input = new InputManager();

}

void Player::Update() {

	Graphics::DrawMesh(this, &m_mesh, &m_texture, m_frameCount);

	m_input->Update(this, true, 1.5f);

	// DEBUG STRING OUTPUT
	std::string tempPos = std::to_string(m_position.x) + ", " + std::to_string(m_position.y);

	OutputDebugStringA("Player Position: ");
	OutputDebugStringA(tempPos.c_str());
	OutputDebugStringA("\n");

}
