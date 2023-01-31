/* File         : mesinkata.c */
/* Deskripsi    : Implementasi ADT Mesin Kata */

#include <stdio.h>
#include "mesinkata.h"

boolean endKata;
Word currentKata;

void ignoreBlank() {

    while ((cc == INPUTBLANK && !isFile) || (cc == FILEBLANK && isFile)) {
        adv();
    }

}

void startKata(boolean fileInput, char *filename) {

    endKata = false;
    start(fileInput, filename);
    ignoreBlank();

    if (eoi) {
        endKata = true;
    } else {
        salinKata();
    }

}

void advKata() {

    ignoreBlank();

    if (eoi) {
        endKata = true;
    } else {
        salinKata();
    }

}

void salinKata() {

    int i = 0;

    while (!eoi && ((isFile && cc != FILEBLANK) || (!isFile && cc != INPUTBLANK))) {
        if (i < N_MAX) {
            currentKata.buffer[i] = cc;
            i = i + 1;
        }
        adv();
    }

    currentKata.length = i;

}