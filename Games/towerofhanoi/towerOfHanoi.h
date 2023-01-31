#ifndef towerofhanoi_H
#define towerofhanoi_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../../ADT/boolean.h"
#include "../../ADT/stack/stack.h"
#include "../../ADT/word/mesinkata/mesinkata.h"
#include "../../ADT/word/word.h"
#include "../../ADT/map/listMap.h"
#include "../../ADT/set/listSet.h"
#include "../../Misc/ascii/ascii.h"
#include "../../Misc/io/io.h"
#include "../../Utility/splash.h"
#include "../../ADT/list/array.h"
#include "../random.h"


// Tower Type
typedef struct Tower {
    char name;
    int height; // height of the tower
    int countDisc; // count of disc inside the tower
    Stack content;
} Tower;

// Initialize all tower
void initAllTower(int h, Tower *A, Tower *B, Tower *C);
// Move top disc from tower A to B
void moveDisc(Tower *A, Tower *B);
// Print tower
void printTower(Tower T);
// Print all tower
void printAllTower(Tower A, Tower B, Tower C);

void towerOfHanoi(ListMap *M, ListSet *S);

#endif