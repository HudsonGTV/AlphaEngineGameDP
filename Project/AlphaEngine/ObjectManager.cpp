#include "ObjectManager.h"
#include "Input.h"

static Player *player;

void Objects::Init(Entity *entityID[ENTITY_COUNT]) {

	// CREATE OBJECTS HERE
	player = new Player();

	// SET PROPERTIES HERE
	player->SetPosition(math::vec3(0.5f, 0.25f, 0.0f));

	// ADD TO ARRAY
	entityID[ID_PLAYER] = player;

}

void Objects::Update(double dt) {

	player->Update();

}
