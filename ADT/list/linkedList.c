#include "linkedList.h"
#include <stdio.h>

boolean isEmptyLL(LinkedList LL) {

    return (First(LL) == NIL && Last(LL) == NIL);

}

Address allocateNode(Point P) {

    Address A = (Address) malloc (sizeof(Node));

    if (A != NIL) {
        Info(A) = copyPoint(P);
        Next(A) = NIL;
        Prev(A) = NIL;
        return A;
    } else {
        return NIL;
    }


}

void deallocateNode(Address A) {

    free(A);

}

void createLL(LinkedList *LL) {

    First(*LL) = NIL;
    Last(*LL) = NIL;

}

void insVFirstLL(LinkedList *LL, Point P) {

    Address A = allocateNode(P);

    if (A != NIL) {
        insertFirstLL(LL,A);
    }

}

void insVLastLL(LinkedList *LL, Point P) {

    Address A = allocateNode(P);

    if (A != NIL) {
        insertLastLL(LL,A);
    }

}

void delVFirstLL(LinkedList *LL, Point *P) {

    Address A;
    *P = copyPoint(Info(First(*LL)));

    deleteFirstLL(LL,&A);
    free(A);

}

void delVLastLL(LinkedList *LL, Point *P) {

    Address A;
    *P = copyPoint(Info(First(*LL)));

    deleteLastLL(LL,&A);
    free(A); 

}

void insertFirstLL(LinkedList *LL, Address A) {

    Prev(A) = NIL;

    if (isEmptyLL(*LL)) {

        Next(A) = NIL;
        Last(*LL) = A;

    } else {

        Next(A) = First(*LL);
        Prev(First(*LL)) = A;

    }

    First(*LL) = A;

}

void insertLastLL(LinkedList *LL, Address A) {

    Next(A) = NIL;

    if (isEmptyLL(*LL)) {

        Prev(A) = NIL;
        First(*LL) = A;

    } else {

        Prev(A) = Last(*LL);
        Next(Last(*LL)) = A;
        
    }

    Last(*LL) = A;

}

void insertBeforeLL(LinkedList *LL, Address A, Address Succ) {

    if (Succ == First(*LL)) {

        insertFirstLL(LL,A);

    } else {

        Next(A) = Succ;
        Prev(A) = Prev(Succ);

        Next(Prev(A)) = A;
        Prev(Succ) = A;

    }

}

void insertAfterLL(LinkedList *LL, Address A, Address Prec) {

    if (Prec == Last(*LL)) {

        insertLastLL(LL,A);
    
    } else {

        Prev(A) = Prec;
        Next(A) = Next(Prec);

        Prev(Next(A)) = A;
        Next(Prec) = A;

    }    

}

void deleteFirstLL(LinkedList *LL, Address *A) {

    *A = First(*LL);

    First(*LL) = Next(*A);

    if (First(*LL) == NIL) {
        Last(*LL) = NIL;
    } else {
        Prev(First(*LL)) = NIL;
    }    

}

void deleteLastLL(LinkedList *LL, Address *A) {

    *A = Last(*LL);

    Last(*LL) = Prev(*A);

    if (Last(*LL) == NIL) {
        First(*LL) = NIL;
    } else {
        Next(Last(*LL)) = NIL;
    }

}

void delAddressLL(LinkedList *LL, Point P) {

    Address A = searchLL(*LL,P);

    if (A != NIL) {

        if (A == First(*LL)) {
            deleteFirstLL(LL,&A);
        } else if (A == Last(*LL)) {
            deleteLastLL(LL,&A);
        } else {
            deleteBeforeLL(LL,&A,Next(A));
        }
    
        deallocateNode(A);

    }

}

void deleteBeforeLL(LinkedList *LL, Address *A, Address Succ) {

    *A = Prev(Succ);

    if (*A != NIL) {

        if (*A == First(*LL)) {
        First(*LL) = Succ;
        } else {
            Next(Prev(*A)) = Succ;
        }

        Prev(Succ) = Prev(*A);

    }

}

void deleteAfterLL(LinkedList *LL, Address *A, Address Prec) {

    *A = Next(Prec);

    if (*A != NIL) {

        if (*A == Last(*LL)) {
        Last(*LL) = Prec;
        } else {
            Prev(Next(*A)) = Prec;
        }

        Next(Prec) = Next(*A);

    }

}

Point getElmtLL(LinkedList LL, int I) {

    Point P;

    Address A = First(LL);

    int i = 0;
    while (i != I) {
        A = Next(A);
        i = i + 1;
    }

    P = copyPoint(Info(A));
    return P;

}

void setElmtLL(LinkedList *LL, int I, Point P) {

    Address A = First(*LL);

    int i = 0;
    while (i != I) {
        A = Next(A);
        i = i + 1;
    }

    Info(A) = copyPoint(P);

}

Address searchLL(LinkedList LL, Point P) {

    Address A = First(LL);
    boolean Found = false;

    while (A != NIL && !Found) {
        if (isPointEqual(Info(A),P)) {
            Found = true;
        } else {
            A = Next(A);
        }
    }

    if (Found) {
        return A;
    } else {
        return NIL;
    }

}

int lengthLL(LinkedList LL) {

    Address A = First(LL);
    int Len = 0;

    while (A != NIL) {
        Len = Len + 1;
        A = Next(A);
    }

    return Len;

}

int getIdxLL(LinkedList LL, Point P) {

    Address A = First(LL);
    boolean Found = false;
    int Idx = 0;


    while (A != NIL && !Found) {
        if (isPointEqual(P,Info(A))) {
            Found = true;
        } else {
            Idx = Idx + 1;
            A = Next(A);
        }
    }

    if (!Found) {
        return -1;
    } else {
        return Idx;
    }

}