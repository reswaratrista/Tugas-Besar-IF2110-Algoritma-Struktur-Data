#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <stdio.h>
#include "../../ADT/map/map.h"
#include "../../ADT/set/set.h"
#include "../../ADT/word/mesinkata/mesinkata.h"
#include "../../ADT/word/word.h"
#include "../listGame/listGame.h"
#include "../../Misc/io/io.h"
#include "../../Misc/ascii/ascii.h"
#include "../../ADT/map/listMap.h"
#include "../../ADT/set/listSet.h"

void addMap(ListMap *M, List listGame);
// bikin map baru waktu command start buat tiap game di list game

void addSet(ListSet *S, List listGame);
// bikin set baru waktu command start buat tiap game di list game

void scoreboard(ListMap *M, List L);
// display scoreboard

void resetScoreboard(ListMap *M, ListSet *S, List listGame);

#endif

