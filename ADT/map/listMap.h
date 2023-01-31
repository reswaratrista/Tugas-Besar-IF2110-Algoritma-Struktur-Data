#ifndef __LISTMAP__
#define __LISTMAP__

#include "../boolean.h"
#include "map.h"

#define Nil 0
#define defaultSize 10

#define ElTypeMap Map

typedef struct {
    ElTypeMap *ElmtListMap;
    int nEff;
    int capacity;
} ListMap;

void createListMap(ListMap *L);

void deallocateListMap(ListMap *L);

void updateCapacityListMap(ListMap *L);

boolean isEmptyListMap(ListMap L);

boolean isFullListMap(ListMap L);

void insertListMap(ListMap *L, Map M);

void deleteListMap(ListMap *L, int idx);

void displayListMap(ListMap L, List Game);

void inputDataListMap(ListMap *L, ListSet *S, int idx, int score);

#endif