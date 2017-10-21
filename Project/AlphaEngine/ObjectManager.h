#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#define ID_PLAYER 0
#define ID_BOSS 1

#include "Entity.h"
#include "Player.h"

namespace Objects {

	void Init(Entity entityArray[ENTITY_COUNT]);

}

#endif