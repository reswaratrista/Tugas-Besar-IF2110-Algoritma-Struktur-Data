#include <stdio.h>

#include "../../ADT/boolean.h"
#include "../../ADT/list/array.h"
#include "../../ADT/word/word.h"
#include "../../ADT/word/mesinkata/mesinkata.h"

void START(List *ListGame){

    startKata(true,"Config/config.txt");
    advKata();

    while (!endKata) {
        insertLast(ListGame,currentKata);
        advKata();
    }

}
