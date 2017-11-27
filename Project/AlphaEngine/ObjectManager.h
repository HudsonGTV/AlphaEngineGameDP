#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "Entity.h"

namespace ObjectManager {

	void updateObject(Entity *obj);

	void removeEntityByID(std::vector<Entity *> *entityID, int id, bool shouldDeallocate = true);
	void giveUniqueID(std::vector<Entity *> *entityID, int &id);

	Entity *getEntityByID(std::vector<Entity *> *entityID, int id);
	Entity *getEntityByName(std::vector<Entity *> *entityID, std::string name);

};

#endif