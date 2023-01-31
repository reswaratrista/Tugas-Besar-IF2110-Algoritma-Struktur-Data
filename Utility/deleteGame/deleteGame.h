#ifndef DELETEGAME_H
#define DELETEGAME_H

#include "../../ADT/queue/queue2.h"
#include "../../ADT/word/mesinkata/mesinkata.h"
#include "../../ADT/word/word.h"
#include "../listGame/listGame.h"
#include "../../Misc/io/io.h"
#include "../../Misc/ascii/ascii.h"
#include "../splash.h"
#include "../../ADT/map/listMap.h"
#include "../../ADT/set/listSet.h"

void deleteGame(List *L, Queue Q, List *listHist, ListMap *listMapGame, ListSet *listName);
// I.S.
// F.S. 
// Menghapus sebuah game dari daftar game
// Aturan penghapusan game :
// Game yang dapat dihapus hanya game yang dibuat secara custom oleh pengguna
// 5 game pertama pada file konfigurasi tidak dapat dihapus
// Game yang saat itu terdapat di dalam queue game tidak dapat dihapus

// ENTER COMMAND: DELETE GAME
// Berikut adalah daftar game yang tersedia
//      1. RNG
//      2. LUNCH SLOW
//      3. DINASOUR IN EARTH
//      4. RISEWOMAN
//      5. EIFFEL TOWER
//      6. CUSTOM GAME 1
// Masukkan nomor game yang akan dihapus: 6
//
// Game berhasil dihapus

// ex lain
// Masukkan nomor game yang akan dihapus: 1
//
// Game gagal dihapus

#endif