/* File         : io.h */
/* Deskripsi    : Header Library I/O */

/* Digunakan untuk melakukan input dengan verifikasi */

#ifndef __IO__
#define __IO__

#include "../../ADT/boolean.h"
#include "../../ADT/word/word.h"
#include "../../ADT/list/array.h"

#define EMPTY_INPUT -1
#define INVALID_INPUT 0
#define VALID_INPUT 1

/* Meminta user untuk menginput satu buah kata dengan panjang minimal min dan panjang maksimal max, lalu menyimpannya di w. Kata dianggap berakhir ketika bertemu dengan karakter newline. Apabila input kurang dari min/lebih dari max, akan mengembalikan INVALID_INPUT. */
int wordInput(Word *w, int min, int max);

/* Meminta user untuk menginput beberapa kata dengan banyak minimal min dan banyak maksimal max, lalu menyimpannya di array of kata input. Input dianggap berakhir ketika bertemu dengan karakter newline, dan kata dipisahkan berdasarkan spasi. Apabila input kurang dari min/lebih dari max, akan mengembalikan INVALID_INPUT. */
int multiWordInput(List *input, int min, int max);

void blankInput();

#endif