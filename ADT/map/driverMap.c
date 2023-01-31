#include <stdio.h>
#include "map.h"

int main()
{
    Set S;
    Map M;
    CreateEmptyMap(&M);
    if (IsEmptyMap(M)){
        printf("Map kosong\n");
    } else {
        printf("Map tidak kosong\n");
    }
    keytype test, test1;
    test = stringToWord("hai");
    test1 = stringToWord("halo");
    valuetype testInfo, test1Info;
    testInfo = 10;
    test1Info = 20;
    InsertMap(&M, test, testInfo);
    InsertMap(&M, test1, test1Info);
    PrintMap(M, stringToWord("MAP-1"));
    DeleteMap(&M, test);
    PrintMap(M, stringToWord("MAP-NEW"));
    printf("%d\n", Value(M, test1));
    inputData(&M, &S, testInfo);
    PrintMap(M, stringToWord("NEW"));
    return 0;
}

// compile : gcc src/ADT/set/set.c src/ADT/set/listSet.c src/ADT/list/array.c src/ADT/map/driverMap.c src/ADT/map/map.c src/ADT/word/mesinkata/mesinkata.c src/ADT/word/mesinkarakter/mesinkarakter.c src/ADT/word/word.c src/Misc/ascii/ascii.c src/Misc/io/io.c -o driver