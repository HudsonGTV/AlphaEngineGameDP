#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy : public IEntityAi {
private:

	double m_shootTimer = 1;

	std::vector<Bullet *> m_entityBullets;

	double m_bulletSpeed = 6.5;

public:
	Enemy(std::vector<Entity *> *entityID, char *texturePath, int frameCount = 1, ColliderType ctype = COLLIDER_NONE, float width = 0.0f, float height = 0.0f, float textureWidth = 60.0f, float textureHeight = 60.0f);

	virtual void Update();
	virtual void AiUpdate(std::vector<Entity *> *entityID);

};

#endif