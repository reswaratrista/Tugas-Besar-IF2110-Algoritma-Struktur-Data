/* File         : mesinkata.h */
/* Deskripsi    : Header ADT Mesin Kata */

#ifndef __MESINKATA__
#define __MESINKATA__

#include "../mesinkarakter/mesinkarakter.h"
#include "../word.h"

#define FILEBLANK '\n'
#define INPUTBLANK ' '

extern boolean endKata;
extern Word currentKata;

void ignoreBlank();

/* Memulai mesin kata. Apabila fileInput bernilai true, mesin kata akan membaca dari file; apabila false, dari stdin. Kosongkan filename apabila input dari stdin. */
void startKata(boolean fileInput, char *filename);

void advKata();

void salinKata();

#endif