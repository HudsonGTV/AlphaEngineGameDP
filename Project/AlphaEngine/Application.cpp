#include <time.h>

#include "Application.h"

Application::Application(int winWidth, int winHeight, int refreshRate) {

	// SET PASSED IN WINDOW PROPERTIES ARGUMENTS
	m_windowWidth = winWidth;
	m_windowHeight = winHeight;
	m_refreshRate = refreshRate;

	// CORE CLASS DECLARATIONS
	m_game = new Game();
	m_graphics = new Graphics();

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
	sysInitInfo.mCreateConsole = 0;
	sysInitInfo.mMaxFrameRate = m_refreshRate;
	sysInitInfo.mpWinCallBack = NULL;
	sysInitInfo.mClassStyle = CS_HREDRAW | CS_VREDRAW;
	sysInitInfo.mWindowStyle = WS_OVERLAPPEDWINDOW;
	sysInitInfo.mWindowHandle = NULL;
	sysInitInfo.mHandleWindowMessages = 1;

	// APPLY SYSTEM PROPERTIES
	AESysInit(&sysInitInfo);

	// SET WINDOW TITLE
	AESysSetWindowTitle("Weird Game Thing That We Made");

	// RESET SYSTEM MODULES
	AESysReset();

	// INITIALIZE FUNCTIONS
	Objects::Init(m_entityArray);

	m_graphics->Init(m_entityArray);
	m_game->Init(m_entityArray);

	OutputDebugStringA("Initialized!\n");

}

void Application::Loop(HINSTANCE instanceH) {

	m_deltaTime = clock() - m_oldTime;
	double fps = (1.0 / m_deltaTime) * 1000;
	m_oldTime = clock();

	std::string fpsStr = std::to_string(fps);

	OutputDebugStringA("FPS: ");
	OutputDebugStringA(fpsStr.c_str());
	OutputDebugStringA("\n");

	// INFORMING THE SYSTEM ABOUT THE LOOP'S START
	AESysFrameStart();

	// HANDLING INPUT
	AEInputUpdate();

	// GLOBAL INPUT
	// CHECK IF FORCING THE APPLICATION TO QUIT
	if(AEInputCheckTriggered(VK_ESCAPE) || !AESysDoesWindowExist()) {
		isRunning = false;
	}

	// RENDER/UPDATE FUNCTIONS
	Objects::Update(m_deltaTime);

	m_game->Update(m_deltaTime);
	m_graphics->Render(m_entityArray, m_deltaTime);

	// INFORMING THE SYSTEM ABOUT THE LOOP'S END
	AESysFrameEnd();

}

void Application::Uninit(HINSTANCE instanceH) {

	delete m_game;
	delete m_graphics;
	delete *m_entityArray;

	AESysExit();

}
