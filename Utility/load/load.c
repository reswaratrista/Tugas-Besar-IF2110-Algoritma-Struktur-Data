#include <stdio.h>
#include "load.h"

void LOAD(Word filename, List *ListGame, List *listHist, ListMap *listMapGame, ListSet *listName) {
    
    Word filepath;
    concateWord(stringToWord("Config/"),filename,&filepath);
    
    char filepathstr[wordLength(filepath) + 1];
    wordToString(filepath,filepathstr);

    Map M;
    Set S;
    startKata(true,filepathstr);
    int i;
    int numberGame = wordToInt(currentKata); //baca jumlah listGame
    advKata();
    for (i=0; i < numberGame; i++){
        insertLast(ListGame,currentKata);
        CreateEmptyMap(&M);
        insertListMap(listMapGame,M);
        CreateEmptySet(&S);
        insertListSet(listName, S);
        advKata();
    }

    int number = wordToInt(currentKata); //baca jumlah listHist
    advKata();
    for (i=0; i < number; i++){
        insertLast(listHist,currentKata);
        advKata();
    }

    int k;
    for (k=0; k<numberGame; k++){ // jumlah listmapgame
        int numberMap = wordToInt(currentKata); //baca jumlah  elemen map dlm list map game
        advKata();
        for (i=0; i < numberMap; i++){
            Word name, score;
            createWord(&name);
            createWord(&score);
            int j = 0;
            while (currentKata.buffer[j] != INPUTBLANK){
                name.buffer[j] = currentKata.buffer[j];
                name.length++;
                j++;
            }

            j++; // spasi

            while (j < currentKata.length){
                score.buffer[j - (name.length+1)] = currentKata.buffer[j];
                score.length++;
                j++;
            }

            InsertMap(&listMapGame->ElmtListMap[k], name, wordToInt(score));
            InsertSet(&listName->ElmtListSet[k], name);
            advKata();
        }
    }

}

boolean CHECKFILE(Word filename) {

    Word filepath;
    concateWord(stringToWord("Config/"),filename,&filepath);
    
    char filepathstr[wordLength(filepath) + 1];
    wordToString(filepath,filepathstr);

    FILE * test;
    test = fopen(filepathstr,"r");

    if (test) {
        fclose(test);
        return false;
    } else {
        return true;
    }

}