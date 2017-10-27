#ifndef BULLET_H
#define BULLET_H

#include <vector>
#include "Math.h"
#include "Entity.h"

class Bullet : public Entity {

private:

	std::vector<Bullet *> *m_entityBullets;

	int m_BulletID;


public:

	Bullet(char *texturePath, int frameCount, std::vector<Bullet *> *entityBullets, math::vec3 position);
	~Bullet();
	
	void Update();

};

#endif

