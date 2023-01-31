#include <stdio.h>
#include "scoreboard.h"

void addMap(ListMap *M, List listGame){
    Map map;
    int i;
    for (i=0; i<length(listGame); i++){
        CreateEmptyMap(&map);
        insertListMap(M, map);
    }
}

void addSet(ListSet *S, List listGame){
    Set set;
    int i;
    for (i=0; i<length(listGame); i++){
        CreateEmptySet(&set);
        insertListSet(S, set);
    }
}

void scoreboard(ListMap *M, List L){
    // sort

    header();

    int i;
    for(i=0; i<(*M).nEff; i++){
        sortMap(&(*M).ElmtListMap[i]);
    }
    displayListMap(*M, L);
}

void resetScoreboard(ListMap *M, ListSet *S, List listGame){

    header();

    boolean repeat = true;

    while (repeat){
        printf("DAFTAR SCOREBOARD: \n");
        printf("0. ALL\n");
        int i;
        for (i=0; i<length(listGame); i++){
            printf("%d. ", i+1);
            printWord(listGame.A[i]);
            printf("\n");
        }

        printf("SCOREBOARD YANG INGIN DIHAPUS: ");
        Word input, yesno;
        boolean valid = wordInput(&input, 1, 1);
        if (valid && wordToInt(input)>=0 && wordToInt(input)<=length(listGame)){
            if (wordToInt(input) == 0){
                printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ALL [Y/N] ? ");
                valid = wordInput(&yesno, 1, 1);

                if (valid && (isWordEqual(yesno, stringToWord("Y")) || isWordEqual(yesno, stringToWord("y")))){
                    printf("\nScoreboard berhasil di-reset. \n");
                    int i;
                    for (i=0; i<length(listGame); i++){
                        CreateEmptyMap(&(*M).ElmtListMap[i]);
                        CreateEmptySet(&(*S).ElmtListSet[i]);
                    }
                } else {
                    printf("\nScoreboard tidak jadi di-reset. Berikut adalah daftar scoreboard yang ada. \n");
                    scoreboard(M, listGame);
                }
            } else {
                printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ");
                printWord(listGame.A[wordToInt(input)-1]);
                printf(" [Y/N] ? ");
                valid = wordInput(&yesno, 1, 1);

                if (valid && (isWordEqual(yesno, stringToWord("Y")) || isWordEqual(yesno, stringToWord("y")))){
                    printf("\nScoreboard berhasil di-reset. \n");
                    CreateEmptyMap(&(*M).ElmtListMap[wordToInt(input)-1]);
                    CreateEmptySet(&(*S).ElmtListSet[wordToInt(input)-1]);

                } else {
                    printf("\nScoreboard tidak jadi di-reset. Berikut adalah daftar scoreboard yang ada. \n");
                    scoreboard(M, listGame);
                }
            }

            repeat = false;

        } else {
            printf("\nNomor scoreboard tidak valid. Berikut adalah daftar scoreboard yang ada. \n");
        }
    }

}


//compile (ketik cd src dulu) : gcc Utility/scoreboard/scoreboard.c ADT/map/map.c ADT/word/word.c ADT/word/mesinkata/mesinkata.c Misc/io/io.c ADT/word/mesinkarakter/mesinkarakter.c Misc/ascii/ascii.c ADT/list/array.c ADT/map/listMap.c ADT/set/set.c ADT/set/listSet.c -o test