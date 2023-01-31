/* File: listGame.h */
/* Menggunakan ADT array */

#ifndef LISTGAME_H
#define LISTGAME_H

/* ADT lain yang dipakai */
#include "../../ADT/list/array.h"
#include "../../Misc/io/io.h"
#include "../splash.h"

void listGame(List L);
// I.S. List L terdefinisi
// F.S. Jika List kosong menampilkan pesan list kosong
// Jika List tidak kosong, menampilkan daftar game yang disediakan oleh sistem
void listGameMain(List L);

#endif