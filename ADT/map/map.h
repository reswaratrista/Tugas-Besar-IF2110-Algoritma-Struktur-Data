#ifndef map_H
#define map_H
#include <stdio.h>
#include "../boolean.h"
#include "../word/mesinkata/mesinkata.h"
#include "../../Misc/io/io.h"
#include "../../Misc/ascii/ascii.h"
#include "../set/listSet.h"

/* MODUL Map
Deklarasi map yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
#define Nil 0
#define InitialSize 10
#define Undefined -999

#define keytype Word

typedef int address;
typedef int valuetype;

typedef struct {
	keytype name;
	valuetype score;
} infotype;

typedef struct {
	infotype *Elements;
	address Count;
	int CapacityMap;
} Map;

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Map *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

void deallocateMap(Map *M);

void updateCapacityMap(Map *M);

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Map M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFullMap(Map M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertMap(Map *M, keytype k, valuetype v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteMap(Map *M, keytype k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberMap(Map M, keytype k);
/* Mengembalikan true jika k adalah member dari M */

void PrintMap(Map M, Word GameName);
// void inputName(Map *M);
// Di setiap keadaan game over atau menang sebuah game, program meminta nama pemain. 
// Nama pemain yang valid adalah nama yang belum terpakai di scoreboard game yang sedang dimainkan. Kemudian program menyimpan nama dan skor game tersebut di ADT Map.

void inputData(Map *M, Set *S, int score);

void sortMap(Map *M);

#endif