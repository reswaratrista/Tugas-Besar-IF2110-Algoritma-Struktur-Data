#include <stdio.h>
#include "queue2.h"
#include "../word/word.h"

int main()
{
    Queue Q;
    QElType X, Y;
    createQueue(&Q);
    X = stringToWord("hai");
    Y = stringToWord("halo");
    enqueue(&Q, X);
    displayQueue(Q);
    printf("%d\n", Q.MaxEl);
    enqueue(&Q, Y);
    printf("%d\n", Length(Q));
    QElType Z;
    dequeue(&Q, &Z);
    if (isSameWord(Z, X)){
        printf("Sama\n");
    } else {
        printf("Tidak sama\n");
    }
    printWord(Front(Q));
    printf("\n");
    if (isMember(Q, X)){
        printf("hai ada\n");
    } else {
        printf("hai ga ada\n");
    }
    return 0;
}

// compile: gcc src/ADT/queue/driverQueue2.c src/ADT/queue/queue2.c src/ADT/word/word.c src/Misc/ascii/ascii.c -o driver