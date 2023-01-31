#include <stdio.h>
#include "tree.h"

int main()
{
    BinTree p;
    if (isTreeEmpty(p)){
        printf("p pohon kosong\n");
    }
    p = NewTree(1, NULL, NULL);
    if (isOneElmt(p)){
        printf("p hanya memiliki 1 elemen\n");
    }
    p = NewTree(1, NewTree(2, NULL, NULL), NULL);
    if (isUnerLeft(p)){
        printf("p adalah pohon condong kiri\n");
    }
    p = NewTree(1, NewTree(3, NULL, NULL), NewTree(2, NULL, NULL));
    if (isBinary(p)){
        printf("p adalah pohon biner\n");
    }
    printf("%d\n", nbElmt(p));
    printf("%d\n", nbLeaf(p));
    deallocTreeNode(p);
    return 0;
}

// compile: gcc src/ADT/tree/driverTree.c src/ADT/tree/tree.c -o driver