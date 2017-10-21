#include "GraphicsEngine.h"
#include "AEEngine.h"

#include <stdbool.h>

#ifdef _DEBUG
#pragma comment (lib, "Alpha_Engine_D.lib")
#else
#pragma comment (lib, "Alpha_Engine.lib")
#endif

static AEGfxVertexList *meshPlayer;

static AEGfxTexture *texturePlayer;

void Graphics::Init(Entity *entityArray[ENTITY_COUNT]) {

	AEGfxMeshStart();

	AEGfxTriAdd(
		-30.0f, -30.0f, 0x00FF00FF, 0.0f, 1.0f,
		30.0f, -30.0f, 0x00FFFF00, 1.0f, 1.0f,
		-30.0f, 30.0f, 0x00F00FFF, 0.0f, 0.0f);

	AEGfxTriAdd(
		30.0f, -30.0f, 0x00FFFFFF, 1.0f, 1.0f,
		30.0f, 30.0f, 0x00FFFFFF, 1.0f, 0.0f,
		-30.0f, 30.0f, 0x00FFFFFF, 0.0f, 0.0f);

	meshPlayer = AEGfxMeshEnd();

	texturePlayer = AEGfxTextureLoad("assets/entity/player/player.png");

	AEGfxSetBackgroundColor(0.3f, 0.15f, 0.05f);

}



void Graphics::Render(Entity *entityArray[ENTITY_COUNT], double dt) {

	// Drawing object 1
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	// Set poisition for object 1
	AEGfxSetPosition(entityArray[ID_PLAYER]->GetPositionX(), entityArray[ID_PLAYER]->GetPositionY());
	// No texture for object 1
	AEGfxTextureSet(texturePlayer, 0.0f, 0.0f);
	// Drawing the mesh (list of triangles)
	AEGfxSetTransparency(1.0f);
	AEGfxMeshDraw(meshPlayer, AE_GFX_MDM_TRIANGLES);

}

void Graphics::Uninit() {

	// FREE MESHES
	AEGfxMeshFree(meshPlayer);

	// FREE TEXTURES
	AEGfxTextureUnload(texturePlayer);

}
