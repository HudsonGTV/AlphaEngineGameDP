#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy : public Entity {

private:
	


public:
	Enemy(char *texturePath, int frameCount = 1, ColliderType ctype = COLLIDER_NONE, float width = 0, float height = 0);

	void Update();

};

#endif