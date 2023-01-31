#ifndef HISTORY_H
#define HISTORY_H

#include <stdio.h>
#include "../../ADT/list/array.h"
#include "../../ADT/word/mesinkata/mesinkata.h"
#include "../../ADT/word/word.h"
#include "../../ADT/queue/queue2.h"
#include "../listGame/listGame.h"
#include "../../Misc/io/io.h"
#include "../../Misc/ascii/ascii.h"
#include "../splash.h"

void history(List listHist, int num);
void resetHist(List *listHist);

#endif
