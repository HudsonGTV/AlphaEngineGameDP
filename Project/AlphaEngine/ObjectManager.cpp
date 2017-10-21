#include "ObjectManager.h"

void Objects::Init(Entity entityArray[ENTITY_COUNT]) {

	// CREATE OBJECTS HERE
	Player *player = new Player();

	// SET PROPERTIES HERE
	player->SetPosition(math::vec3(0.5f, 0.25f, 0.0f));

	// ADD TO ARRAY
	entityArray[ID_PLAYER] = *player;

}
