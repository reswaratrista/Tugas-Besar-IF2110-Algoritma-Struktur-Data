#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include "../boolean.h"
#include "../point/point.h"

#include <stdlib.h>

#define NIL NULL

typedef struct tNode* Address;

typedef struct tNode {
    Point info;
    Address next;
    Address prev;
} Node;

typedef struct {
    Address first;
    Address last;
} LinkedList;

#define First(ll) ((ll).first)
#define Last(ll) ((ll).last)
#define Info(A) (A)->info
#define Next(A) (A)->next
#define Prev(A) (A)->prev

boolean isEmptyLL(LinkedList LL);

Address allocateNode(Point P);

void deallocateNode(Address A);

void createLL(LinkedList *LL);

void insVFirstLL(LinkedList *LL, Point P);

void insVLastLL(LinkedList *LL, Point P);

void delVFirstLL(LinkedList *LL, Point *P);

void delVLastLL(LinkedList *LL, Point *P);

void insertFirstLL(LinkedList *LL, Address A);

void insertLastLL(LinkedList *LL, Address A);

void insertBeforeLL(LinkedList *LL, Address A, Address Succ);

void insertAfterLL(LinkedList *LL, Address A, Address Prec);

void deleteFirstLL(LinkedList *LL, Address *A);

void deleteLastLL(LinkedList *LL, Address *A);

void deleteBeforeLL(LinkedList *LL, Address *A, Address Succ);

void deleteAfterLL(LinkedList *LL, Address *A, Address Prec);

void delAddressLL(LinkedList *LL, Point P);

Point getElmtLL(LinkedList LL, int I);

void setElmtLL(LinkedList *LL, int I, Point P);

Address searchLL(LinkedList LL, Point P);

int lengthLL(LinkedList LL);

int getIdxLL(LinkedList LL, Point P);

#endif