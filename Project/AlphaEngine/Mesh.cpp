#include <time.h>

#include "GraphicsEngine.h"

static int frameNum = 0;

static double timeCounter = 0;

static clock_t thisTime = clock();
static clock_t lastTime = thisTime;

void Graphics::CreateMesh(Entity *entity, AEGfxVertexList **mesh, AEGfxTexture **texture, char *texturePath, int frameCount, math::vec2 size) {

	AEGfxMeshStart();

	AEGfxTriAdd(
		-size.x / 2, -size.y / 2, 0xFFFF0000, 0.0f, 1.0f,
		size.x / 2, -size.y / 2, 0xFFFF0000, 1.0f / (float)frameCount, 1.0f,
		-size.x / 2, size.y / 2, 0xFFFF0000, 0.0f, 0.0f
	);

	AEGfxTriAdd(
		size.x / 2, -size.y / 2, 0xFFFF0000, 1.0f / (float)frameCount, 1.0f,
		size.x / 2, size.y / 2, 0xFFFF0000, 1.0f / (float)frameCount, 0.0f,
		-size.x / 2, size.y / 2, 0xFFFF0000, 0.0f, 0.0f
	);

	*mesh = AEGfxMeshEnd();

	*texture = AEGfxTextureLoad(texturePath);

}

void Graphics::DrawMesh(Entity *entity, AEGfxVertexList **mesh, AEGfxTexture **texture, int frameCount, float zOrder) {

	if(frameCount > 6) {
		frameCount = 6;
	}

	float textureFrame[6] {
		0.0f, 1.0f / frameCount, 2.0f / frameCount, 3.0f / frameCount, 4.0f / frameCount, 5.0f / frameCount
	};

	// PLAYER
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	// SET POISITION
	//AEGfxSetPosition(entity->GetPositionX(), entity->GetPositionY());
	AEGfxSetFullTransformWithZOrder(entity->GetPositionX(), entity->GetPositionY(), entity->GetPositionZ() + zOrder, 0.0f, 1.0f, 1.0f);
	// SET TEXTURE
	AEGfxTextureSet(*texture, textureFrame[frameNum], 0.0f);
	// DRAW MESH
	AEGfxSetTransparency(1.0f);
	AEGfxMeshDraw(*mesh, AE_GFX_MDM_TRIANGLES);

}

void Graphics::EnableAnimations(float speed) {

	thisTime = clock();
	timeCounter += (double)(thisTime - lastTime);
	lastTime = thisTime;

	if(timeCounter > (double)(speed * CLOCKS_PER_SEC)) {
		timeCounter -= (double)(speed * CLOCKS_PER_SEC);
		++frameNum;
	}

	if(frameNum > 5) {
		frameNum = 0;
	}

}
