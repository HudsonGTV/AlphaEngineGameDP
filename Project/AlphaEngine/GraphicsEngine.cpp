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
	Graphics::CreateMesh(&meshRock, &textureRock, "terrain/terrain.png", 6);

	AEGfxSetBackgroundColor(0.3f, 0.15f, 0.05f);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

}

void GraphicsEngine::PreRender(std::vector<Entity *> *entityList, double dt) {

	// TERRAIN
	Graphics::DrawMesh(math::vec2(0.0f, 0.0f), &meshRock, &textureRock, 0.0f, 6, false, 4);

}

void GraphicsEngine::Render(std::vector<Entity *> *entityList, double dt) {

}

void GraphicsEngine::PostRender(std::vector<Entity *> *entityList, double dt) {

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
