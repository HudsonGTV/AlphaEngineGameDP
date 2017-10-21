#include "GraphicsEngine.h"
#include "AEEngine.h"
#include "Math.h"

#include <time.h>
#include <stdbool.h>

#ifdef _DEBUG
#pragma comment (lib, "Alpha_Engine_D.lib")
#else
#pragma comment (lib, "Alpha_Engine.lib")
#endif

static AEGfxVertexList *meshPlayer;
static AEGfxVertexList *meshBoss;
static AEGfxVertexList *meshBullet;

static AEGfxTexture *texturePlayer;
static AEGfxTexture *textureBoss;
static AEGfxTexture *textureBullet;

void Graphics::Init(Entity *entityID[ENTITY_COUNT]) {

	Graphics::CreateMesh(entityID[ID_PLAYER], &meshPlayer, &texturePlayer, "../../assets/entity/player/player.png", 3);

	AEGfxSetBackgroundColor(0.3f, 0.15f, 0.05f);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

}

void Graphics::Render(Entity *entityID[ENTITY_COUNT], double dt) {

	Graphics::DrawMesh(entityID[ID_PLAYER], &meshPlayer, &texturePlayer, 3);

}

void Graphics::Uninit() {

	// FREE MESHES
	AEGfxMeshFree(meshPlayer);

	// FREE TEXTURES
	AEGfxTextureUnload(texturePlayer);

}
