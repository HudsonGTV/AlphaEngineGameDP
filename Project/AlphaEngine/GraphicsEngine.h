#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H

#include "Entity.h"

namespace Graphics {

	void CreateMesh(Entity *entity, AEGfxVertexList **mesh, AEGfxTexture **texture, char *texturePath, int frameCount = 1, math::vec2 size = math::vec2(60.0f, 60.0f));
	void DrawMesh(Entity *entity, AEGfxVertexList **mesh, AEGfxTexture **texture, int frameCount = 1, float zOrder = 0.0f);
	void EnableAnimations(float speed = 0.25f);

};

class GraphicsEngine {

public:
	void Init(std::vector<Entity *> *entityList);
	void Render(std::vector<Entity *> *entityList, double dt);
	void Uninit();

};

#endif