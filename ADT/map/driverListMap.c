#include <stdio.h>
#include "listMap.h"


int main()
{
    Map M1, M2;
    CreateEmptyMap(&M1);
    CreateEmptyMap(&M2);

    ListMap L;
    createListMap(&L);
    insertListMap(&L, M1);
    insertListMap(&L, M2);

    Set S1, S2;
    CreateEmptySet(&S1);
    CreateEmptySet(&S2);

    ListSet S;
    createListSet(&S);
    insertListSet(&S, S1);
    insertListSet(&S, S2);

    inputDataListMap(&L, &S, 0, 10);
    inputDataListMap(&L, &S, 1, 20);

    List Game;
    createList(&Game);
    insertLast(&Game, stringToWord("Game1"));
    insertLast(&Game, stringToWord("Game2"));

    displayListMap(L, Game);

    return 0;
}

//compile : gcc src/ADT/set/set.c src/ADT/set/listSet.c src/ADT/list/array.c src/ADT/map/map.c src/ADT/map/driverListMap.c src/ADT/map/listMap.c src/ADT/word/mesinkata/mesinkata.c src/ADT/word/mesinkarakter/mesinkarakter.c src/ADT/word/word.c src/Misc/ascii/ascii.c src/Misc/io/io.c -o driver