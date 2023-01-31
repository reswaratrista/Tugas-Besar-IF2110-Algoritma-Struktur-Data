#ifndef __HANGMAN__
#define __HANGMAN__

#include "man.h"
#include "../../ADT/boolean.h"
#include "../../ADT/list/array.h"
#include "../../ADT/word/mesinkata/mesinkata.h"
#include "../../ADT/word/word.h"
#include "../../Misc/ascii/ascii.h"
#include "../../Misc/io/io.h"
#include "../../Utility/splash.h"
#include "../random.h"
#include "../../ADT/map/listMap.h"

void inputGuess(List Guesses, Word *guess);
// I.S. Guesses terdefinisi, guess terdefinisi
// F.S. guess terisi dengan input pengguna, jika input user ada di List Guesses, maka akan meminta input lagi

void man(int chance);
// I.S. chance terdefinisi
// F.S. Menampilkan gambar hangman sesuai dengan chance yang dimiliki

void toContinue();
// I.S. Sembarang
// F.S. Menampilkan pesan tekan enter untuk melanjutkan permainan

void displayKata(List L);
// I.S. L terdefinisi
// F.S. Menampilkan isi List L

Word randomWord(List L);
// I.S. L terdefinisi
// F.S. Mengembalikan kata random dari List L

void readListKata(List *ListKata);
// I.S. Membaca isi file listkata.txt
// F.S. ListKata terisi dengan kata-kata dari file listKata.txt

void addToListKata(List *L);
// I.S. L terdefinisi
// F.S. Menambah kata baru ke List L

void saveListKata(List L);
// I.S. L terdefinisi
// F.S. Menyimpan List L ke file listkata.txt

void playHangman(List L, ListMap *M, ListSet *S);
// I.S. L terdefinisi
// F.S. Memainkan game hangman

void hangman(ListMap *M, ListSet *S);
// I.S. Sembarang
// F.S. Menunjukkan pilihan main game hangman atau menambah kata

void hangmanSplash();

#endif