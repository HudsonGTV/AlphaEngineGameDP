#include "GraphicsEngine.h"
#include "AEEngine.h"

#include <stdbool.h>

#ifdef _DEBUG
#pragma comment (lib, "Alpha_Engine_D.lib")
#else
#pragma comment (lib, "Alpha_Engine.lib")
#endif

void Graphics::Init() {

	AEGfxSetBackgroundColor(0.3f, 0.15f, 0.05f);

}



void Graphics::Render() {

	// INFORMING THE SYSTEM ABOUT THE LOOP'S START
	AESysFrameStart();

	// HANDLING INPUT
	AEInputUpdate();

	// INFORMING THE SYSTEM ABOUT THE LOOP'S END
	AESysFrameEnd();

	// CHECK IF FORCING THE APPLICATION TO QUIT
	if (AEInputCheckTriggered(VK_ESCAPE) || !AESysDoesWindowExist()) {
		m_isRunning = false;
	}

}
