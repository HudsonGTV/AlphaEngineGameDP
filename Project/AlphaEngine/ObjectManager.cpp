#include "ObjectManager.h"
#include "consoleio.h"

void ObjectManager::updateObject(Entity *obj) {

	if(!obj->m_objectWasRemovedByID) {
		obj->Update();
	}

}

void ObjectManager::removeEntityByID(std::vector<Entity *> *entityID, int id) {

	if(entityID == nullptr) {
		Console::out::println(std::string("Could not remove entity with ID " + std::to_string(id) + ". It does not exist in the specified vector."), "Warning");
		return;
	}

	for(int i = 0; i < entityID->size(); ++i) {
		if((*entityID)[i]->m_id == id) {
			(*entityID)[i]->m_objectWasRemovedByID = true;
			//delete (*entityID)[i];
			entityID->erase(entityID->begin() + i);
			Console::out::println(std::string("Entity with ID " + std::to_string(id) + " was killed successfully."));
			break;
		}
	}

}

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

Entity *ObjectManager::getEntityByID(std::vector<Entity *> *entityID, int id) {

	for(int i = 0; i < entityID->size(); ++i) {
		if((*entityID)[i]->m_id == id) {
			return (*entityID)[i];
		}
	}

	Console::out::println(std::string("Could not find entity with ID " + std::to_string(id) + ". It does not exist in the specified vector."), "Warning");

	return nullptr;

}
