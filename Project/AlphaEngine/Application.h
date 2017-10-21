#ifndef APPLICATION_H
#define APPLICATION_H

#include "GraphicsEngine.h"
#include "GameEngine.h"
#include "Entity.h"
#include "AEEngine.h"
#include "ObjectManager.h"

#include <stdbool.h>

#ifdef _DEBUG
#pragma comment (lib, "Alpha_Engine_D.lib")
#else
#pragma comment (lib, "Alpha_Engine.lib")
#endif

class Application {

private:
	int m_windowWidth = 800;
	int m_windowHeight = 600;
	int m_refreshRate = 144;

	bool m_isRunning = true;

	Graphics *m_graphics;
	Game *m_game;

	Entity *m_entityArray[ENTITY_COUNT];
	
public:
	int isRunning = true;

	Application(int winWidth, int winHeight, int refreshRate = 60);

	void Init(HINSTANCE instanceH, int show);
	void Loop(HINSTANCE instanceH);
	void Uninit(HINSTANCE instanceH);

};

#endif