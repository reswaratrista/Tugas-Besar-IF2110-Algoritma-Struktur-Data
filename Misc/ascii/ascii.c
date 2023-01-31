/* FILE         : ascii.h */
/* DESKRIPSI    : Implementasi library ASCII buatan gweh */

#include "ascii.h"

/* Mengembalikan karakter pada indeks ASCII ke-i */
char chr(int i) {
    
    char c = i;
    return c;

}

/* Mengembalikan indeks ASCII dari suatu karakter */
int ord(char c) {

    int i = c;
    return i;

}

/* Mengembalikan indeks karakter dalam alfabet, dengan a = 0; apabila bukan alfabet, akan mengembalikan INVALID */
int alphabeticalOrd(char c) {

    c = upper(c);
    int i;

    if (isAlpha(c)) {
        i = c - 65;
    } else {
        i = INVALID;
    }

    return i;

}

/* Mengembalikan huruf kecil dari suatu karakter apabila karakter merupakan huruf kapital */
char lower(char c) {

    if (isUppercase(c)) {
        return (c + 32);
    } else {
        return (c);
    }

}

/* Mengembalikan huruf kapital dari suatu karakter apabila karakter merupakan huruf kecil */
char upper(char c) {

    if (isLowercase(c)) {
        return (c - 32);
    } else {
        return (c);
    }

}

/* Mengecek apakah sebuah karakter merupakan huruf kecil */
boolean isLowercase(char c) {

    return (isCharInRange(c,ord('a'),ord('z')));

}

/* Mengecek apakah sebuah karakter merupakan huruf besar */
boolean isUppercase(char c) {

    return (isCharInRange(c,ord('A'),ord('Z')));

}

/* Mengecek apakah sebuah karakter merupakan alfabet */
boolean isAlpha(char c) {

    c = lower(c);
    return (isCharInRange(c,ord('a'),ord('z')));

}

/* Mengecek apakah sebuah karakter merupakan angka */
boolean isNumeric(char c) {

    return (isCharInRange(c,ord('0'),ord('9')));

}

/* Mengecek apakah sebuah karakter merupakan karakter dalam indeks ASCII [min...max] */
boolean isCharInRange(char c, int min, int max) {

    return ((c >= min) && (c <= max));

}

/* Merubah sebuah karakter menjadi sebuah integer; apabila invalid, akan mengembalikan INVALID */
int charToInt(char c) {

    int i;

    if (isNumeric(c)) {
        i = c - 48;
    } else {
        i = INVALID;
    }
    return i;
}

/* Mengubah sebuah integer antara 0-9 menjadi sebuah karakter; apabila integer lebih dari 9 atau kurang dari 0, akan dikembalikan integer % 10 */
char intToChar(int i) {

    i = i % 10;

    char c = i + 48;

    return c;

}