/* FILE         : ascii.h */
/* DESKRIPSI    : Header library ASCII buatan gweh */

#ifndef __ASCII__
#define __ASCII__

#include "../../ADT/boolean.h"

#define INVALID 0xDEADBEEF

/* Mengembalikan karakter pada indeks ASCII ke-i */
char chr(int i);

/* Mengembalikan indeks ASCII dari suatu karakter */
int ord(char c);

/* Mengembalikan indeks karakter dalam alfabet, dengan a = 0; apabila bukan alfabet, akan mengembalikan INVALID */
int alphabeticalOrd(char c);

/* Mengembalikan huruf kecil dari suatu karakter apabila karakter merupakan huruf kapital */
char lower(char c);

/* Mengembalikan huruf kapital dari suatu karakter apabila karakter merupakan huruf kecil */
char upper(char c);

/* Mengecek apakah sebuah karakter merupakan huruf kecil */
boolean isLowercase(char c);

/* Mengecek apakah sebuah karakter merupakan huruf besar */
boolean isUppercase(char c);

/* Mengecek apakah sebuah karakter merupakan alfabet */
boolean isAlpha(char c);

/* Mengecek apakah sebuah karakter merupakan angka */
boolean isNumeric(char c);

/* Mengecek apakah sebuah karakter merupakan karakter dalam indeks ASCII [min...max] */
boolean isCharInRange(char c, int min, int max);

/* Merubah sebuah karakter menjadi sebuah integer; apabila invalid, akan mengembalikan INVALID */
int charToInt(char c);

/* Mengubah sebuah integer antara 0-9 menjadi sebuah karakter; apabila karakter lebih dari 9, akan diambil digit paling kanan; apabila < 0, tanda negatif akan diabaikan */
char intToChar(int i);

#endif