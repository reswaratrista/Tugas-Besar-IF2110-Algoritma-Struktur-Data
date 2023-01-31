#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "playGame.h"

void playGame(Queue *Q, List L, List *listHist, ListMap *M, ListSet *S)
{
    header();
    if (IsEmpty(*Q)){
        printf("Antrian Anda kosong.\n");
        printf("\nTekan [ENTER] untuk kembali ke menu utama...");
        blankInput();
    } else {
        printf("Berikut adalah daftar Game di dalam antrian Anda.\n");
        displayQueue(*Q);
        printf("\n");
        QElType x;
        dequeue(Q, &x);
        if (isSameWord(x, stringToWord("RNG")) || isSameWord(x, stringToWord("Diner DASH")) || isSameWord(x, stringToWord("HANGMAN")) || isSameWord(x, stringToWord("TOWER OF HANOI")) || isSameWord(x, stringToWord("SNAKE ON METEOR")) || isSameWord(x, stringToWord("Battleship")) || isSameWord(x, stringToWord("The Guessing Genie"))){
            printf("Loading ");
            printWord(x);
            printf(" ...\n");
            printf("\nLoading selesai! Tekan [ENTER] untuk memasuki permainan...");
            blankInput();
            if (isSameWord(x, stringToWord("RNG"))){
                rng(M, S);
            } else if (isSameWord(x, stringToWord("Diner DASH"))){
                dinerDash(M, S);
            } else if (isSameWord(x, stringToWord("HANGMAN"))){
                hangman(M, S);
            } else if (isSameWord(x, stringToWord("TOWER OF HANOI"))){
                towerOfHanoi(M, S);
            } else if (isSameWord(x, stringToWord("SNAKE ON METEOR"))){
                snakeonmeteor(M, S);
            } else if (isSameWord(x, stringToWord("Battleship"))){
                battleship(M, S);
            } else if (isSameWord(x, stringToWord("The Guessing Genie"))){
                guessingGenie(M, S);
            }
        } 
        // else if (isSameWord(x, stringToWord("EIFFEL TOWER")) || isSameWord(x, stringToWord("RISEWOMAN")) || isSameWord(x, stringToWord("DINOSAUR IN EARTH"))){
        //     // Game di file config default selain RNG dan diner DASH
        //     printf("Game ");
        //     printWord(x);
        //     printf(" masih dalam maintenance, belum dapat dimainkan.\n");
        //     printf("Silahkan pilih game lain.\n");
        //     printf("\nTekan [ENTER] untuk kembali ke menu utama...");
        //     blankInput();
        // } 
        else {
            // tidak ada di spek game, atau hasil createGame
            printf("Loading ");
            printWord(x);
            printf(" ...\n");
            printf("GAME OVER\n");
			int r = random_range(0,100);
			printf("Score: %d\n", r);

            int index = SearchList(L, x);
            inputDataListMap(M, S, index, r);
            printf("\nTekan [ENTER] untuk kembali ke menu utama...");
            blankInput();
        }
        insertFirst(listHist, x);
    }
}

// int main()
// {
//     List L, hist;
//     ListMap M;
//     createList(&L);
//     createList(&hist);
//     createListMap(&M);
//     insertLast(&L, stringToWord("RNG"));
//     insertLast(&L, stringToWord("Diner DASH"));
//     insertLast(&L, stringToWord("DINOSAUR IN EARTH"));
//     insertLast(&L, stringToWord("RISEWOMAN"));
//     insertLast(&L, stringToWord("EIFFEL TOWER"));
//     insertLast(&L, stringToWord("Battleship")); 
//     insertLast(&L, stringToWord("Tetris"));
//     displayList(L);
//     Queue Q;
//     createQueue(&Q);
//     enqueue(&Q, stringToWord("RNG"));
//     enqueue(&Q, stringToWord("Diner DASH"));
//     enqueue(&Q, stringToWord("RNG"));
    
//     Map hangman, dinerdash, rng, battleship;
//     createMap(&hangman, stringToWord("HANGMAN"));
//     createMap(&dinerdash, stringToWord("Diner DASH"));
//     createMap(&rng, stringToWord("RNG"));
//     createMap(&battleship, stringToWord("Battleship"));
//     insertLastMap(&M, hangman);
//     insertLastMap(&M, dinerdash);
//     insertLastMap(&M, rng);
//     insertLastMap(&M, battleship);

//     displayListMap(M, L);
//     // playGame(&Q, L, &hist, &M);
//     // displayQueue(Q);
//     // printf("hai");
//     // displayListMap(M, L);
//     // printf("hai");
//     return 0;
// }

// compile: gcc ADT/map/listMap.c ADT/point/point.c Games/battleship/battleship.c ADT/map/map.c Games/hangman/hangman.c Games/hangman/man.c utility/splash.c utility/playGame/playGame.c utility/queuegame/queueGame.c utility/listGame/listGame.c Games/rng/rng.c Games/random.c Games/dinerdash/dinerdash.c ADT/list/array.c ADT/queue/queue2.c ADT/queue/prioqueue.c ADT/word/mesinkata/mesinkata.c ADT/word/mesinkarakter/mesinkarakter.c ADT/word/word.c Misc/io/io.c Misc/ascii/ascii.c -o driver