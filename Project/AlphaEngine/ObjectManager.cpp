#include "ObjectManager.h"
#include "consoleio.h"

void ObjectManager::updateObject(Entity *obj) {

	if(obj != nullptr && !obj->m_objectWasRemovedByID) {
		obj->Update();
	} else {
		static bool problem = false;
		if (!problem)
			Console::out::println(std::string("Object was nullptr"), "Warning");
		problem = true;
	}

}

void ObjectManager::updateObjects(std::vector<Entity *> *entityID) {

	for(Entity *entity : *entityID) {

		if(entity) {
			ObjectManager::updateObject(entity);
		}

	}

}

void ObjectManager::updateObjectAi(std::vector<Entity *> *entityID, IEntityAi *obj) {

	if(obj != nullptr && !obj->m_objectWasRemovedByID) {
		obj->AiUpdate(entityID);
	} else {
		static bool problem = false;
		if (!problem)
			Console::out::println(std::string("Object was nullptr"), "Warning");
		problem = true;
	}

}

void ObjectManager::removeEntityByID(std::vector<Entity *> *entityID, int id, bool shouldDeallocate) {

	if(entityID == nullptr) {
		Console::out::println(std::string("Could not remove entity with ID " + std::to_string(id) + ". It does not exist in the specified vector."), "Warning");
		return;
	}

	for(int i = 0; i < entityID->size(); ++i) {
		if((*entityID)[i]->m_id == id) {

			(*entityID)[i]->m_objectWasRemovedByID = true;

			if(shouldDeallocate) {
				delete (*entityID)[i];
				(*entityID)[i] = nullptr;
			}

			entityID->erase(entityID->begin() + i);
			Console::out::println(std::string("Entity with ID " + std::to_string(id) + " was killed successfully."));

			break;

		}
	}

}

// Add a file-level scope variable to the ObjectManager namespace
namespace ObjectManager {
	// Keeps track of the next ID to be used in giveUniqueID()
	static int nextUniqueID = 0;
	// You should restructure the function to:
	int giveUniqueID() { return nextUniqueID++; }
	// With an additional helper function in case you want it
	int peekNextID() { return nextUniqueID; }
}
/*
	You should not be reusing IDs, because then they are not UNIQUE
	If you reuse IDs then storing objects by ID is invalid
	The IDs of objects already destroyed will refer to new objects

void ObjectManager::giveUniqueID(std::vector<Entity *> *entityID, int &id) {

	for(int i = 0; i < entityID->size() + 1; ++i) {

		for(int j = 0; j < entityID->size(); ++j) {
			if((*entityID)[j]->m_id != i) {
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
		id = entityID->size() + 1;
	}

}
*/

Entity *ObjectManager::getEntityByID(std::vector<Entity *> *entityID, int id) {

	for(int i = 0; i < entityID->size(); ++i) {
		if((*entityID)[i]->m_id == id) {
			return (*entityID)[i];
		}
	}

	Console::out::println(std::string("Could not find entity with ID " + std::to_string(id) + ". It does not exist in the specified vector."), "Warning");

	return nullptr;

}

Entity * ObjectManager::getEntityByName(std::vector<Entity*>* entityID, std::string name) {
	
	for(int i = 0; i < entityID->size(); ++i) {
		if((*entityID)[i]->m_name == name) {
			return (*entityID)[i];
		}
	}

	Console::out::println(std::string("Could not find entity with name " + name + ". It does not exist in the specified vector."), "Warning");

	return nullptr;

}
