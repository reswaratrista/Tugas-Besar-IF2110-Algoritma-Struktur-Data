#include "mesinkata.h"
#include "../word.h"
#include <stdio.h>

int main() {

    startKata(false,"");

    while (!endKata) {
        printWord(currentKata);
        printf("\n");
        advKata();
    }

    startKata(true,"src/ADT/word/mesinkata/test.txt");

    while (!endKata) {
        printWord(currentKata);
        printf("\n");
        advKata();
    }

}

// compile : gcc src/ADT/word/mesinkata/driverMesinKata.c src/ADT/word/mesinkata/mesinkata.c src/ADT/word/mesinkarakter/mesinkarakter.c src/ADT/word/word.c src/Misc/ascii/ascii.c -o driver