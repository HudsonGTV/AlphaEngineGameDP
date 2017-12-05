#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "Entity.h"

class IEntityAi;

namespace ObjectManager {

	void updateObject(Entity *obj);
	void updateObjects(std::vector<Entity *> *entityID);
	void updateObjectAi(std::vector<Entity *> *entityID, IEntityAi *obj, double dt);

	void removeEntityByID(std::vector<Entity *> *entityID, int id, bool shouldDeallocate = true);
	// You should restructure the function to:
	int giveUniqueID();
	// With an additional helper function in case you want it
	int peekNextID();
	//void giveUniqueID(std::vector<Entity *> *entityID, int &id);

	Entity *getEntityByID(std::vector<Entity *> *entityID, int id, bool suppressWarnings = false);
	Entity *getEntityByName(std::vector<Entity *> *entityID, std::string name, bool suppressWarnings = false);

};

#endif