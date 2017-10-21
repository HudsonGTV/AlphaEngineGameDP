#include <string>

#include "Player.h"

void Player::Update() {

	m_input->Update(this, true);

	std::string tempPos = std::to_string(m_position.x) + ", " + std::to_string(m_position.y);

	OutputDebugStringA("Player Position: ");
	OutputDebugStringA(tempPos.c_str());
	OutputDebugStringA("\n");

}
