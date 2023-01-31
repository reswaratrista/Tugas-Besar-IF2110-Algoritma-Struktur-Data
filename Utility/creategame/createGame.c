#include <stdio.h>
#include "createGame.h"

void createGame(List *L, ListMap *LM, ListSet *LS){

    Map M;
    Set S;

    boolean repeat = true;

    Word name;

    while (repeat) {

        header();

        printf("Masukkan nama game yang akan ditambahkan: ");

        boolean valid = wordInput(&name,1,N_MAX);

        if (valid) {
            boolean unique = true;
            int i = 0;
            while (i < length(*L) && unique) {
                if (isWordEqual(getElmt(*L,i),name)) {
                    unique = false;
                }
                i = i + 1;
            }
            if (!unique) {
                printf("Nama game sudah ada dalam daftar game!\n");
            } else {
                insertLast(L,name);
                printf("Game berhasil ditambahkan.\n");
                // insert map baru ke list map
                CreateEmptyMap(&M);
                insertListMap(LM,M);

                // insert set baru ke list set
                CreateEmptySet(&S);
                insertListSet(LS,S);
                
                repeat = false;
            }
        } else {
            if (wordLength(name) == 0) {
                printf("Nama game tidak boleh kosong!\n");
            } else {
                printf("Nama game melebihi batas karakter!\n");
            }
        }

        printf("\nApakah Anda ingin kembali melakukan input? [Y/N]: ");

        valid = wordInput(&name,1,1);
        
        if (valid && (isWordEqual(name,stringToWord("Y")) || isWordEqual(name,stringToWord("y")))) {
            repeat = true;
        } else {
            repeat = false;
        }

    }
}


// compile: gcc utility/createGame.c utility/listGame/listGame.c ADT/list/array.c ADT/queue/queue2.c ADT/word/mesinkata/mesinkata.c ADT/word/mesinkarakter/mesinkarakter.c ADT/word/word.c Misc/io/io.c Misc/ascii/ascii.c -o driver 