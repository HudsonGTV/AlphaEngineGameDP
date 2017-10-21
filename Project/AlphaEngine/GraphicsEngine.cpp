#include "GraphicsEngine.h"
#include "AEEngine.h"

#include <stdbool.h>

#ifdef _DEBUG
#pragma comment (lib, "Alpha_Engine_D.lib")
#else
#pragma comment (lib, "Alpha_Engine.lib")
#endif

static AEGfxVertexList* meshPlayer;

void Graphics::Init(Entity *entityArray[ENTITY_COUNT]) {

	AEGfxMeshStart();

	AEGfxTriAdd(
		-25.5f, -25.5f, 0xFFFF0000, 0.0f, 0.0f,
		25.5f, 0.0f, 0xFFFF0000, 0.0f, 0.0f,
		-25.5f, 25.5f, 0xFFFF0000, 0.0f, 0.0f
	);

	meshPlayer = AEGfxMeshEnd();

	AEGfxSetBackgroundColor(0.3f, 0.15f, 0.05f);

}



void Graphics::Render(Entity *entityArray[ENTITY_COUNT], double dt) {

	// Drawing object 1
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	// Set poisition for object 1
	AEGfxSetPosition(entityArray[ID_PLAYER]->GetPositionX(), entityArray[ID_PLAYER]->GetPositionY());
	// No texture for object 1
	AEGfxTextureSet(NULL, 0, 0);
	// Drawing the mesh (list of triangles)
	AEGfxSetTransparency(1.0f);
	AEGfxMeshDraw(meshPlayer, AE_GFX_MDM_TRIANGLES);

}

void Graphics::Uninit() {
	AEGfxMeshFree(meshPlayer);
}
