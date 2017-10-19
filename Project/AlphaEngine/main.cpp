/******************************************************************************/
/*!
 \file   Step1 - Empty.c
 \author Antoine Abi Chacra
 \par    Course: GAM150
 \par    Copyright © 2016 DigiPen (USA) Corporation.
 \brief
 */
/******************************************************************************/

#include <stdbool.h>

#include "AEEngine.h"
#include "Application.h"

static Application *app;

int WINAPI WinMain(HINSTANCE instanceH, HINSTANCE prevInstanceH, LPSTR command_line, int show) {

	UNREFERENCED_PARAMETER(prevInstanceH);
	UNREFERENCED_PARAMETER(command_line);

	app = new Application();

	app->Init(instanceH, show);

	while(app->isRunning) {
		app->Render(instanceH);
	}



	return 1;

}