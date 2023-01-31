/* File: queueGame.h */
/* Menggunakan ADT queue */

#ifndef PLAYGAME_H
#define PLAYGAME_H

/* ADT lain yang dipakai */
#include "../../ADT/boolean.h"
#include "../queuegame/queueGame.h"
#include "../../Games/rng/rng.h"
#include "../../Games/dinerdash/dinerdash.h"
#include "../../Games/battleship/battleship.h"
#include "../../Games/hangman/hangman.h"
#include "../../Games/towerofhanoi/towerOfHanoi.h"
#include "../../Games/snakeonmeteor/snakeonmeteor.h"
#include "../../Games/tgg/tgg.h"
#include "../../ADT/map/listMap.h"
#include "../../ADT/set/listSet.h"

void playGame(Queue *Q, List L, List *listHist, ListMap *M, ListSet *S);
// Game yang dimainkan adalah game dengan antrian pertama di antrian game
// Game yang dapat dimainkan adalah game yang ada di spek game

#endif