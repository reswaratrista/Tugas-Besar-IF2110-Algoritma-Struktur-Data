#include <stdio.h>
#include <stdlib.h>
#include "towerOfHanoi.h"

void headerTOH(){
    printf("#########   ######   ##      #     ##   ######   ####    \n");
    printf("   ##      ##    ##   ##    ###   ##    ##      ##   #     \n");
    printf("   ##      ##    ##    ##   ###  ##     #####   #####       \n");
    printf("   ##      ##    ##     # ##  ## #      ##      ##  ##       \n");
    printf("   ##       ######      ###   ###       ######  ##   ##       \n");
    printf("-------------------------- O F -------------------------       \n");
    printf("##    ##     ###     ####    ##    ######    #########     \n");
    printf("##    ##    ## ##    ## ##   ##   ##    ##       ##         \n");
    printf("########   #######   ##  ##  ##   ##    ##       ##          \n");
    printf("##    ##  ##     ##  ##   ## ##   ##    ##       ##           \n");
    printf("##    ##  ##     ##  ##    ####    ######    #########         \n");
    printf("      ____                                                      \n");
    printf("     |____|                   ||                      ||\n");
    printf("    |______|                  ||                      ||\n");
    printf("   |________|                 ||                      ||\n");
    printf("  |__________|                ||                      ||\n");
    printf(" |____________|               ||                      ||\n");
    printf("==================    ==================      ==================\n");
    printf("\n");
}
// Inisialisasi Tower
void initAllTower(int h, Tower *A, Tower *B, Tower *C){
    Stack stackA, stackB, stackC;
    CreateEmptyStack(&stackA);
    CreateEmptyStack(&stackB);
    CreateEmptyStack(&stackC);
    (*A).name = 'A';
    (*A).height = h;
    (*A).countDisc = 0;
    (*A).content = stackA;
    (*B).name = 'B';    
    (*B).height = h;
    (*B).countDisc = 0;
    (*B).content = stackB;
    (*C).name = 'C';
    (*C).height = h;
    (*C).countDisc = 0;
    (*C).content = stackC;

    // fill in stack depends on h to tower A
    int i;
    for (i = h; i > 0 ; i--){
        Push(&(*A).content, i);
        (*A).countDisc++;
    };
};

// void initAllTowerV2(int h, Tower *A, Tower *B, Tower *C){
//     Stack stackA, stackB, stackC;
//     CreateEmptyStack(&stackA);
//     CreateEmptyStack(&stackB);
//     CreateEmptyStack(&stackC);
//     (*A).name = 'A';
//     (*A).height = h;
//     (*A).countDisc = 0;
//     (*A).content = stackA;
//     (*B).name = 'B';    
//     (*B).height = h;
//     (*B).countDisc = 0;
//     (*B).content = stackB;
//     (*C).name = 'C';
//     (*C).height = h;
//     (*C).countDisc = 0;
//     (*C).content = stackC;

//     // fill in stack depends on h to tower A
//     int i;
//     for (i = h; i > 0 ; i--){
//         Push(&(*A).content, i);
//         (*A).countDisc++;
//     };
// };

void printAllTower(Tower A, Tower B, Tower C)
{
    printf("Tower A\n");
    printTower(A);
    printf("Tower B\n");    
    printTower(B);
    printf("Tower C\n");
    printTower(C);
    printf("\n========================\n");
}

void printTower(Tower T){
    int h, count, top, i, j, s, disc;
    Stack temp;
    CreateEmptyStack(&temp);
    h = T.height;
    count = T.countDisc;
    top = InfoTop(T.content);
    temp = CopyStack(T.content);

    // print for empty level
    for (i = 0; i < h - count; i++){
        for (j = 0; j < h; j++){
            printf(" ");  
        }
        printf("|\n");
    }

    // print for the rest of tower
    if (top != 0) {
        for (i = 0; i < count; i++)
        {
            // get current disc from temp stack
            Pop(&temp, &disc);
            for (j = 0; j <= h - disc;j++){
                printf(" ");  
            }
            for (s = 0; s < disc-1;s++){
                printf("*");
            }
            printf("*");
            for (s = 0; s < disc-1;s++){
                printf("*");
            }
            printf("\n");
        }
    }

    for (i=0; i<=2*h; i++){
        printf("-");
    }
    printf("\n");
};

// void printTowerV2(Tower T){
//     int h, count, top, i, j, s, disc;
//     Stack temp;
//     CreateEmptyStack(&temp);
//     h = T.height;
//     count = T.countDisc;
//     top = InfoTop(T.content);
//     temp = CopyStack(T.content);

//     // print for empty level
//     for (i = 0; i < h - count; i++){
//         for (j = 0; j < h; j++){
//             printf(" ");  
//         }
//         printf("|\n");
//     }

//     // print for the rest of tower
//     if (top != 0) {
//         for (i = 0; i < count; i++)
//         {
//             // get current disc from temp stack
//             Pop(&temp, &disc);
//             for (j = 0; j < h - disc;j++){
//                 printf(" ");  
//             }
//             for (s = 0; s < disc;s++){
//                 printf("*");
//             }
//             printf("|");
//             for (s = 0; s < disc;s++){
//                 printf("*");
//             }
//             printf("\n");
//         }
//     }

//  for (i=0; i<=2*h; i++){
//   printf("-");
//  }
//  printf("\n");
// };

void moveDisc(Tower *A, Tower *B)
{

    if (IsEmptyStack((*A).content)){
        printf("Tower kosong, tidak ada yang bisa dipindahkan!\n");
        
        printf("\nTekan [ENTER] untuk melanjutkan...");
        blankInput();
        return;
    }

    if (IsEmptyStack((*B).content)) {
        int popped;
        Pop(&((*A).content), &popped);
        (*A).countDisc--;
        Push(&((*B).content), popped);
        (*B).countDisc++;

        printf("Memindahkan piringan dari tower %c ke tower %c\n", (*A).name, (*B).name);
        printf("\nTekan [ENTER] untuk melanjutkan...");
        blankInput();

    } else {
        if (InfoTop((*A).content) > InfoTop((*B).content)){
            printf("Piringan dari tower %c ke tower %c tidak dapat dipindahkan\n", (*A).name, (*B).name);

            printf("\nTekan [ENTER] untuk melanjutkan...");
            blankInput();
            return;
        } else {
            int popped;
            Pop(&((*A).content), &popped);
            (*A).countDisc--;
            Push(&((*B).content), popped);
            (*B).countDisc++;

            printf("Memindahkan piringan dari tower %c ke tower %c\n", (*A).name, (*B).name);
            printf("\nTekan [ENTER] untuk melanjutkan...");
            blankInput();
        }
    }
}

void towerOfHanoi(ListMap *M, ListSet *S){
    header();
    headerTOH();
    Tower A, B, C;
    Word many;
    int height;
    int moves = 0;
    boolean play = true;

    printf("Halo! Selamat datang!\n");    
    printf("Mau main dengan berapa piringan?: ");
	wordInput(&many, 1, 2);
    int intMany = wordToInt(many);

	while (intMany < 1) {
		printf("Pilih angka lebih baik...\n");
        printf("\nTekan [ENTER] untuk melanjutkan...");
        blankInput();

        header();
		printf("Mau main dengan berapa piringan?: ");
        wordInput(&many, 1, 2);
        wordToInt(many);
        intMany = wordToInt(many);
	}

    height = intMany;
    initAllTower(height, &A, &B, &C);
    
    while (play){
        Word wordFirst;
        boolean valid = false;
        while (!valid){
            header();
            printAllTower(A, B, C);
            printf("Pilih tower asal: ");
            createWord(&wordFirst);
            wordInput(&wordFirst, 1, 1);
            if (wordLength(wordFirst) == 0){
                printf("Masukan kosong, ulangi masukan tower!\n");
                printf("\nTekan [ENTER] untuk melanjutkan...");                    
                blankInput();
            }else if(wordLength(wordFirst) > 1){
                printf("Masukan tidak valid, ulangi masukan tower!\n");
                printf("\nTekan [ENTER] untuk melanjutkan...");                    
                blankInput();
            }else {
                if(wordFirst.buffer[0] == 'A' || wordFirst.buffer[0] == 'B' || wordFirst.buffer[0] == 'C' || wordFirst.buffer[0] == 'a' || wordFirst.buffer[0] == 'b' || wordFirst.buffer[0] == 'c'){
                    valid = true;
                }else{
                    printf("Tidak ada tower %c di game ini\n", wordFirst.buffer[0]);
                    printf("\nTekan [ENTER] untuk melanjutkan...");                    
                    blankInput();
                }
            }
           
        }

        Word wordDest;
        valid = false;

        while (!valid){
            printf("Pilih tower tujuan: ");
            createWord(&wordDest);
            wordInput(&wordDest, 1, 1);
            if (wordLength(wordDest) == 0){
                printf("Masukan kosong, ulangi masukan tower!\n\n");
            }else if(wordLength(wordDest) > 1){
                printf("Masukan tidak valid, ulangi masukan tower!\n");
                printf("\nTekan [ENTER] untuk melanjutkan...");                    
                blankInput();
            }else{
                if(wordDest.buffer[0] == 'A' || wordDest.buffer[0] == 'B' || wordDest.buffer[0] == 'C' || wordDest.buffer[0] == 'a' || wordDest.buffer[0] == 'b' || wordDest.buffer[0] == 'c'){
                    valid = true;
                }else{
                    printf("Tidak ada tower %c di game ini\n", wordDest.buffer[0]);
                }                  
            }
        }

        if (wordFirst.buffer[0] == wordDest.buffer[0]){
            printf("Tidak bisa memindahkan ke tower yang sama! Pilih tower lain\n");
            printf("\nTekan [ENTER] untuk melanjutkan...");
            blankInput();

        }else{
            if (wordFirst.buffer[0] == 'A' || wordFirst.buffer[0] == 'a'){
                if (wordDest.buffer[0] == 'B' || wordDest.buffer[0] == 'b'){
                    moveDisc(&A, &B);
                }
                else if(wordDest.buffer[0] == 'C' || wordDest.buffer[0] == 'c'){
                    moveDisc(&A, &C);
                }
            }
            else if (wordFirst.buffer[0] == 'B' || wordFirst.buffer[0] == 'b'){
                if(wordDest.buffer[0] == 'A' || wordDest.buffer[0] == 'a'){
                    moveDisc(&B, &A);
                }
                else if(wordDest.buffer[0] == 'C' || wordDest.buffer[0] == 'c'){
                    moveDisc(&B, &C);
                }
            }
            else //shud be from tower C
                if(wordDest.buffer[0] == 'A' || wordDest.buffer[0] == 'a'){
                    moveDisc(&C, &A);
                }
                else if(wordDest.buffer[0] == 'B' || wordDest.buffer[0] == 'b'){
                    moveDisc(&C, &B);
                }

            moves += 1;
        }

        header();
        printAllTower(A, B, C);

        if (C.countDisc == height) {
            play = false;
        }
    }
    header();
    float min_moves = pow(2, height) - 1;
    int score = ((min_moves/moves)*height*2);
    printf("Selamat telah menyelesaikan Tower of Hanoi!\n");
    printf("Skor kamu: %d\n", score);
    inputDataListMap(M, S, 3, score);
}

// compile:
// ganti dulu nama function tower of hanoi jadi main kalo mau coba 
// gcc src/Games/towerofhanoi/towerOfHanoi.c src/ADT/stack/stack.c src/Utility/splash.c src/Games/random.c src/ADT/word/mesinkata/mesinkata.c src/ADT/word/mesinkarakter/mesinkarakter.c src/ADT/word/word.c src/ADT/list/array.c src/Misc/ascii/ascii.c src/Misc/io/io.c -o driver