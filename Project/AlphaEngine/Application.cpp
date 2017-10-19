#include "Application.h"

Application::Application() {

}

void Application::Init(HINSTANCE instanceH, int show) {

	// INITIALIZE THE SYSTEM 
	AESysInitInfo sysInitInfo;

	sysInitInfo.mCreateWindow = 1;
	sysInitInfo.mAppInstance = instanceH;
	sysInitInfo.mShow = show;
	sysInitInfo.mWinWidth = 800;
	sysInitInfo.mWinHeight = 600;
	sysInitInfo.mCreateConsole = 1;
	sysInitInfo.mMaxFrameRate = 60;
	sysInitInfo.mpWinCallBack = NULL;
	sysInitInfo.mClassStyle = CS_HREDRAW | CS_VREDRAW;
	sysInitInfo.mWindowStyle = WS_OVERLAPPEDWINDOW;
	sysInitInfo.mWindowHandle = NULL;
	sysInitInfo.mHandleWindowMessages = 1;

	AESysInit(&sysInitInfo);

	AESysReset();

}

void Application::Render(HINSTANCE instanceH) {

	// INFORMING THE SYSTEM ABOUT THE LOOP'S START
	AESysFrameStart();

	// HANDLING INPUT
	AEInputUpdate();


	// INFORMING THE SYSTEM ABOUT THE LOOP'S END
	AESysFrameEnd();

	// CHECK IF FORCING THE APPLICATION TO QUIT
	if(AEInputCheckTriggered(VK_ESCAPE) || 0 == AESysDoesWindowExist()) {
		isRunning = false;
	}

}
