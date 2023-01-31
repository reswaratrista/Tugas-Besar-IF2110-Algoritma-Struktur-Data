/* File         : colors.h */
/* Deskripsi    : Definisi-definisi warna output */

#include <stdio.h>

#ifndef __COLORS__
#define __COLORS__

#define BLACK    "\x1b[30m"
#define RED      "\x1b[31m"
#define GREEN    "\x1b[32m"
#define YELLOW   "\x1b[33m"
#define BLUE     "\x1b[34m"
#define PURPLE   "\x1b[35m"
#define CYAN     "\x1b[36m"
#define WHITE    "\x1b[37m"

#define B_BLACK  "\x1b[90m"
#define B_RED    "\x1b[91m"
#define B_GREEN  "\x1b[92m"
#define B_YELLOW "\x1b[93m"
#define B_BLUE   "\x1b[94m"
#define B_PURPLE "\x1b[95m"
#define B_CYAN   "\x1b[96m"
#define B_WHITE  "\x1b[97m"

#define BG_BLACK  "\x1b[40m"
#define BG_RED    "\x1b[41m"
#define BG_GREEN  "\x1b[42m"
#define BG_YELLOW "\x1b[43m"
#define BG_BLUE   "\x1b[44m"
#define BG_PURPLE "\x1b[45m"
#define BG_CYAN   "\x1b[46m"
#define BG_WHITE  "\x1b[47m"

#define RESET    "\x1b[0m"

#endif