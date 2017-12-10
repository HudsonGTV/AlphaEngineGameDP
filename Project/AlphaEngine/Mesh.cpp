#include <time.h>

#include "GraphicsEngine.h"

static int frameNum = 0;

static double timeCounter = 0;

static clock_t thisTime = clock();
static clock_t lastTime = thisTime;

void Graphics::CreateMesh(AEGfxVertexList **mesh, AEGfxTexture **texture, std::string texturePath, int frameCount, math::vec2 size) {

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

	texturePath = std::string("../../assets/texture/" + texturePath);

	*mesh = AEGfxMeshEnd();
	*texture = AEGfxTextureLoad(texturePath.c_str());

}

void Graphics::DrawMesh(Entity *entity, AEGfxVertexList **mesh, AEGfxTexture **texture, float zOrder, int frameCount, bool loopAnimation, unsigned int currFrame) {

	if(frameCount > 7 || currFrame > 7) {
		frameCount = 7;
		currFrame = 7;
	}

	if(frameCount == 0) {
		frameCount = 1;
	}

	float textureFrame[7] {
		0.0f, 1.0f / frameCount, 2.0f / frameCount, 3.0f / frameCount, 4.0f / frameCount, 5.0f / frameCount, 6.0f / frameCount
	};

	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetTextureMode(AE_GFX_TM_PRECISE);

	AEGfxSetFullTransformWithZOrder(entity->GetPositionX(), entity->GetPositionY(), entity->GetPositionZ() + zOrder, 0.0f, 1.0f, 1.0f);
	if(loopAnimation) {
		AEGfxTextureSet(*texture, textureFrame[frameNum], 0.0f);
	} else {
		AEGfxTextureSet(*texture, textureFrame[currFrame], 0.0f);
	}
	AEGfxSetTransparency(1.0f);

	AEGfxMeshDraw(*mesh, AE_GFX_MDM_TRIANGLES);

}

void Graphics::DrawMesh(math::vec2 pos, AEGfxVertexList **mesh, AEGfxTexture **texture, float zOrder, int frameCount, bool loopAnimation, unsigned int currFrame) {

	if(frameCount > 7 || currFrame > 7) {
		frameCount = 7;
		currFrame = 7;
	}

	if(frameCount == 0) {
		frameCount = 1;
	}

	float textureFrame[7]{
		0.0f, 1.0f / frameCount, 2.0f / frameCount, 3.0f / frameCount, 4.0f / frameCount, 5.0f / frameCount, 6.0f / frameCount
	};

	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetTextureMode(AE_GFX_TM_PRECISE);

	AEGfxSetFullTransformWithZOrder(pos.x, pos.y, zOrder, 0.0f, 1.0f, 1.0f);
	if(loopAnimation) {
		AEGfxTextureSet(*texture, textureFrame[frameNum], 0.0f);
	} else {
		AEGfxTextureSet(*texture, textureFrame[currFrame], 0.0f);
	}
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

	if(frameNum > 6) {
		frameNum = 0;
	}

}
