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

static float texturePlayerFrame[3] {
	0.0f, 0.3333f, 0.6666f
};

static int frameNum = 0;

static double timeCntr = 0;

static clock_t thisTime = clock();
static clock_t lastTime = thisTime;

void Graphics::Init(Entity *entityArray[ENTITY_COUNT]) {

	AEGfxMeshStart();

	AEGfxTriAdd(
		-30.0f, -30.0f, 0xFFFF0000, 0.0f, 1.0f,
		30.0f, -30.0f, 0xFFFF0000, 0.33f, 1.0f,
		-30.0f, 30.0f, 0xFFFF0000, 0.0f, 0.0f);

	AEGfxTriAdd(
		30.0f, -30.0f, 0xFFFF0000, 0.33f, 1.0f,
		30.0f, 30.0f, 0xFFFF0000, 0.33f, 0.0f,
		-30.0f, 30.0f, 0xFFFF0000, 0.0f, 0.0f);

	meshPlayer = AEGfxMeshEnd();

	texturePlayer = AEGfxTextureLoad("../../assets/entity/player/player.png");

	AEGfxSetBackgroundColor(0.3f, 0.15f, 0.05f);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

}

void Graphics::Render(Entity *entityArray[ENTITY_COUNT], double dt) {

	thisTime = clock();
	timeCntr += (double)(thisTime - lastTime);
	lastTime = thisTime;

	// PLAYER
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	// SET POISITION
	AEGfxSetPosition(entityArray[ID_PLAYER]->GetPositionX(), entityArray[ID_PLAYER]->GetPositionY());
	// SET TEXTURE
	AEGfxTextureSet(texturePlayer, texturePlayerFrame[frameNum], 0.0f);
	// DRAW MESH
	AEGfxSetTransparency(1.0f);
	AEGfxMeshDraw(meshPlayer, AE_GFX_MDM_TRIANGLES);

	if(timeCntr > (double)(0.25 * CLOCKS_PER_SEC)) {
		timeCntr -= (double)(0.25 * CLOCKS_PER_SEC);
		++frameNum;
	}

	if(frameNum > 2) {
		frameNum = 0;
	}

}

void Graphics::Uninit() {

	// FREE MESHES
	AEGfxMeshFree(meshPlayer);

	// FREE TEXTURES
	AEGfxTextureUnload(texturePlayer);

}
