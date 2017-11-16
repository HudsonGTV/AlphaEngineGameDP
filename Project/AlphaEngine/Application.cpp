#include <time.h>

#include "Application.h"
#include "consoleio.h"

Application::Application(int winWidth, int winHeight, int refreshRate) {

	// SET PASSED IN WINDOW PROPERTIES ARGUMENTS
	m_windowWidth = winWidth;
	m_windowHeight = winHeight;
	m_refreshRate = refreshRate;

	// CORE CLASS DECLARATIONS
	m_game = new Game();
	m_physics = new PhysicsEngine();
	m_graphics = new GraphicsEngine();

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
	sysInitInfo.mCreateConsole = 1;
	sysInitInfo.mMaxFrameRate = m_refreshRate;
	sysInitInfo.mpWinCallBack = NULL;
	sysInitInfo.mClassStyle = CS_HREDRAW | CS_VREDRAW;
	sysInitInfo.mWindowStyle = WS_OVERLAPPEDWINDOW;
	sysInitInfo.mWindowHandle = NULL /*hwnd*/;
	sysInitInfo.mHandleWindowMessages = 1;

	// APPLY SYSTEM PROPERTIES
	AESysInit(&sysInitInfo);

	// SET WINDOW TITLE
	AESysSetWindowTitle("Potato Man");
	
	// RESET SYSTEM MODULES
	AESysReset();

	// INITIALIZE FUNCTIONS
	m_graphics->Init(&m_entityID);
	m_physics->Init(&m_entityID);
	m_game->Init(&m_entityID);
	
	OutputDebugStringA("Initialized!\n");

	// LET USER KNOW THAT THEY MUST HAVE A VERY HIGH IQ TO UNDERSTAND FOO AND BARTY
	AESysPrintf("\nTo be fair, you have to have a very high IQ to understand Foo and Barty. The humour is extremely subtle, and without a \nsolid grasp of theoretical potatos most of the jokes will go over a typical viewer\'s head. There\'s also Foo\'s \nnihilistic outlook, which is deftly woven into his characterisation- his personal philosophy draws heavily from \nFoodnaya Volya literature, for instance. The fans understand this stuff; they have the intellectual capacity to truly \nappreciate the depths of these jokes, to realise that they're not just funny- they say something deep about LIFE. As a \nconsequence people who dislike Foo & Barty truly ARE idiots- of course they wouldn't appreciate, for instance, the \nhumour in Foo's existential catchphrase \"ReadAccessViolation,\" which itself is a cryptic reference to Turgenev's \nRussian epic Stacks and Overflows. I'm smirking right now just imagining one of those addlepated simpletons scratching \ntheir heads in confusion as Null Pointer's genius wit unfolds itself on their television screens. What fools.. how I \npity them. :D\n\nAnd yes, by the way, i DO have a Foo & Barty tattoo. And no, you cannot see it. It's for the ladies' eyes only - and \neven then they have to demonstrate that they're within 5 IQ points of my own (preferably lower) beforehand. Nothin \npersonnel kid ]-)\n\n\n");
	
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
	m_game->Update(&m_entityID, m_deltaTime);
	m_physics->Update(m_deltaTime);
	m_graphics->Render(&m_entityID, m_deltaTime);

	// INFORMING THE SYSTEM ABOUT THE LOOP'S END
	AESysFrameEnd();

}

void Application::Uninit(HINSTANCE instanceH) {

	// UNINIT
	m_graphics->Uninit();

	// DELETE UNLOADED CLASSES
	delete m_game;
	delete m_graphics;

	AESysExit();

}
