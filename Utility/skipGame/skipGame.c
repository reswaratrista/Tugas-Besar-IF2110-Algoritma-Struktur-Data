#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "skipGame.h"

void skipGame(Queue *Q, List L, int n, List *listHist, ListMap *M, ListSet *S) {

    header();

    printf("Berikut adalah daftar game dalam antrian Anda.\n");
    displayQueue(*Q);
    printf("\n");
    int i;
    QElType X;
    if (n>=Length(*Q)){
        createQueue(Q);
        printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
        printf("Tekan [ENTER] untuk kembali ke menu utama...");
        blankInput();
    } else {
        
        for (i=0; i<n; i++){
            dequeue(Q, &X);
        }

        QElType y;
        dequeue(Q, &y);

        if (isSameWord(y, stringToWord("RNG")) || isSameWord(y, stringToWord("Diner DASH")) || isSameWord(y, stringToWord("HANGMAN")) || isSameWord(y, stringToWord("TOWER OF HANOI")) || isSameWord(y, stringToWord("SNAKE ON METEOR")) || isSameWord(y, stringToWord("Battleship")) || isSameWord(y, stringToWord("The Guessing Genie"))){
            printf("Loading ");
            printWord(y);
            printf(" ...\n");
            printf("\nLoading selesai! Tekan [ENTER] untuk memasuki permainan...");
            blankInput();
            if (isSameWord(y, stringToWord("RNG"))){
                rng(M, S);
            } else if (isSameWord(y, stringToWord("Diner DASH"))){
                dinerDash(M, S);
            } else if (isSameWord(y, stringToWord("HANGMAN"))){
                hangman(M, S);
            } else if (isSameWord(y, stringToWord("TOWER OF HANOI"))){
                towerOfHanoi(M, S);
            } else if (isSameWord(y, stringToWord("SNAKE ON METEOR"))){
                snakeonmeteor(M, S);
            } else if (isSameWord(y, stringToWord("Battleship"))){
                battleship(M, S);
            } else if (isSameWord(y, stringToWord("The Guessing Genie"))){
                guessingGenie(M, S);
            }
        } 
        // else if (isSameWord(y, stringToWord("EIFFEL TOWER")) || isSameWord(y, stringToWord("RISEWOMAN")) || isSameWord(y, stringToWord("DINOSAUR IN EARTH"))){
        //     // Game di file config default selain RNG dan diner DASH
        //     printf("Game ");
        //     printWord(y);
        //     printf(" masih dalam maintenance, belum dapat dimainkan.\n");
        //     printf("Silahkan pilih game lain.\n");
        //     printf("Tekan [ENTER] untuk kembali ke menu utama...");
        //     blankInput();
        // } 
        else {
            // tidak ada di spek game, atau hasil createGame
            printf("Loading ");
            printWord(y);
            printf(" ...\n");
            printf("GAME OVER\n");
			int r = random_range(0,100);
			printf("Score: %d\n", r);

            int index = SearchList(L, y);
            inputDataListMap(M, S, index, r);

            printf("Tekan [ENTER] untuk kembali ke menu utama...");
            blankInput();
        }
        insertFirst(listHist, y);


    }



}

// int main()
// {
//     List L;
//     createList(&L);
//     insertLast(&L, stringToWord("RNG"));
//     insertLast(&L, stringToWord("Diner DASH"));
//     insertLast(&L, stringToWord("DINOSAUR IN EARTH"));
//     insertLast(&L, stringToWord("RISEWOMAN"));
//     insertLast(&L, stringToWord("EIFFEL TOWER"));
//     insertLast(&L, stringToWord("Battleship")); 
//     insertLast(&L, stringToWord("Tetris"));
//     // listGame(L);
//     Queue Q;
//     createQueue(&Q);
//     enqueue(&Q, stringToWord("RNG"));
//     enqueue(&Q, stringToWord("Diner DASH"));
//     enqueue(&Q, stringToWord("Battleship"));
//     enqueue(&Q, stringToWord("RISEWOMAN"));
//     enqueue(&Q, stringToWord("RNG"));
//     skipGame(&Q, L, 4);
//     return 0;
// }

// compile: gcc utility/skipGame/skipGame.c utility/playGame/playGame.c Games/rng/rng.c Games/random.c Games/dinerdash/dinerdash.c ADT/queue/prioqueue.c utility/queuegame/queueGame.c utility/listGame/listGame.c ADT/list/array.c ADT/queue/queue2.c ADT/word/mesinkata/mesinkata.c ADT/word/mesinkarakter/mesinkarakter.c ADT/word/word.c Misc/ascii/ascii.c Misc/io/io.c -o driver