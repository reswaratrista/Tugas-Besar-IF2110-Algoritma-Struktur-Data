/* File: createGame.h */
/* Menggunakan ADT array */

#ifndef SAVE_H
#define SAVE_H

/* ADT lain yang dipakai */
#include "../../ADT/list/array.h"
#include "../../ADT/word/word.h"
#include "../../Misc/io/io.h"
#include "../../ADT/map/listMap.h"

void savetoFile(char saveFilename[], List L, List listHist, ListMap listMapGame);
// I.S. saveFilename terdefinisi, L terdefinisi
// F.S. Menyimpan state game pemain yang ada di List L ke file bernama saveFilename


#endif