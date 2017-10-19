#include "Application.h"

Application::Application(int winWidth, int winHeight, int refreshRate = 60) {

	m_windowWidth = winWidth;
	m_windowHeight = winHeight;
	m_refreshRate = refreshRate;

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

	AESysInit(&sysInitInfo);

	AESysReset();

	// GAME INIT FUNCTION
	m_graphics->Init();
	m_game->Init();

}

void Application::Loop(HINSTANCE instanceH) {

	m_graphics->Render();
	m_game->Update();

}

void Application::Uninit(HINSTANCE instanceH) {
	AESysExit();
}
