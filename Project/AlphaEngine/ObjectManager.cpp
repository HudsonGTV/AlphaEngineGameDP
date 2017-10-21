#include "ObjectManager.h"

void Objects::Init(Entity *entityArray[ENTITY_COUNT]) {

	Player *player = new Player();

	entityArray[ID_PLAYER] = player;

}
