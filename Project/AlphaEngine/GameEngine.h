#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Entity.h"

class Game {

public:
	void Init(std::vector<Entity *> *entityID);
	void Update(std::vector<Entity *> *entityID, double dt);

};

#endif