#ifndef TEXTSTYLE_H
#define TEXTSTYLE_H

// DEFINE CONSOLE TEXT COLORS
#define L_BLACK "\x1b[30m\033[47m"
#define L_RED "\x1b[31m\033[47m"
#define L_GREEN "\x1b[32m\033[47m"
#define L_YELLOW "\x1b[33m\033[47m"
#define L_BLUE "\x1b[34m\033[47m"
#define L_MAGENTA "\x1b[35m\033[47m"
#define L_CYAN "\x1b[36m\033[47m"
#define L_WHITE "\x1b[37m\033[47m"
#define L_NORMAL "\x1b[0m\033[47m"

#define BLACK "\x1b[30m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
#define NORMAL "\x1b[0m"
#define TITLECOLOR "\x1b[30m"
#define CLOSEBUTTON "\x1b[31m"

// DEFINE HIGHLIGHT COLORS
#define BGBLACK "\033[40m"
#define BGRED "\033[41m"
#define BGGREEN "\033[42m"
#define BGYELLOW "\033[43m"
#define BGBLUE "\033[44m"
#define BGMAGENTA "\033[45m"
#define BGCYAN "\033[46m"
#define BGWHITE "\033[47m"

// ERROR HIGHLIGHT
#define HERROR "\033[37m\033[1m\033[41m"

// DEFINE TEXT STYLE
#define BOLD "\033[3m"
#define UNDERLINE "\033[4m"
#define BLINK "\033[5m"

// SHOW/HIDE CURSOR
#define SHOWCURSOR "\033[?25h"
#define HIDECURSOR "\033[?25l"

#endif