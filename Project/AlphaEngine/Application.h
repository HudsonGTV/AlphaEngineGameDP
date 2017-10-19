#ifndef APPLICATION_H
#define APPLICATION_H

#include "AEEngine.h"

#include <stdbool.h>

#ifdef _DEBUG
#pragma comment (lib, "Alpha_Engine_D.lib")
#else
#pragma comment (lib, "Alpha_Engine.lib")
#endif

class Application {

	int m_windowWidth = 800;
	int m_windowHeight = 600;
	
public:

	int isRunning = true;

	Application();

	void Init(HINSTANCE instanceH, int show);
	void Render(HINSTANCE instanceH);

};

#endif