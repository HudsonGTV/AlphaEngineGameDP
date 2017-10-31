#ifndef PLAYER_H
#define PLAYER_H

#include "Math.h"
#include "Input.h"
#include "Bullet.h"

class Player : public Entity {
private:
	std::vector<Bullet *> *m_entityBullets;
public:
	Player(char *texturePath, int frameCount = 1, float width = 0, float height = 0);

	void Update();

};

#endif