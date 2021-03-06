#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H

#include "Entity.h"

// HACK: UNDEFINE DRAWTEXT FROM THE WINDOWS LIBRARY
#undef DrawText

#define TEXT_ASCII_COUNT 54

/*constexpr unsigned long long int operator "" FPS(unsigned long long int fps) {
	return fps;
}*/

namespace Graphics {

	enum ScreenCorner {
		SC_TOP_LEFT, SC_TOP, SC_TOP_RIGHT,
		SC_MIDDLE_LEFT, SC_MIDDLE, SC_MIDDLE_RIGHT,
		SC_BOTTOM_LEFT, SC_BOTTOM, SC_BOTTOM_RIGHT
	};

	void CreateMesh(AEGfxVertexList **mesh, AEGfxTexture **texture, std::string texturePath, int frameCount = 1, math::vec2 size = math::vec2(60.0f, 60.0f));
	void DrawMesh(Entity *entity, AEGfxVertexList **mesh, AEGfxTexture **texture, float zOrder = 1.0f, int frameCount = 1, bool loopAnimation = true, unsigned int currFrame = 0, float opacity = 1.0f, math::vec2 scale = math::vec2(1.0f));
	void DrawMesh(math::vec2 pos, AEGfxVertexList **mesh, AEGfxTexture **texture, float zOrder = 1.0f, int frameCount = 1, bool loopAnimation = true, unsigned int currFrame = 0, float opacity = 1.0f, math::vec2 scale = math::vec2(1.0f));
	void DrawCounter(math::vec2 pos, int number, AEGfxVertexList **mesh, AEGfxTexture **texture, int lowestSafeValue = 0, AEGfxTexture **textureW = nullptr);
	void DrawText(math::vec2 pos, std::string str, AEGfxVertexList **mesh, AEGfxTexture **texture, int size = 30, float opacity = 1.0f);
	void EnableAnimations(float speed = 0.25f);
	void WorldToScreen(float &x, float &y, ScreenCorner corner = SC_TOP_LEFT);
	void DebugLines(bool isEnabled);

	bool CheckDebugLineStatus();

};

class GraphicsEngine {

public:
	void Init(std::vector<Entity *> *entityList);
	void PreRender(std::vector<Entity *> *entityList, double dt);
	void Render(std::vector<Entity *> *entityList, double dt);
	void PostRender(std::vector<Entity *> *entityList, double dt);
	void PauseRender(std::vector<Entity *> *entityList, double dt);
	void Uninit();

};

#endif