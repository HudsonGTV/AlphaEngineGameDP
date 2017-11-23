#ifndef BULLET_H
#define BULLET_H

#include <vector>

#include "Math.h"
#include "Entity.h"

class Bullet : public Entity {

public:
	Bullet(std::vector<Entity *> *entityID, char *texturePath, int frameCount, math::vec3 position);
	~Bullet();
	
	void Update();

};

#endif
