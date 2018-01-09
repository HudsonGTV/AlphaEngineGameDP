#ifndef CONSOLEIO_H
#define CONSOLEIO_H

#include "out.h"

bool IsConsoleInForeground();
bool IsConsoleKeyDown();
bool ConsoleAsyncKeyIsDown(int vKey);
bool ConsoleAsyncKeyIsPressed(int vKey);

#endif
