#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H

#include "Entity.h"

namespace GameObjects {

	void removeEntityByID(std::vector<Entity *> *entityID, int id);

	int giveUniqueID(std::vector<Entity *> *entityID, int &id);

	Entity *getEntityByID(std::vector<Entity *> *entityID, int id);

}

#endif