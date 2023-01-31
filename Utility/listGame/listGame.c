#include <stdio.h>
#include "listGame.h"

void listGameMain(List L) {

    header();

    if (isEmpty(L)){
        printf("Tidak ada game yang tersedia\n");
    } else {
        printf("Berikut adalah daftar game yang tersedia\n");
        displayList(L);
    }

    printf("\nTekan [ENTER] untuk kembali ke menu utama...");

    blankInput();

}

void listGame(List L)
{
    if (isEmpty(L)){
        printf("Tidak ada game yang tersedia\n");
    } else {
        printf("Berikut adalah daftar game yang tersedia\n");
        displayList(L);
    }
}

// int main()
// {
//     List L;
//     createList(&L);
//     listGame(L);
//     ElType test, test1;
//     test = stringToWord("hai");
//     test1 = stringToWord("halo");
//     insertFirst(&L, test);
//     insertLast(&L, test1);
//     listGame(L);
//     return 0;
// }

// compile: gcc utility/listGame/listGame.c ADT/list/array.c ADT/word/mesinkata/mesinkata.c ADT/word/mesinkarakter/mesinkarakter.c ADT/word/word.c Misc/ascii/ascii.c -o driver