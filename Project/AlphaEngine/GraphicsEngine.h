#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H

#include "Entity.h"

class Graphics {

private:
	void CreateMesh(AEGfxVertexList **mesh, AEGfxTexture **texture, char *texturePath, int frameCount = 1);
	void DrawMesh(Entity *entity, AEGfxVertexList **mesh, AEGfxTexture **texture, int frameCount = 1);

public:
	void Init(Entity *entityArray[ENTITY_COUNT]);
	void Render(Entity *entityArray[ENTITY_COUNT], double dt);
	void Uninit();

};

#endif