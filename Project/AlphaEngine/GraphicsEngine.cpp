#include "GraphicsEngine.h"
#include "AEEngine.h"
#include "Math.h"

#include <time.h>
#include <stdbool.h>

// MESHES
static AEGfxVertexList *meshTerrain;
static AEGfxVertexList *meshNumbers;
static AEGfxVertexList *meshLetters;

// TEXTURES
static AEGfxTexture *textureTerrain;
static AEGfxTexture *textureNumbers;
static AEGfxTexture *textureLetters;

// TERRAIN
static std::vector<math::vec3 *> objectList;

void GraphicsEngine::Init(std::vector<Entity *> *entityList) {

	srand(time(NULL));

	// CREATE MESHES
	Graphics::CreateMesh(&meshTerrain, &textureTerrain, "terrain/terrain.png", 7, math::vec2(50.0f));
	Graphics::CreateMesh(&meshNumbers, &textureNumbers, "font/number.png", 10, math::vec2(30.0f));
	Graphics::CreateMesh(&meshLetters, &textureLetters, "font/letter.png", 53, math::vec2(30.0f));

	for(int i = 0; i < 25; ++i) {

		int positionX = ((rand() % (12 - -12)) + -12) * 50;
		int positionY = ((rand() % (9 - -9)) + -9) * 50;
		int randType = (rand() % (5 - 4)) + 4;

		objectList.push_back(new math::vec3(positionX, positionY, randType));

	}

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

		Graphics::DrawCounter(math::vec2(nmX + 25.0f, nmY + 30.0f), (unsigned int)round(tmpPlayer->GetHealth()), &meshNumbers, &textureNumbers);

	}

	// FPS
	double fps = (1.0 / dt);

	float nmX = 0.0f;
	float nmY = 0.0f;

	Graphics::WorldToScreen(nmX, nmY, Graphics::ScreenCorner::SC_TOP_LEFT);

	Graphics::DrawCounter(math::vec2(nmX + 25.0f, nmY - 30.0f), (unsigned int)round(fps), &meshNumbers, &textureNumbers);
	Graphics::DrawText(math::vec2(nmX + 75.0f, nmY - 30.0f), "FPS", &meshLetters, &textureLetters);

}

void GraphicsEngine::Uninit() {

	// FREE MESHES
	AEGfxMeshFree(meshTerrain);
	AEGfxMeshFree(meshNumbers);

	// FREE TEXTURES
	AEGfxTextureUnload(textureTerrain);
	AEGfxTextureUnload(textureNumbers);

}
