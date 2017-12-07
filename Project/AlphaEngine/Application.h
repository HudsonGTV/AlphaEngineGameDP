#ifndef APPLICATION_H
#define APPLICATION_H

#include "AEEngine.h"
#include "Entity.h"
#include "GraphicsEngine.h"
#include "GameEngine.h"
#include "PhysicsEngine.h"

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

	double m_oldTime = 0.0;
	double m_newTime = 0.0;
	double m_deltaTime = 0.0;

	Game *m_game;
	PhysicsEngine *m_physics;
	GraphicsEngine *m_graphics;

	std::vector<Entity *> m_entityList;
	
public:
	int isRunning = true;

	Application(int winWidth, int winHeight, int refreshRate = 60);

	void Init(HINSTANCE instanceH, int show);
	void Loop(HINSTANCE instanceH);
	void Uninit(HINSTANCE instanceH);

	void GlobalInputManager(double dt);

};

#endif
