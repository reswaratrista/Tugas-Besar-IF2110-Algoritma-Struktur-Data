/* File: queueGame.h */
/* Menggunakan ADT queue */

#ifndef QUEUEGAME_H
#define QUEUEGAME_H

/* ADT lain yang dipakai */
#include "../../ADT/boolean.h"
#include "../../ADT/queue/queue2.h"
#include "../../ADT/word/mesinkata/mesinkata.h"
#include "../listGame/listGame.h"
#include "../../Misc/io/io.h"
#include "../../Misc/ascii/ascii.h"
#include "../splash.h"

void queueGame(Queue *Q, List L);
// mendaftarkan permainan ke dalam list

#endif