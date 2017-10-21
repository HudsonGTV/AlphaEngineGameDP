#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "Entity.h"
#include "Player.h"

namespace Objects {

	void Init(Entity *entityArray[ENTITY_COUNT]);
	void Update(double dt);

}

#endif