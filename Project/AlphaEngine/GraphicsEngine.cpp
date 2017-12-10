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

}

void GraphicsEngine::Render(std::vector<Entity *> *entityList, double dt) {

}

void GraphicsEngine::PostRender(std::vector<Entity *> *entityList, double dt) {

	// TERRAIN
	Graphics::DrawMesh(math::vec2(-700, 500.0f), &meshRock, &textureRock, 0.0f, 6, false, 0);
	Graphics::DrawMesh(math::vec2(700, 500.0f), &meshRock, &textureRock, 0.0f, 6, false, 2);

	// TOP
	for(int i = -650; i <= 650; i += 50) {
		Graphics::DrawMesh(math::vec2(i, 500.0f), &meshRock, &textureRock, 0.0f, 6, false, 1);
	}

	// BOTTOM
	for(int i = -700; i <= 700; i += 50) {
		Graphics::DrawMesh(math::vec2(i, -500.0f), &meshRock, &textureRock, 0.0f, 6, false, 1);
	}

	// LEFT
	for(int i = -450; i <= 450; i += 50) {
		Graphics::DrawMesh(math::vec2(-700, i), &meshRock, &textureRock, 0.0f, 6, false, 0);
	}

	// RIGHT
	for(int i = -450; i <= 450; i += 50) {
		Graphics::DrawMesh(math::vec2(700, i), &meshRock, &textureRock, 0.0f, 6, false, 0);
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
