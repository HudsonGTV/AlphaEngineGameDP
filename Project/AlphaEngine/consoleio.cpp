#include "consoleio.h"

static bool keyIsDown = true;

bool IsConsoleInForeground() {
	bool isConsoleWindowFocused = (GetConsoleWindow() == GetForegroundWindow());
	return isConsoleWindowFocused;
}

bool IsConsoleKeyDown() {
	return keyIsDown;
}

bool ConsoleAsyncKeyIsDown(int vKey) {

	if(IsConsoleInForeground()) {
		if(GetAsyncKeyState(vKey)) {
			keyIsDown = true;
			return true;
		}
	}

	keyIsDown = false;

	return false;

}

bool ConsoleAsyncKeyIsPressed(int vKey) {

	if(IsConsoleInForeground() && !AEInputCheckTriggered(vKey)) {
		if(!keyIsDown && GetAsyncKeyState(vKey) & 0x8000) {
			keyIsDown = true;
			return true;
		} else if(keyIsDown && !GetAsyncKeyState(vKey) == 0 && AEInputCheckTriggered(vKey)) {
			keyIsDown = false;
			return false;
		}
	} else {
		return false;
	}

}
