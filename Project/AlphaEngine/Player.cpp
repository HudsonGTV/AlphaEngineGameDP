#include <string>

#include "Player.h"

void Player::Update() {

	m_input->Update(this, true, 1.5f);

	// DEBUG STRING OUTPUT
	std::string tempPos = std::to_string(m_position.x) + ", " + std::to_string(m_position.y);

	OutputDebugStringA("Player Position: ");
	OutputDebugStringA(tempPos.c_str());
	OutputDebugStringA("\n");

}
