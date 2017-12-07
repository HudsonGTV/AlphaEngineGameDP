#ifndef BULLET_H
#define BULLET_H

#include <vector>

#include "Math.h"
#include "Entity.h"

class Bullet : public Entity {

private:
	std::vector<Bullet *> *m_entityBullets;

public:
	Bullet(std::vector<Entity *> *entityList, std::vector<Bullet *> *entityBullets, char *texturePath, int frameCount, math::vec3 position);
	
	void Update() override;

};

#endif
