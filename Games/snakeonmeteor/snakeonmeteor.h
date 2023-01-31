#ifndef __SNAKE__
#define __SNAKE__

#include "../../ADT/list/linkedList.h"
#include "../../ADT/word/mesinkata/mesinkata.h"
#include "../../ADT/map/listMap.h"
#include "../../Misc/io/io.h"
#include "../../Utility/splash.h"
#include "../random.h"

typedef struct {
    Point meteor;
    Point obstacle;
    Point food;
} SnakeGrid;

void drawMap(SnakeGrid SG, LinkedList S, boolean Lose, boolean Hit, int LoseCondition, int Turns);

void snakeonmeteor(ListMap *M, ListSet *S);

Point validMove(SnakeGrid SG, LinkedList S, Word D);

Point checkGrow(SnakeGrid SG, LinkedList S);

void spawn(LinkedList *S);

int move(SnakeGrid *SG, LinkedList *S, Word D, boolean *Lose, int *LoseCondition);

void hit(SnakeGrid *SG, LinkedList *S, boolean *Lose, boolean *Hit, int *LoseCondition);

void grow(SnakeGrid *SG, LinkedList *S, boolean *Lose, int *LoseCondition);

void updateFood(SnakeGrid *SG, LinkedList S);

void updateMeteor(SnakeGrid *SG);

boolean noMoreMoves(SnakeGrid SG, LinkedList S);

void snakeSplash();

#endif