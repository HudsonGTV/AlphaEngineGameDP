#include "GameEngine.h"
#include "AEEngine.h"
#include "Math.h"
#include "Player.h"

#include <stdbool.h>

#ifdef _DEBUG
#pragma comment (lib, "Alpha_Engine_D.lib")
#else
#pragma comment (lib, "Alpha_Engine.lib")
#endif

// OBJECTS
static Player *entityPlayer;
static Entity *entityBoss;
static Entity *entityBullet;

void Game::Init(Entity *entityID[ENTITY_COUNT]) {

	// CREATE OBJECTS HERE
	entityPlayer = new Player();
	entityBoss = new Entity();
	entityBullet = new Entity();

	// SET PROPERTIES HERE
	entityPlayer->SetWorldPosition(math::vec3(-250.0f, 0.0f, 0.0f));
	entityBoss->SetWorldPosition(math::vec3(250.0f, 0.0f, 0.0f));
	entityBullet->SetWorldPosition(math::vec3(0.0f, 0.0f, 0.0f));

	// ADD TO ARRAY
	entityID[ID_PLAYER] = entityPlayer;
	entityID[ID_BOSS] = entityBoss;
	entityID[ID_BULLET] = entityBullet;

}

void Game::Update(double dt) {
	
	// UPDATE OBJECTS
	entityPlayer->Update();
	entityBoss->Update();
	entityBullet->Update();
	
}
