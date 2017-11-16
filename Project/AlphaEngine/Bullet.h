#ifndef BULLET_H
#define BULLET_H

#include <vector>

#include "Math.h"
#include "Entity.h"

class Bullet : public Entity {

private:

	std::vector<Entity *> *m_entityID;

public:

	Bullet(char *texturePath, std::vector<Entity *> *entityID, int frameCount, math::vec3 position);
	~Bullet();
	
	void Update();

};

#endif
