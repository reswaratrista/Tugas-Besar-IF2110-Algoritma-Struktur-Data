#ifndef __LIST_DINER_H__
#define __LIST_DINER_H__

#include "../boolean.h"
#include "../word/mesinkata/mesinkata.h"
#include "../queue/prioqueue.h"

#define Nil 0
#define initialSize 10

typedef struct {
    PQElType *Data;
    int nEff;
    int capacity;
} ListDiner;

void createListDiner(ListDiner *L);

void deallocateListDiner(ListDiner *L);

boolean isEmptyDiner(ListDiner L);

boolean isFullDiner(ListDiner L);

int lengthDiner(ListDiner L);

PQElType getElmtDiner(ListDiner L, int i);

int getidxDiner(ListDiner L, int ID);

boolean isMemberListDiner(ListDiner L, int ID);

void updateCapacityDiner(ListDiner *L);

void insertFirstDiner(ListDiner *L, PQElType X);

void insertAtDiner(ListDiner *L, PQElType X, int idx);

void insertLastDiner(ListDiner *L, PQElType X);

void deleteFirstDiner(ListDiner *L);

void deleteAtDiner(ListDiner *L, int idx);

void deleteLastDiner(ListDiner *L);

void printCookingDiner(ListDiner L);

void printServingDiner(ListDiner L);

#endif // __ARRAYDINER_H__