#include <stdio.h>
#include "deleteGame.h"

void deleteGame(List *L, Queue Q, List *listHist, ListMap *listMapGame, ListSet *listName) {

    boolean repeat = true;

    while (repeat) {

        header();

        listGame(*L);

        printf("\nMasukkan nomor game yang akan dihapus: ");
        Word input;
        createWord(&input);

        boolean valid = wordInput(&input,1,10);
        if (valid && wordToInt(input) > 0 && wordToInt(input) <= length(*L)) {
            if (wordToInt(input)>=1 && wordToInt(input)<=7){
                printf("Game gagal dihapus.\n");
            } else if (wordToInt(input) > 7) {
                if (!(IsEmpty(Q))){
                    if (!(isMember(Q, getElmt(*L,wordToInt(input)-1)))){
                        
                        // delete di history
                        Word gamename;
                        createWord(&gamename);
                        gamename = getElmt(*L,wordToInt(input)-1);
                        deleteElmt(listHist, gamename);

                        // delete di listgame
                        deleteAt(L, wordToInt(input)-1);

                        // delete di listmap & listset
                        deleteListMap(listMapGame, wordToInt(input)-1);
                        deleteListSet(listName, wordToInt(input)-1);
                        printf("Game berhasil dihapus\n");
                    } else {
                        printf("Game ada di antrian game-mu; game gagal dihapus.");
                    }
                } else {

                    // delete di history
                    Word gamename;
                    createWord(&gamename);
                    gamename = getElmt(*L,wordToInt(input)-1);
                    deleteElmt(listHist, gamename);

                   // delete di listgame
                    deleteAt(L, wordToInt(input)-1);

                    // delete di listmap & listset
                    deleteListMap(listMapGame, wordToInt(input)-1);
                    deleteListSet(listName, wordToInt(input)-1);
                    printf("Game berhasil dihapus\n");
                }
            }
        } else {    // wordToInt(input) <= 0 || wordToInt(input) > length(*L)
            printf("Nomor game tidak valid; game gagal dihapus.\n");
        }

        printf("Apakah Anda ingin kembali melakukan input? [Y/N]: ");

        valid = wordInput(&input,1,1);
        
        if (valid && (isWordEqual(input,stringToWord("Y")) || isWordEqual(input,stringToWord("y")))) {
            repeat = true;
        } else {
            repeat = false;
    
    }

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
//     displayList(L);
//     printf("\n");
//     Queue Q;
//     createQueue(&Q);
//     enqueue(&Q, stringToWord("RNG"));
//     enqueue(&Q, stringToWord("Diner DASH"));
//     enqueue(&Q, stringToWord("RNG"));
//     displayQueue(Q);
//     printf("\n");
//     deleteGame(&L,Q);
//     displayList(L);
//     return 0;
// }

// compile: gcc utility/deleteGame/deleteGame.c utility/listGame/listGame.c ADT/list/array.c ADT/queue/queue2.c ADT/word/mesinkata/mesinkata.c ADT/word/mesinkarakter/mesinkarakter.c ADT/word/word.c Misc/io/io.c Misc/ascii/ascii.c -o driver
