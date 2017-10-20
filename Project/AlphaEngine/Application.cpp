#include "Application.h"

Application::Application(int winWidth, int winHeight, int refreshRate) {

	// SET PASSED IN WINDOW PROPERTIES ARGUMENTS
	m_windowWidth = winWidth;
	m_windowHeight = winHeight;
	m_refreshRate = refreshRate;

	// CORE CLASS DECLARATIONS
	m_graphics = new Graphics();
	m_game = new Game();

}

void Application::Init(HINSTANCE instanceH, int show) {

	// INITIALIZE THE SYSTEM 
	AESysInitInfo sysInitInfo;

	// SET SYSTEM PROPERTIES
	sysInitInfo.mCreateWindow = 1;
	sysInitInfo.mAppInstance = instanceH;
	sysInitInfo.mShow = show;
	sysInitInfo.mWinWidth = m_windowWidth;
	sysInitInfo.mWinHeight = m_windowHeight;
	sysInitInfo.mCreateConsole = 1;
	sysInitInfo.mMaxFrameRate = m_refreshRate;
	sysInitInfo.mpWinCallBack = NULL;
	sysInitInfo.mClassStyle = CS_HREDRAW | CS_VREDRAW;
	sysInitInfo.mWindowStyle = WS_OVERLAPPEDWINDOW;
	sysInitInfo.mWindowHandle = NULL;
	sysInitInfo.mHandleWindowMessages = 1;

	// APPLY SYSTEM PROPERTIES
	AESysInit(&sysInitInfo);

	// RESET
	//AESysReset();

	// INITIALIZE FUNCTIONS
	m_graphics->Init();
	m_game->Init();

}

void Application::Loop(HINSTANCE instanceH) {

	// RENDER/UPDATE FUNCTIONS
	m_graphics->Render();
	m_game->Update();

}

void Application::Uninit(HINSTANCE instanceH) {
	AESysExit();
}
