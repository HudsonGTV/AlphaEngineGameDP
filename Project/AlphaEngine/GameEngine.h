#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Entity.h"

class Game {

public:
	void Init(Entity *entityID[ENTITY_COUNT]);
	void Update(Entity *entityID[ENTITY_COUNT], double dt);

};

#endif