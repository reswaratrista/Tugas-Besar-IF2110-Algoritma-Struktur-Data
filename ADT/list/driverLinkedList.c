#include <stdio.h>
#include "linkedList.h"

int main()
{
    LinkedList LL;
    createLL(&LL);

    Point P;
    createPoint(&P, 1, 2);

    Address x = allocateNode(P);
    insertFirstLL(&LL, x);

    createPoint(&P, 3, 4);

    insVLastLL(&LL, P);

    deleteFirstLL(&LL, &x);
    P = getElmtLL(LL, 0);

    setElmtLL(&LL, 0, P);

    Address y = searchLL(LL, P);
    if (y != NIL) {
        printf("P ada di LL\n");
    } else {
        printf("P tidak ada di LL\n");
    }

    printf("%d\n", lengthLL(LL));

    printf("%d %d\n", ABSCISSA(getElmtLL(LL, lengthLL(LL)-1)), ORDINATE(getElmtLL(LL, lengthLL(LL)-1)));

    return 0;
}

// compile : gcc src/ADT/point/point.c src/ADT/list/linkedList.c src/ADT/list/driverLinkedList.c -o driver