#include "GraphicsEngine.h"
#include "AEEngine.h"

#include <stdbool.h>

#ifdef _DEBUG
#pragma comment (lib, "Alpha_Engine_D.lib")
#else
#pragma comment (lib, "Alpha_Engine.lib")
#endif

void Graphics::Init(Entity entityArray[ENTITY_COUNT]) {

	AEGfxSetBackgroundColor(0.3f, 0.15f, 0.05f);

}



void Graphics::Render(double dt) {

}
