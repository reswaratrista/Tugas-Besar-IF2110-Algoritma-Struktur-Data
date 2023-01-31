#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "rng.h"

void rng(ListMap *M, ListSet *S){

    header();

    rngSplash();

    int Number = random_range(0,100);

    int Answer, Tries = 0;

    boolean Correct = false;

    Word input;
    createWord(&input);

    boolean valid;

    while (!Correct) {
        printf("Tebakan: ");
        valid = wordInput(&input,1,10);
        if (valid && wordToInt(input) != INVALID_INT && wordToInt(input) >= 0) {
            Answer = wordToInt(input);
            if (Answer != Number) {
                if (Answer > Number) {
                    printf("Lebih Kecil\n");
                } else {
                    printf("Lebih Besar\n");
                }
                Tries = Tries + 1;
            } else {
                printf("Ya, X adalah %d.\n",Number);
                int Score = 100 - Tries;
                if (Score < 0) {
                    Score = 0;
                }
                printf("\nSkor Anda adalah: %d\n\n",Score);
                inputDataListMap(M, S, 0, Score);
                Correct = true;
            }
        } else {
            printf("Masukan tidak valid!\n");
        }
    }

    printf("\nTekan [ENTER] untuk kembali ke menu utama...\n");

    blankInput();

}

void rngSplash() {

    printf("                       Selamat datang di\n");
    printf("                       :::::::::  ::::    :::  ::::::::\n");
    printf("                       :+:    :+: :+:+:   :+: :+:    :+:\n");
    printf("                       +:+    +:+ :+:+:+  +:+ +:+        \n");
    printf("                       +#++:++#:  +#+ +:+ +#+ :#:        \n");
    printf("                       +#+    +#+ +#+  +#+#+# +#+   +#+# \n");
    printf("                       +#+    +#+ +#+  +#+#+# +#+   +#+# \n");
    printf("                       #+#    #+# #+#   #+#+# #+#    #+# \n");
    printf("                       ###    ### ###    ####  ########  \n");
    printf("                                        Are you lucky..? \n");
    printf("\n");
    printf("==========RNG telah dimulai. Uji keberuntungan Anda dengan menebak X.===========\n\n");

}

// int main(){
//     rng();
// }
// compile: gcc Games/rng/rng.c Games/random.c Misc/io/io.c Misc/ascii/ascii.c ADT/list/array.c ADT/word/mesinkata/mesinkata.c ADT/word/mesinkarakter/mesinkarakter.c ADT/word/word.c -o driver