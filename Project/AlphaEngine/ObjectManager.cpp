#include "ObjectManager.h"
#include "consoleio.h"

void ObjectManager::updateObject(Entity *obj) {

	if(obj != nullptr && !obj->m_objectWasRemovedByID) {
		obj->Update();
	} else {
		static bool problem = false;
		if(!problem)
			Console::out::println("Could not update object. Object was nullptr.", "Warning");
		problem = true;
	}

}

void ObjectManager::updateObjects(std::vector<Entity *> *entityList) {

	for(Entity *entity : *entityList) {
		if(entity) {
			ObjectManager::updateObject(entity);
		}
	}

}

void ObjectManager::updateObjectAi(std::vector<Entity *> *entityList, IEntityAi *obj, double dt) {

	if(obj != nullptr && !obj->m_objectWasRemovedByID) {
		obj->AiUpdate(entityList, dt);
	} else {
		static bool problem = false;
		if (!problem)
			Console::out::println("Could not update object AI. Object was nullptr.", "Warning");
		problem = true;
	}

}

void ObjectManager::removeEntityByID(std::vector<Entity *> *entityList, int id, bool shouldDeallocate) {

	if(entityList == nullptr) {
		Console::out::println("Could not remove entity with ID " + Console::value(std::to_string(id)) + ". It does not exist in the specified vector.", "Warning");
		return;
	}

	for(int i = 0; i < static_cast<int>(entityList->size()); ++i) {
		if((*entityList)[i]->GetID() == id) {

			(*entityList)[i]->m_objectWasRemovedByID = true;

			if(shouldDeallocate) {
				delete (*entityList)[i];
				(*entityList)[i] = nullptr;
			}

			entityList->erase(entityList->begin() + i);
			Console::out::println("Entity with ID " + Console::value(std::to_string(id)) + " was killed successfully.");

			break;

		}
	}

}

Entity *ObjectManager::getEntityByID(std::vector<Entity *> *entityList, int id, bool suppressWarnings) {

	for(int i = 0; i < static_cast<int>(entityList->size()); ++i) {
		if((*entityList)[i]->GetID() == id) {
			return (*entityList)[i];
		}
	}

	if(!suppressWarnings) {
		Console::out::println("Could not find entity with ID " + Console::value(std::to_string(id)) + ". It does not exist in the specified vector.", "Warning");
	}

	return nullptr;

}

Entity *ObjectManager::getEntityByName(std::vector<Entity *> *entityList, std::string name, bool suppressWarnings) {
	
	for(int i = 0; i < static_cast<int>(entityList->size()); ++i) {
		if((*entityList)[i]->GetName() == name) {
			return (*entityList)[i];
		}
	}

	if(!suppressWarnings) {
		Console::out::println("Could not find entity with name " + Console::value(name) + ". It does not exist in the specified vector.", "Warning");
	}

	return nullptr;

}

// Add a file-level scope variable to the ObjectManager namespace
namespace ObjectManager {

	// Keeps track of the next ID to be used in giveUniqueID()
	static int nextUniqueID = 0;

	// You should restructure the function to:
	int giveUniqueID() {
		return nextUniqueID++;
	}

	// With an additional helper function in case you want it
	int peekNextID() {
		return nextUniqueID;
	}

}
/*
You should not be reusing IDs, because then they are not UNIQUE
If you reuse IDs then storing objects by ID is invalid
The IDs of objects already destroyed will refer to new objects

void ObjectManager::giveUniqueID(std::vector<Entity *> *entityList, int &id) {

for(int i = 0; i < entityList->size() + 1; ++i) {

for(int j = 0; j < entityList->size(); ++j) {
if((*entityList)[j]->m_id != i) {
id = i;
} else {
id = -1;
break;
}
}

if(id != -1) {
return;
}

}

if(id == -1) {
id = entityList->size() + 1;
}

}
*/
