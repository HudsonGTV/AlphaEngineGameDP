#include "GameObjects.h"

void GameObjects::removeEntityByID(std::vector<Entity *> *entityID, int id) {

	for(int i = 0; i < entityID->size(); ++i) {
		if((*entityID)[i]->m_id == id) {
			entityID->erase(entityID->begin() + i);
			break;
		}
	}

}

int GameObjects::giveUniqueID(std::vector<Entity *> *entityID, int &id) {

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
			return id;
		}

	}

	if(id == -1) {
		return entityID->size() + 1;
	}

}

Entity *GameObjects::getEntityByID(std::vector<Entity *> *entityID, int id) {

	for(int i = 0; i < entityID->size(); ++i) {
		if((*entityID)[i]->m_id == id) {
			return (*entityID)[i];
		}
	}

	return nullptr;

}
