#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy : public IEntityAi {

private:
	double m_shootTimer = 0.5;
	double m_bulletSpeed = 6.5;

	bool m_playerExists = true;

	std::vector<Bullet *> m_entityBullets;

public:
	Enemy(std::vector<Entity *> *entityList, char *texturePath, int frameCount = 1, ColliderType ctype = COLLIDER_NONE, float width = 0.0f, float height = 0.0f, float textureWidth = 60.0f, float textureHeight = 60.0f);

	void Update() override;
	virtual void AiUpdate(std::vector<Entity *> *entityList, double dt);

};

#endif