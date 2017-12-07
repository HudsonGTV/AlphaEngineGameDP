#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Entity.h"

class Game {

public:
	void Init(std::vector<Entity *> *entityList);
	void Update(std::vector<Entity *> *entityList, double dt);

};

#endif