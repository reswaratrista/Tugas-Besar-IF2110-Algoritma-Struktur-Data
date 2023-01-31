#ifndef __CREATE_GAME_H__
#define __CREATE_GAME_H__

#include "../../ADT/list/array.h"
#include "../../ADT/word/mesinkarakter/mesinkarakter.h"
#include "../../ADT/word/word.h"
#include "../../Misc/io/io.h"
#include "../../ADT/boolean.h"
#include "../../ADT/queue/queue2.h"
#include "../../ADT/word/mesinkata/mesinkata.h"
#include "../listGame/listGame.h"
#include "../../Misc/io/io.h"
#include "../../Misc/ascii/ascii.h"
#include "../../ADT/map/map.h"
#include "../../ADT/map/listMap.h"
#include "../../ADT/set/listSet.h"
#include "../splash.h"


void createGame(List *L, ListMap *LM, ListSet *LS);
// I.S. List game tidak kosong
// F.S. Jika input tidak NULL, menambahkan game baru dalam di akhir list game
// Jika input NULL, gagal menambahkan game baru

// Contoh input:
// ENTER COMMAND : CREATE GAME
// Masukkan nama game yang akan ditambahkan: EXTRA1
// Game berhasil ditambahkan

#endif