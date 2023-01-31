#include <stdio.h>
#include <stdlib.h>
#include "listDiner.h"

int main()
{
    ListDiner L;
    createListDiner(&L);
    if (isEmptyDiner(L)){
        printf("ListDiner kosong\n");
    }
    PQElType temp;
    temp.foodId = 1;
    temp.cookTime = 1;
    temp.stayTime = 1;
    temp.price = 10000;
    insertFirstDiner(&L, temp);
    temp.foodId = 2;
    insertLastDiner(&L, temp);
    temp.foodId = 3;
    insertAtDiner(&L, temp, 1);
    printCookingDiner(L);
    deleteAtDiner(&L, 1);
    printCookingDiner(L);

    temp = getElmtDiner(L,1);
    printf("\n%d\n", temp.foodId);

    int idx = getidxDiner(L, 2);
    printf("\n%d\n", idx);

    if (isMemberListDiner(L, 10)){
        printf("\nMember\n");
    } else {
        printf("\nNot Member\n");
    }
    return 0;
}

// compile: gcc src/ADT/list/driverListDiner.c src/ADT/list/listDiner.c src/ADT/queue/prioqueue.c -o driver