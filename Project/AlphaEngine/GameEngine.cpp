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
static int playerID;
static int bossID;
static float BossSize = 100.0f;

void Game::Init(std::vector<Entity *> *entityID) {

	// CREATE OBJECTS HERE
	Player *entityPlayer = new Player(entityID, "../../assets/entity/player/player.png", 3, 60.0f, 60.0f);
	Enemy *entityBoss = new Enemy(entityID, "../../assets/entity/boss/boss.png", 2, COLLIDER_CIRCLE, BossSize, BossSize, BossSize, BossSize);

	playerID = entityPlayer->m_id;
	bossID = entityBoss->m_id;

	// SET WORLD POSITION HERE
	entityPlayer->SetWorldPosition(math::vec3(-250.0f, 0.0f, 0.0f));
	entityBoss->SetWorldPosition(math::vec3(250.0f, 0.0f, 0.0f));

	// SET HEALTH HERE
	entityPlayer->SetHealth(20.0f);
	entityBoss->SetHealth(20.0f);

	entityID->push_back(entityPlayer);
	entityID->push_back(entityBoss);

	//ObjectManager::removeEntityByID(entityID, 1);

}

void Game::Update(std::vector<Entity *> *entityID, double dt) {

	// ENABLE ANIMATIONS
	Graphics::EnableAnimations();
	
	// GET AI OBJECTS
	Enemy *entityBoss = static_cast<Enemy *>(ObjectManager::getEntityByID(entityID, bossID, true));

	// UPDATE OBJECTS
	ObjectManager::updateObjects(entityID);

	// UPDATE AI
	ObjectManager::updateObjectAi(entityID, entityBoss, dt);

}
