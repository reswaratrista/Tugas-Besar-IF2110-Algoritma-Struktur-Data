#ifndef __ARRAY_H__
#define __ARRAY_H__

#include "../boolean.h"
#include "../word/mesinkata/mesinkata.h"

#define Nil 0
#define initialSize 10

#define ElType Word

typedef struct {
    ElType *A;
    int nEff;
    int capacity;
} List;

void createList(List *L);

void deallocateList(List *L);

boolean isElTypeEqual(ElType l1, ElType l2);

boolean isEmpty(List L);

boolean isFull(List L);

int length(List L);

ElType getElmt(List L, int i);

void setElmt(List *L, int i, ElType v);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */

boolean isMemberList(List L, ElType X);

void updateCapacity(List *L);

void insertFirst(List *L, ElType X);

void insertAt(List *L, ElType X, int idx);

void insertLast(List *L, ElType X);

void deleteFirst(List *L);

void deleteAt(List *L, int idx);

void deleteLast(List *L);

void displayList(List L);

int SearchList(List L, ElType X);

void deleteElmt(List *L, ElType X);

#endif // __ARRAY_H__