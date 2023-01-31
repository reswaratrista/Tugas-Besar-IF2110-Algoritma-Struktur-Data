#include <stdio.h>
#include "history.h"
#include "../playGame/playGame.h"
#include "../../Utility/queuegame/queueGame.h"

void resetHist(List *listHist){
    Word yn;
    printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY?[Y/N]\n");
    boolean yesno = wordInput(&yn, 1, 1);
    boolean yes = (isSameWord(yn, stringToWord("Y")) || isSameWord(yn, stringToWord("y")));
    boolean no = (isSameWord(yn, stringToWord("N")) || isSameWord(yn, stringToWord("n")));
    while (!yes && !no){
        printf("Masukan salah! Ulangi input!\n");
        yesno = wordInput(&yn, 1, 1);
    }
    if (yes){
        deallocateList(listHist);
        printf("History berhasil di-reset.\n");            
    }else if (no){
        printf("History tidak jadi di-reset. ");
        history(*listHist, length(*listHist));
    }
}

void history(List listHist, int num){
    int i;

    header();

    if (length(listHist) > 0){
        printf("Berikut adalah daftar Game yang telah dimainkan\n");
        if (num < length(listHist)){
            for (i = 0; i < num; i++){
                printf("%d. ", i+1);
                int j;
                for(j=0; j<listHist.A[i].length; j++){
                    printf("%c", listHist.A[i].buffer[j]);
                }
                printf("\n");
            }
        }else{
            for (i = 0; i < length(listHist); i++){
                printf("%d. ", i+1);
                int j;
                for(j=0; j<listHist.A[i].length; j++){
                    printf("%c", listHist.A[i].buffer[j]);
                }
                printf("\n");
            }        
        }     
    } else { 
        printf("Belum ada Game yang dimainkan.\n");
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

//     List hist;
//     createList(&hist);

//     Queue Q;
//     createQueue(&Q);
//     // enqueue(&Q, stringToWord("Tetris"));
//     // enqueue(&Q, stringToWord("Diner DASH"));
//     // enqueue(&Q, stringToWord("RNG"));
//     queueGame(&Q, L);
//     displayQueue(Q);
//     playGame(&Q, L, &hist);
//     playGame(&Q, L, &hist);
//     playGame(&Q, L, &hist);
//     playGame(&Q, L, &hist);
//     playGame(&Q, L, &hist);
//     playGame(&Q, L, &hist);
//     //battle dash battle dash dash dash
//     printf("List history\n");
//     displayList(hist);
//     printf("keluarin history\n");
//     history(hist, 3);
//     resetHist(&hist);
//     printf("List history\n");
//     displayList(hist);
//     history(hist, 3);

//     // int num;
//     // history(List, num);
//     // displayList(List);
// }

// gcc utility/splash.c utility/playGame/playGame.c utility/queuegame/queueGame.c utility/listGame/listGame.c Games/rng/rng.c ADT/list/array.c ADT/word/word.c ADT/word/mesinkata/mesinkata.c ADT/word/mesinkarakter/mesinkarakter.c Games/random.c Games/dinerdash/dinerdash.c Misc/io/io.c Misc/ascii/ascii.c ADT/queue/queue2.c Utility/history/history.c ADT/queue/prioqueue.c -o driver