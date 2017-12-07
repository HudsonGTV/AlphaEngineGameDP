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

// MESHES
//static AEGfxVertexList *meshPlayer;
//static AEGfxVertexList *meshBoss;
//static AEGfxVertexList *meshBullet;
//static AEGfxVertexList *meshMine;

// TEXTURES
//static AEGfxTexture *texturePlayer;
//static AEGfxTexture *textureBoss;
//static AEGfxTexture *textureBullet;
//static AEGfxTexture *textureMine;

void GraphicsEngine::Init(std::vector<Entity *> *entityList) {

	// CREATE MESHES
	//Graphics::CreateMesh(entityList[ID_PLAYER], &meshPlayer, &texturePlayer, "../../assets/entity/player/player.png", 3);
	//Graphics::CreateMesh(entityList[ID_BOSS], &meshBoss, &textureBoss, "../../assets/entity/boss/boss.png", 2);
	//Graphics::CreateMesh(entityList[ID_BULLET], &meshBullet, &textureBullet, "../../assets/entity/bullet/bullet.png", 1);
	//Graphics::CreateMesh(entityList[ID_BULLET], &meshMine, &textureMine, "../../assets/entity/mine/mine.png", 1);

	AEGfxSetBackgroundColor(0.3f, 0.15f, 0.05f);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

}

void GraphicsEngine::Render(std::vector<Entity *> *entityList, double dt) {

	//ENABLE ANIMATIONS
	//Graphics::EnableAnimations();

	// DRAW MESHES
	//Graphics::DrawMesh(entityList[ID_PLAYER], &meshPlayer, &texturePlayer, 3);
	//Graphics::DrawMesh(entityList[ID_BOSS], &meshBoss, &textureBoss, 2);
	//Graphics::DrawMesh(entityList[ID_BULLET], &meshBullet, &textureBullet, 1);
	//Graphics::DrawMesh(entityList[ID_BULLET], &meshMine, &textureMine, 1);

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
