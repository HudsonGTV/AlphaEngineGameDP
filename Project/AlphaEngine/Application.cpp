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

	// REGISTER WINDOW CLASS
	/*WNDCLASSEX winClass;
	winClass.cbSize = sizeof(WNDCLASSEX);
	winClass.style = 0;
	winClass.cbClsExtra = 0;
	winClass.cbWndExtra = 0;
	winClass.hInstance = instanceH;
	winClass.hIcon = LoadIcon(instanceH, IDI_APPLICATION);
	winClass.hCursor = LoadCursor(instanceH, IDC_ARROW);
	winClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	winClass.lpszMenuName = NULL;
	winClass.lpszClassName = "appWCDGame";
	winClass.hIconSm = LoadIcon(instanceH, IDI_APPLICATION);

	HWND hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		"appWCDGame",
		"Title",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 640, 480,
		NULL, NULL, instanceH, NULL
	);*/

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
	sysInitInfo.mWindowHandle = NULL /*hwnd*/;
	sysInitInfo.mHandleWindowMessages = 1;

	// APPLY SYSTEM PROPERTIES
	AESysInit(&sysInitInfo);

	// SET WINDOW TITLE
	AESysSetWindowTitle("Weird Game Thing That We Made");
	
	// RESET SYSTEM MODULES
	AESysReset();

	// INITIALIZE FUNCTIONS
	m_graphics->Init(m_entityID);
	m_game->Init(m_entityID);
	
	OutputDebugStringA("Initialized!\n");

}

void Application::Loop(HINSTANCE instanceH) {

	// DELTA TIME AND FPS STUFF
	m_deltaTime = clock() - m_oldTime;
	m_oldTime = clock();

	double fps = (1.0 / m_deltaTime) * 1000;

	// OUTPUT FPS
	OutputDebugStringA("FPS: ");
	OutputDebugStringA(std::to_string(fps).c_str());
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
	m_game->Update(m_deltaTime);
	m_graphics->Render(m_entityID, m_deltaTime);

	// INFORMING THE SYSTEM ABOUT THE LOOP'S END
	AESysFrameEnd();

}

void Application::Uninit(HINSTANCE instanceH) {

	// UNINIT
	m_graphics->Uninit();

	// DELETE UNLOADED CLASSES
	delete m_game;
	delete m_graphics;
	delete m_entityID[ID_PLAYER];
	delete m_entityID[ID_BOSS];
	delete m_entityID[ID_BULLET];

	AESysExit();

}
