#include "GraphicsEngine.h"
#include "AEEngine.h"
#include "Math.h"
#include "Text.h"
#include "consoleio.h"

#include <time.h>
#include <stdbool.h>

void GenerateTerrain();

// MESHES
static AEGfxVertexList *meshTerrain;
static AEGfxVertexList *meshNumbers;

// TEXTURES
static AEGfxTexture *textureTerrain;
static AEGfxTexture *textureNumbers;
static AEGfxTexture *textureNumberR;
static AEGfxTexture *textureNumberW;

// TEXT
static Text *textFPS;
static Text *textHP;
static Text *textPaused;
static Text *textDebug;

// TERRAIN
static std::vector<math::vec3 *> objectList;

void GraphicsEngine::Init(std::vector<Entity *> *entityList) {

	srand(time(NULL));

	// CREATE MESHES
	Graphics::CreateMesh(&meshTerrain, &textureTerrain, "terrain/terrain.png", 7, math::vec2(50.0f));
	Graphics::CreateMesh(&meshNumbers, &textureNumbers, "font/number.png", 10, math::vec2(20.0f));
	Graphics::CreateMesh(&meshNumbers, &textureNumberR, "font/numberRed.png", 10, math::vec2(20.0f));
	Graphics::CreateMesh(&meshNumbers, &textureNumberW, "font/numberWarning.png", 10, math::vec2(20.0f));

	// CREATE TEXT
	textFPS = new Text(math::vec2(0.0f), " FPS", 20);
	textHP = new Text(math::vec2(0.0f), "HP: ", 20);
	textPaused = new Text(math::vec2(0.0f), "Game Paused", 60);
	textDebug = new Text(math::vec2(0.0f), "Enemy HP: \nCamera Coordinates: TODO: ADD SUPPORT FOR COORDS\n\nDebug Mode", 20);

	textFPS->SetTextAlignment(TEXT_LEFT);
	textHP->SetTextAlignment(TEXT_LEFT);
	textPaused->SetTextAlignment(TEXT_CENTER);
	textDebug->SetTextAlignment(TEXT_LEFT);

	textFPS->SetOpacity(0.5f);
	textHP->SetOpacity(0.5f);
	textPaused->SetOpacity(1.0f);
	textDebug->SetOpacity(1.0f);

	GenerateTerrain();

	//AEGfxSetBackgroundColor(0.3f, 0.15f, 0.05f);
	AEGfxSetBackgroundColor(0.44f, 0.24f, 0.09f);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

}

void GraphicsEngine::PreRender(std::vector<Entity *> *entityList, double dt) {

	/* BACKGROUND COLOR */
	Graphics::DrawMesh(math::vec2(0.0f), &meshTerrain, &textureTerrain, 0.0f, 7, false, 6, 1.0f, math::vec2(29.0f, 20.0f));

	/* ROCKS */
	for(math::vec3 *objPos : objectList) {
		if(objPos) {
			Graphics::DrawMesh(math::vec2(objPos->x, objPos->y), &meshTerrain, &textureTerrain, 1.0f, 7, false, objPos->z);
		}
	}

}

void GraphicsEngine::Render(std::vector<Entity *> *entityList, double dt) {

}

void GraphicsEngine::PostRender(std::vector<Entity *> *entityList, double dt) {

	/* TERRAIN */

	// TOP CORNERS
	Graphics::DrawMesh(math::vec2(-650.0f, 500.0f), &meshTerrain, &textureTerrain, 0.0f, 7, false, 0);
	Graphics::DrawMesh(math::vec2(650.0f, 500.0f), &meshTerrain, &textureTerrain, 0.0f, 7, false, 2);

	// TOP
	for(float i = -600.0f; i <= 600.0f; i += 50.0f) {
		Graphics::DrawMesh(math::vec2(i, 500.0f), &meshTerrain, &textureTerrain, 0.0f, 7, false, 1);
	}

	// BOTTOM
	for(float i = -700.0f; i <= 700.0f; i += 50.0f) {
		Graphics::DrawMesh(math::vec2(i, -500.0f), &meshTerrain, &textureTerrain, 0.0f, 7, false, 3);
	}

	// LEFT
	for(float i = -500.0f; i <= 500.0f; i += 50.0f) {
		Graphics::DrawMesh(math::vec2(-700.0f, i), &meshTerrain, &textureTerrain, 0.0f, 7, false, 3);
	}

	// RIGHT
	for(float i = -500.0f; i <= 500.0f; i += 50.0f) {
		Graphics::DrawMesh(math::vec2(700.0f, i), &meshTerrain, &textureTerrain, 0.0f, 7, false, 3);
	}

	// HEALTH
	Entity *tmpPlayer = ObjectManager::getEntityByName(entityList, "Player");

	if(tmpPlayer != nullptr) {

		float nmX = 0.0f;
		float nmY = 0.0f;

		Graphics::WorldToScreen(nmX, nmY, Graphics::ScreenCorner::SC_BOTTOM_LEFT);

		textHP->Render(math::vec2(nmX + 20.0f, nmY + 20.0f));

		Graphics::DrawCounter(math::vec2(nmX + 80.0f, nmY + 20.0f), (unsigned int)round(tmpPlayer->GetHealth()), &meshNumbers, &textureNumberR);
		
	}

	if(Console::out::filterStatus(Console::Filters::Debug)) {

		Graphics::DebugLines(true);

		double fps = (1.0 / dt);

		float nmX = 0.0f;
		float nmY = 0.0f;

		Graphics::WorldToScreen(nmX, nmY, Graphics::ScreenCorner::SC_TOP_LEFT);

		// FPS
		Graphics::DrawCounter(math::vec2(nmX + 20.0f, nmY - 20.0f), (unsigned int)round(fps), &meshNumbers, &textureNumbers, 30, &textureNumberW);
		textFPS->Render(math::vec2(nmX + 65.0f, nmY - 20.0f));

		// DEBUG
		textDebug->Render(math::vec2(nmX + 20.0f, nmY - 50.0f));

		Entity *tmpEnemy = ObjectManager::getEntityByName(entityList, "Enemy", true);

		if(tmpEnemy != nullptr) {
			Graphics::DrawCounter(math::vec2(nmX + 200.0f, nmY - 50.0f), (unsigned int)round(tmpEnemy->GetHealth()), &meshNumbers, &textureNumbers);
		} else {
			Graphics::DrawCounter(math::vec2(nmX + 200.0f, nmY - 50.0f), 0U, &meshNumbers, &textureNumbers);
		}

	} else {
		Graphics::DebugLines(false);
	}

}

void GraphicsEngine::PauseRender(std::vector<Entity *> *entityList, double dt) {

	math::vec2 pausedCoords = math::vec2();

	Graphics::WorldToScreen(pausedCoords.x, pausedCoords.y, Graphics::ScreenCorner::SC_MIDDLE);

	textPaused->Render(pausedCoords);

}

void GraphicsEngine::Uninit() {

	delete textFPS;
	textFPS = nullptr;

	// FREE MESHES
	AEGfxMeshFree(meshTerrain);
	AEGfxMeshFree(meshNumbers);

	// FREE TEXTURES
	AEGfxTextureUnload(textureTerrain);
	AEGfxTextureUnload(textureNumbers);

}

void GenerateTerrain() {

	for(int i = 0; i < 25; ++i) {

		int positionX = ((rand() % (12 + 12)) + -12) * 50;
		int positionY = ((rand() % (9 + 9)) - 9) * 50;
		int randType = (rand() % (5 - 4)) + 4;

		objectList.push_back(new math::vec3(positionX, positionY, randType));

	}

}
