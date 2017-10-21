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

static AEGfxTexture *texturePlayer;

void Graphics::Init(Entity *entityArray[ENTITY_COUNT]) {

	CreateMesh(&meshPlayer, &texturePlayer, "../../assets/entity/player/player.png", 3);

	AEGfxSetBackgroundColor(0.3f, 0.15f, 0.05f);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

}

void Graphics::Render(Entity *entityArray[ENTITY_COUNT], double dt) {

	DrawMesh(entityArray[ID_PLAYER], &meshPlayer, &texturePlayer, 3);

}

void Graphics::Uninit() {

	// FREE MESHES
	AEGfxMeshFree(meshPlayer);

	// FREE TEXTURES
	AEGfxTextureUnload(texturePlayer);

}
