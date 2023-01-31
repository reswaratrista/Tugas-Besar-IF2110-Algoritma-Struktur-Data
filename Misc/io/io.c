/* File         : io.c */
/* Deskripsi    : Implementasi mesin karakter-kata untuk input/output + stringops */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "io.h"
#include "../../ADT/list/array.h"
#include "../../ADT/word/word.h"
#include "../../ADT/word/mesinkata/mesinkata.h"

int wordInput(Word *w, int min, int max) {

    createWord(w);

    start(false,"");

    int i = 0;
    while (!eoi) {
        if (i < N_MAX && i < max) {
            w->buffer[i] = cc;
        }
        i = i + 1;
        adv();
    }

    if (i < min || i > max || i > N_MAX) {
        if (i <= N_MAX) {
            wordLength(*w) = i; 
        } else {
            wordLength(*w) = N_MAX;
        }
        return INVALID_INPUT;
    } else {
        wordLength(*w) = i; 
        return VALID_INPUT;
    }

}

int multiWordInput(List *input, int min, int max) {

    startKata(false,"");

    int i = 0;
    while (!endKata) {
        insertAt(input,currentKata,i);
        advKata();
        i = i + 1;
    }

    if (length(*input) < min || length(*input) > max) {
        return INVALID_INPUT;
    } else {
        return VALID_INPUT;
    }

}

void blankInput() {

    startKata(false,"");

    while (!endKata) {
        advKata();
    }

}

/*
int main() {

    Word WordInput;

    boolean Valid = wordInput(&WordInput,1,5); 
    // input pake mesinkar, berhenti pas ketemu newline (enter), hasil disimpen di satu kata
    // minimal input 1 karakter, maksimal 5; lebih ato kurang bakal balikin 0 (false)
    // kalo bener (sesuai min sama max) bakal balikin 1 (true)

    if (Valid) {
        // ngapain
    } else {
        // ngapain
    }

    List Input;
    createList(&Input);

    Valid = multiWordInput(&Input,1,2);
    // input pake mesinkata, berhenti pas ketemu newline (enter), hasil disimpen di array of kata
    // kata dipisah berdasarkan spasi
    // minimal input 1 kata, maksimal 2; lebih ato kurang bakal balikin 0 (false)
    // kalo bener (sesuai min sama max) bakal balikin 1 (true)

    if (Valid) {
        // ngapain
    } else {
        // ngapain
    }

    // contoh dalem while
    Valid = false;
    while (!Valid) {
        Valid = multiWordInput(&Input,1,2);
        if (Valid) {
            // CONTOH: BANDING COMMAND
            if (length(Input) == 1 && isWordEqual(getElmt(Input,0),stringToWord("SERVE"))) {
                // ngapain
            } else { // input salah
                Valid = false; // intinya set variabel yang ngatur loop ke false biar ngulang lagi
                // ngapain
            }
        } else {
            // ngapain
        }
    }

}

*/