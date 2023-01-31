/* File: queueGame.h */
/* Menggunakan ADT queue */

#ifndef SKIPGAME_H
#define SKIPGAME_H

/* ADT lain yang dipakai */
#include "../../ADT/boolean.h"
#include "../playGame/playGame.h"

void skipGame(Queue *Q, List L, int n, List *listHist, ListMap *M, ListSet *S);
// melewatkan permainan sebanyak n kali

#endif