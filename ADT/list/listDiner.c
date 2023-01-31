#include <stdio.h>
#include <stdlib.h>
#include "listDiner.h"

void createListDiner(ListDiner *L)
{
    (*L).Data = (PQElType*) malloc (initialSize * sizeof(PQElType));
    (*L).capacity = initialSize;
    (*L).nEff = 0;
}

void deallocateListDiner(ListDiner *L)
{
    free((*L).Data);
    (*L).capacity = 0;
    (*L).nEff = 0;
}

boolean isEmptyDiner(ListDiner L)
{
    return (L.nEff == 0);
}

boolean isFullDiner(ListDiner L)
{
    return (L.nEff == L.capacity);
}

int lengthDiner(ListDiner L)
{
    return (L.nEff);
}

PQElType getElmtDiner(ListDiner L, int idx)
{
    return (L.Data[idx]);
}

boolean isMemberListDiner(ListDiner L, int ID)
{
    int i = 0;
    while (i< L.nEff){
        if (L.Data[i].foodId == ID){
            return true;
        }
        i++;
    }
    return false;
}

void updateCapacityDiner(ListDiner *L)
{
    int newCapacity = 2 * (*L).capacity;

    PQElType *newBuffer = (PQElType*) malloc (newCapacity * sizeof(PQElType));

    int i;
    for(i = 0; i < lengthDiner(*L); i++){
        newBuffer[i] = getElmtDiner(*L,i);
    }

    free((*L).Data);
    
    (*L).Data = (PQElType*) malloc (newCapacity * sizeof(PQElType));

    for(i = 0; i < lengthDiner(*L); i++){
        (*L).Data[i] = newBuffer[i];
    }

    free(newBuffer);

    (*L).capacity = newCapacity;
}

void insertFirstDiner(ListDiner *L, PQElType X)
{
    insertAtDiner(L, X, 0);
}

void insertAtDiner(ListDiner *L, PQElType X, int idx)
{
    if (isFullDiner(*L)) {
        updateCapacityDiner(L);
    }

    int i;
    for (i = lengthDiner(*L); i > idx; i--) {
        (*L).Data[i] = (*L).Data[i-1];
    }
    (*L).Data[idx] = X;
    (*L).nEff++;
}

void insertLastDiner(ListDiner *L, PQElType X)
{
    insertAtDiner(L, X, lengthDiner(*L));
}

void deleteFirstDiner(ListDiner *L)
{
    deleteAtDiner(L, 0);
}

void deleteAtDiner(ListDiner *L, int idx)
{
    int i;
    for (i = idx; i < lengthDiner(*L); i++) {
        (*L).Data[i] = (*L).Data[i+1];
    }
    (*L).nEff--;
}

void deleteLastDiner(ListDiner *L)
{
    deleteAtDiner(L, lengthDiner(*L)-1);
}

int getidxDiner(ListDiner L, int ID)
{
    int i = 0;
    while (i< L.nEff){
        if (L.Data[i].foodId == ID){
            return i;
        }
        i++;
    }
    return 0;
}

void printCookingDiner(ListDiner L)
{
    printf("\n \n");
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Makanan | Sisa durasi memasak\n");
    printf("-----------------------------\n");
	if (isEmptyDiner(L)){
		printf("        |                 \n");
	} else {
		int i = 0;
		while (i < L.nEff){
            if (L.Data[i].foodId < 10){
                printf("M%d      | %d              \n", L.Data[i].foodId, L.Data[i].cookTime);
            } else {
                printf("M%d     | %d              \n", L.Data[i].foodId, L.Data[i].cookTime);
            }
			i++;
		}
	}
}

void printServingDiner(ListDiner L)
{
    printf("\n \n");
    printf("Daftar Makanan yang dapat disajikan\n");
    printf("Makanan | Sisa ketahanan makanan\n");
    printf("-----------------------------\n");
    if (isEmptyDiner(L)){
		printf("        |                 \n");
	} else {
		int i = 0;
		while (i < L.nEff){
            if (L.Data[i].foodId < 10){
			    printf("M%d      | %d              \n", L.Data[i].foodId, L.Data[i].stayTime);
            } else {
                printf("M%d     | %d              \n", L.Data[i].foodId, L.Data[i].stayTime);
            }
			i++;
		}
	}
}

// compile: gcc ADT/list/array.c ADT/word/word.c Misc/ascii/ascii.c -o driver