#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "Entity.h"

namespace ObjectManager {

	void updateObject(Entity *obj);

	void removeEntityByID(std::vector<Entity *> *entityID, int id);
	void giveUniqueID(std::vector<Entity *> *entityID, int &id);

	Entity *getEntityByID(std::vector<Entity *> *entityID, int id);

}

#endif