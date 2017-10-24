#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"

class Bullet : public Entity {

private:

public:

	Bullet(char *texturePath, int frameCount);
	
	void Update();

};

#endif

