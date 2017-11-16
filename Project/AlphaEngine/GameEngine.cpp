#include "GameEngine.h"
#include "AEEngine.h"
#include "Math.h"
#include "Player.h"
#include "GraphicsEngine.h"
#include "Bullet.h"
#include "Enemy.h"

#include <stdbool.h>
#include <vector>

#ifdef _DEBUG
#pragma comment (lib, "Alpha_Engine_D.lib")
#else
#pragma comment (lib, "Alpha_Engine.lib")
#endif

// OBJECTS
static Player *entityPlayer;
static Enemy *entityBoss;
static Entity *entityBullet;

void Game::Init(std::vector<Entity *> *entityID) {

	// CREATE OBJECTS HERE
	entityPlayer = new Player("../../assets/entity/player/player.png", entityID, 3, 60.0f, 60.0f);
	entityBoss = new Enemy("../../assets/entity/boss/boss.png", 2, COLLIDER_CIRCLE, 60.0f);

	// SET PROPERTIES HERE
	entityPlayer->SetWorldPosition(math::vec3(-250.0f, 0.0f, 0.0f));
	entityBoss->SetWorldPosition(math::vec3(250.0f, 0.0f, 0.0f));

	// ADD TO ARRAY
	entityID->push_back(entityPlayer);
	entityID->push_back(entityBoss);

	AESysPrintf("still works\n");

}

void Game::Update(std::vector<Entity *> *entityID, double dt) {

	// ENABLE ANIMATIONS
	Graphics::EnableAnimations();
	
	// UPDATE OBJECTS
	entityBoss->Update();
	entityPlayer->Update();

	// UPDATE AI
	entityBoss->AiUpdate(entityID);

}
