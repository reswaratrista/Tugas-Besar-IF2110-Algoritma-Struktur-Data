#include <stdio.h>
#include <stdlib.h>
#include "listMap.h"

void createListMap(ListMap *L){
    (*L).ElmtListMap = (ElTypeMap*) malloc (defaultSize * sizeof(ElTypeMap));
    (*L).capacity = defaultSize;
    (*L).nEff = 0;
}

void deallocateListMap(ListMap *L){
    free((*L).ElmtListMap);
    (*L).capacity = 0;
    (*L).nEff = 0;
}

void updateCapacityListMap(ListMap *L){
    int newCapacity = 2 * defaultSize;
    ElTypeMap *newBuffer = (ElTypeMap*) malloc (newCapacity * sizeof(ElTypeMap));
    int i;
    for (i = 0; i < (*L).nEff; i++){
        newBuffer[i] = (*L).ElmtListMap[i];
    }
    free((*L).ElmtListMap);

    (*L).ElmtListMap = (ElTypeMap*) malloc (newCapacity * sizeof(ElTypeMap));

    for (i=0; i<(*L).nEff; i++){
        (*L).ElmtListMap[i] = newBuffer[i];
    }

    free(newBuffer);
    (*L).capacity = newCapacity;
}

boolean isEmptyListMap(ListMap L){
    return (L.nEff == 0);
}

boolean isFullListMap(ListMap L){
    return (L.nEff == L.capacity);
}

void insertListMap(ListMap *L, Map M){
    if (isFullListMap(*L)){
        updateCapacityListMap(L);
    }
    (*L).ElmtListMap[(*L).nEff] = M;
    (*L).nEff++;
}

void deleteListMap(ListMap *L, int idx){
    int i;
    for (i=idx; i<(*L).nEff-1; i++){
        (*L).ElmtListMap[i] = (*L).ElmtListMap[i+1];
    }
    (*L).nEff--;
}

void inputDataListMap(ListMap *L, ListSet *S, int idx, int score){
    inputData(&((*L).ElmtListMap[idx]), &((*S).ElmtListSet[idx]), score);
}

void displayListMap(ListMap L, List Game){
    int i;
    for (i=0; i<L.nEff; i++){
        PrintMap(L.ElmtListMap[i], Game.A[i]);
        // printf("| Nama               | SKOR             |\n");
        // if (!(IsEmptyMap(L.ElmtListMap[i]))){
        //     printf("|---------------------------------------|\n");
        //     int j;
        //     for (j=0; j<L.ElmtListMap->Count; j++){
        //         printf("| ");
        //         printWord(L.ElmtListMap[i].Elements->name);
        //         printf("| %d                 |", L.ElmtListMap[i].Elements->score);
        //     }
        // } else {
        //     printf("-------- SCOREBOARD KOSONG -------------\n\n");
        // }
    }
}