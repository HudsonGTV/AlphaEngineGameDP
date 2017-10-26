#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Math.h"
#include "Input.h"

class Player : public Entity {

public:
	Player::Player(char *texturePath, int frameCount = 1, float width = 0, float height = 0);

	void Update();

};

#endif