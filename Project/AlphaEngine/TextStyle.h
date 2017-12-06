#ifndef TEXTSTYLE_H
#define TEXTSTYLE_H

// DEFINE CONSOLE TEXT COLORS
/*
#define TSC_L_BLACK "\x1b[30m\033[47m"
#define TSC_L_RED "\x1b[31m\033[47m"
#define TSC_L_GREEN "\x1b[32m\033[47m"
#define TSC_L_YELLOW "\x1b[33m\033[47m"
#define TSC_L_BLUE "\x1b[34m\033[47m"
#define TSC_L_MAGENTA "\x1b[35m\033[47m"
#define TSC_L_CYAN "\x1b[36m\033[47m"
#define TSC_L_WHITE "\x1b[37m\033[47m"
#define TSC_L_NORMAL "\x1b[0m\033[47m"
*/

#define TSC_BLACK "\x1b[30m"
#define TSC_RED "\x1b[31m"
#define TSC_GREEN "\x1b[32m"
#define TSC_YELLOW "\x1b[33m"
#define TSC_BLUE "\x1b[34m"
#define TSC_MAGENTA "\x1b[35m"
#define TSC_CYAN "\x1b[36m"
#define TSC_WHITE "\x1b[37m"
#define TSC_NORMAL "\x1b[0m"

// DEFINE HIGHLIGHT COLORS
#define TSC_BGBLACK "\033[40m"
#define TSC_BGRED "\033[41m"
#define TSC_BGGREEN "\033[42m"
#define TSC_BGYELLOW "\033[43m"
#define TSC_BGBLUE "\033[44m"
#define TSC_BGMAGENTA "\033[45m"
#define TSC_BGCYAN "\033[46m"
#define TSC_BGWHITE "\033[47m"

// TIMESTAMP HIGHLIGHT
#define TSC_TIMESTAMP "\033[37m\033[1m"
#define TSC_INFO "\x1b[36m\033[1m"
#define TSC_DEBUG "\x1b[32m\033[1m"
#define TSC_WARNING "\x1b[33m\033[1m"
#define TSC_ERROR "\x1b[31m\033[1m"
#define TSC_VALUE "\x1b[35m\033[1m"

// DEFINE TEXT STYLE
#define TSC_BOLD "\033[3m"
#define TSC_UNDERLINE "\033[4m"
#define TSC_BLINK "\033[5m"

// SHOW/HIDE CURSOR
#define TSC_SHOWCURSOR "\033[?25h"
#define TSC_HIDECURSOR "\033[?25l"

#endif