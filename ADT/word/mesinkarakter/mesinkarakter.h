/* FILE         : mesinkar.h */
/* DESKRIPSI    : Header ADT Mesin Karakter */

#ifndef __MESINKAR__
#define __MESINKAR__

#include "../../boolean.h"

#define INPUTMARK '\n'

extern char cc; // Current Character

extern boolean isFile; // Bernilai true jika input merupakan file; false jika input merupakan stdin
extern boolean eoi; // End of Input

/* Memulai mesin karakter. Apabila fileInput bernilai true, mesin karakter akan membaca dari file; apabila false, dari stdin. Kosongkan filename apabila input dari stdin. */
void start(boolean fileInput, char *filename);

/* Memajukan mesin karakter */
void adv();

#endif