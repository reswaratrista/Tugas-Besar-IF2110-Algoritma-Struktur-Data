#include <stdio.h>
#include "prioqueue.h"

int main()
{
    PrioQueue pq;
    createQueuePQ(&pq);
    if (isEmptyPQ(pq)){
        printf("Queue kosong\n");
    } else {
        printf("Queue tidak kosong\n");
    }
    PQElType test, test1;
    test.foodId = 1;
    test.cookTime = 2;
    test.stayTime = 3;
    test.price = 4;
    test1.foodId = 5;
    test1.cookTime = 6;
    test1.stayTime = 7;
    test1.price = 8;
    enqueuePQ(&pq, test);
    printf("%d\n", lengthPQ(pq));
    if (isFullPQ(pq)){
        printf("Queue penuh\n");
    } else {
        printf("Queue tidak penuh\n");
    }
    enqueuePQ(&pq, test1);
    PQElType test2;
    dequeuePQ(&pq, &test2);
    if (isEmptyPQ(pq)){
        printf("Queue kosong\n");
    } else {
        printf("Queue tidak kosong\n");
    }
    printOrders(pq);
    return 0;
}

// compile: gcc src/ADT/queue/driverPrioqueue.c src/ADT/queue/prioqueue.c -o driver