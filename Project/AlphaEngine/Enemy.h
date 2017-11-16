#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy : public Entity {

private:
	float m_health = 20.0f;

public:
	Enemy(char *texturePath, int frameCount = 1, ColliderType ctype = COLLIDER_NONE, float width = 0.0f, float height = 0.0f, float textureWidth = 60.0f, float textureHeight = 60.0f);

	void Update();
	void AiUpdate(std::vector<Entity *> *entityID);

	float GetHealth() const;

};

#endif