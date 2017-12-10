#ifndef PLAYER_H
#define PLAYER_H

#include "Math.h"
#include "Input.h"
#include "Bullet.h"

class Player : public Entity {

private:
	AEGfxVertexList *m_meshDead;
	AEGfxTexture *m_textureDead;

	std::vector<Bullet *> m_entityBullets;

public:
	Player(std::vector<Entity *> *entityList, char *texturePath, int frameCount = 1, float width = 0, float height = 0);

	void Update() override;

};

#endif