#ifndef TGG_H
#define TGG_H

#include "../../ADT/tree/tree.h"
#include "../../ADT/word/mesinkata/mesinkata.h"
#include "../../ADT/boolean.h"
#include "../../ADT/word/word.h"
#include "../../ADT/map/listMap.h"
#include "../../ADT/set/listSet.h"
#include "../../Misc/ascii/ascii.h"
#include "../../Misc/io/io.h"
#include "../../Utility/splash.h"

boolean yesno();
// meminta input yes atau no

int moveInTree(BinTree T);
// bergerak di binary tree

void guessingGenie();
// main program

void genieSplash();

#endif