#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

BinTree NewTree (TreeElType akar, BinTree l, BinTree r) 
{
    AddressTree t = newTreeNode(akar);
    if (t != NULL) {
        LEFT(t) = l;
        RIGHT(t) = r;
    }
    return t;
}

void CreateTree (TreeElType akar, BinTree l, BinTree r, BinTree *p)
{
    *p = newTreeNode(akar);
    if (*p != NULL){
        LEFT(*p) = l;
        RIGHT(*p) = r;
    }
    
}

AddressTree newTreeNode(TreeElType x)
{
    AddressTree p = (AddressTree) malloc (sizeof(TreeNode));
    if (p != NULL){
        ROOT(p) = x;
        LEFT(p) = NULL;
        RIGHT(p) = NULL;
    }
    return p;
}

void deallocTreeNode (AddressTree p)
{
    free(p);
}

boolean isTreeEmpty (BinTree p)
{
    return (p == NULL);
}

boolean isOneElmt (BinTree p)
{
    return (!isTreeEmpty(p) && isTreeEmpty(LEFT(p)) && isTreeEmpty(RIGHT(p)));
}

boolean isUnerLeft (BinTree p)
{
    return (!isTreeEmpty(p) && !isTreeEmpty(LEFT(p)) && isTreeEmpty(RIGHT(p)));
}

boolean isUnerRight (BinTree p)
{
    return (!isTreeEmpty(p) && isTreeEmpty(LEFT(p)) && !isTreeEmpty(RIGHT(p)));
}

boolean isBinary (BinTree p)
{
    return (!isTreeEmpty(p) && !isTreeEmpty(LEFT(p)) && !isTreeEmpty(RIGHT(p)));
}

int nbElmt (BinTree p)
{
    if (isTreeEmpty(p)){
        return 0;
    } else {
        return 1 + nbElmt(LEFT(p)) + nbElmt(RIGHT(p));
    }
}

int nbLeaf(BinTree p)
{
    if (isTreeEmpty(p)){
        return 0;
    } else if (isOneElmt(p)){
        return 1;
    } else {
        return nbLeaf(LEFT(p)) + nbLeaf(RIGHT(p));
    }
}
