#include <stdbool.h>

#include "AEEngine.h"
#include "Application.h"

static Application *app;

int WINAPI WinMain(HINSTANCE instanceH, HINSTANCE prevInstanceH, LPSTR command_line, int show) {

	UNREFERENCED_PARAMETER(prevInstanceH);
	UNREFERENCED_PARAMETER(command_line);

	app = new Application(800, 600, 144);

	// INITIALIZE
	app->Init(instanceH, show);

	// RENDER LOOP
	while(app->isRunning) {
		app->Loop(instanceH);
	}

	// UNINITIALIZE
	app->Uninit(instanceH);

	return 0;

}