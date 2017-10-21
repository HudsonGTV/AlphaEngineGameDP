#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "Entity.h"
#include "Player.h"

#define ID_PLAYER 0
#define ID_BOSS 1

namespace Objects {

	void Init(Entity *entityArray[ENTITY_COUNT]);

}

#endif