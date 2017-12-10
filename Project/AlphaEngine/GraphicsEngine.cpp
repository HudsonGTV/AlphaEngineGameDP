#include "GraphicsEngine.h"
#include "AEEngine.h"
#include "Math.h"

#include <time.h>
#include <stdbool.h>

// MESHES
static AEGfxVertexList *meshRock;

// TEXTURES
static AEGfxTexture *textureRock;


void GraphicsEngine::Init(std::vector<Entity *> *entityList) {

	// CREATE MESHES
	Graphics::CreateMesh(&meshRock, &textureRock, "terrain/terrain.png", 6, math::vec2(50.0f, 50.0f));

	AEGfxSetBackgroundColor(0.3f, 0.15f, 0.05f);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

}

void GraphicsEngine::PreRender(std::vector<Entity *> *entityList, double dt) {

	/* ROCKS */
	Graphics::DrawMesh(math::vec2(-600.0f, 450.0f), &meshRock, &textureRock, 0.0f, 6, false, 4);
	Graphics::DrawMesh(math::vec2(-400.0f, 450.0f), &meshRock, &textureRock, 0.0f, 6, false, 4);
	Graphics::DrawMesh(math::vec2(-350.0f, 450.0f), &meshRock, &textureRock, 0.0f, 6, false, 5);
	Graphics::DrawMesh(math::vec2(-100.0f, 450.0f), &meshRock, &textureRock, 0.0f, 6, false, 5);

}

void GraphicsEngine::Render(std::vector<Entity *> *entityList, double dt) {

}

void GraphicsEngine::PostRender(std::vector<Entity *> *entityList, double dt) {

	/* TERRAIN */

	// TOP CORNERS
	Graphics::DrawMesh(math::vec2(-700.0f, 500.0f), &meshRock, &textureRock, 0.0f, 6, false, 0);
	Graphics::DrawMesh(math::vec2(700.0f, 500.0f), &meshRock, &textureRock, 0.0f, 6, false, 2);

	// TOP
	for(float i = -650.0f; i <= 650.0f; i += 50.0f) {
		Graphics::DrawMesh(math::vec2(i, 500.0f), &meshRock, &textureRock, 0.0f, 6, false, 1);
	}

	// BOTTOM
	for(float i = -700.0f; i <= 700.0f; i += 50.0f) {
		Graphics::DrawMesh(math::vec2(i, -500.0f), &meshRock, &textureRock, 0.0f, 6, false, 1);
	}

	// LEFT
	for(float i = -450.0f; i <= 450.0f; i += 50.0f) {
		Graphics::DrawMesh(math::vec2(-700.0f, i), &meshRock, &textureRock, 0.0f, 6, false, 0);
	}

	// RIGHT
	for(float i = -450.0f; i <= 450.0f; i += 50.0f) {
		Graphics::DrawMesh(math::vec2(700.0f, i), &meshRock, &textureRock, 0.0f, 6, false, 0);
	}

}

void GraphicsEngine::Uninit() {

	// FREE MESHES
	//AEGfxMeshFree(meshPlayer);
	//AEGfxMeshFree(meshBoss);
	//AEGfxMeshFree(meshBullet);
	//AEGfxMeshFree(meshMine);

	// FREE TEXTURES
	//AEGfxTextureUnload(texturePlayer);
	//AEGfxTextureUnload(textureBoss);
	//AEGfxTextureUnload(textureBullet);
	//AEGfxTextureUnload(textureMine);

}
