#ifndef BULLET_H
#define BULLET_H

#include <vector>
#include "Math.h"
#include "Entity.h"

class Bullet : public Entity {

private:

	int m_BulletID;


public:

	Bullet(char *texturePath, int frameCount, math::vec3 position);
	~Bullet();

	void Destory(int index, std::vector<Bullet *> *entityBullets);
	
	void Update();

};

#endif

