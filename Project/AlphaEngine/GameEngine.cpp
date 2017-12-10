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
static EntityID idPlayer;
static EntityID idBoss;

void Game::Init(std::vector<Entity *> *entityList) {

	// CREATE OBJECTS HERE
	Player *entityPlayer = new Player(entityList, "entity/player/player.png", 3, 60.0f, 60.0f);
	Enemy *entityBoss = new Enemy(entityList, "entity/boss/boss.png", 2, COLLIDER_CIRCLE, 100.0f, 100.0f, 100.0f, 100.0f);

	Entity *entityWallT = new Entity(entityList, "entity/wall/border.png", 1, COLLIDER_BOX, 1400.0f, 50.0f, 0.0f, 0.0f);
	Entity *entityWallB = new Entity(entityList, "entity/wall/border.png", 1, COLLIDER_BOX, 1400.0f, 50.0f, 0.0f, 0.0f);
	Entity *entityWallL = new Entity(entityList, "entity/wall/border.png", 1, COLLIDER_BOX, 50.0f, 1000.0f, 0.0f, 0.0f);
	Entity *entityWallR = new Entity(entityList, "entity/wall/border.png", 1, COLLIDER_BOX, 50.0f, 1000.0f, 0.0f, 0.0f);

	// STORE ID
	idPlayer = entityPlayer->GetID();
	idBoss = entityBoss->GetID();

	// SET NAME
	entityWallT->SetName("WallT");
	entityWallB->SetName("WallB");
	entityWallL->SetName("WallL");
	entityWallR->SetName("WallR");

	// SET GROUP
	entityPlayer->SetGroup("GroupEntity");
	entityBoss->SetGroup("GroupEntity");

	entityWallT->SetGroup("GroupWall");
	entityWallB->SetGroup("GroupWall");
	entityWallL->SetGroup("GroupWall");
	entityWallR->SetGroup("GroupWall");

	// SET WORLD POSITION HERE
	entityPlayer->SetWorldPosition(math::vec3(-250.0f, 0.0f, 0.0f));
	entityBoss->SetWorldPosition(math::vec3(250.0f, 0.0f, 0.0f));

	entityWallT->SetWorldPosition(math::vec3(0.0f, 500.0f, 0.0f));
	entityWallB->SetWorldPosition(math::vec3(0.0f, -500.0f, 0.0f));
	entityWallL->SetWorldPosition(math::vec3(-700.0f, 0.0f, 0.0f));
	entityWallR->SetWorldPosition(math::vec3(700.0f, 0.0f, 0.0f));

	// SET HEALTH HERE
	entityPlayer->SetHealth(20.0f);
	entityBoss->SetHealth(20.0f);

	entityWallT->SetInvincible(true);
	entityWallB->SetInvincible(true);
	entityWallL->SetInvincible(true);
	entityWallR->SetInvincible(true);

	// STORE IN VECTOR
	entityList->push_back(entityPlayer);
	entityList->push_back(entityBoss);

	entityList->push_back(entityWallT);
	entityList->push_back(entityWallB);
	entityList->push_back(entityWallL);
	entityList->push_back(entityWallR);

}

void Game::Update(std::vector<Entity *> *entityList, double dt) {

	// ENABLE ANIMATIONS
	Graphics::EnableAnimations();
	
	// GET AI OBJECTS
	Enemy *entityBoss = static_cast<Enemy *>(ObjectManager::getEntityByID(entityList, idBoss, true));

	// UPDATE OBJECTS
	ObjectManager::updateObjects(entityList);

	// UPDATE AI
	ObjectManager::updateObjectAi(entityList, entityBoss, dt);

}
