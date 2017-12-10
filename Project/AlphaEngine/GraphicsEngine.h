#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H

#include "Entity.h"

namespace Graphics {

	void CreateMesh(AEGfxVertexList **mesh, AEGfxTexture **texture, std::string texturePath, int frameCount = 1, math::vec2 size = math::vec2(60.0f, 60.0f));
	void DrawMesh(Entity *entity, AEGfxVertexList **mesh, AEGfxTexture **texture, float zOrder = 1.0f, int frameCount = 1, bool loopAnimation = true, int currFrame = 0);
	void DrawMesh(math::vec2 pos, AEGfxVertexList **mesh, AEGfxTexture **texture, float zOrder = 1.0f, int frameCount = 1, bool loopAnimation = true, int currFrame = 0);
	void EnableAnimations(float speed = 0.25f);

};

class GraphicsEngine {

public:
	void Init(std::vector<Entity *> *entityList);
	void PreRender(std::vector<Entity *> *entityList, double dt);
	void Render(std::vector<Entity *> *entityList, double dt);
	void PostRender(std::vector<Entity *> *entityList, double dt);
	void Uninit();

};

#endif