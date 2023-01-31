#include <stdio.h>
#include "save.h"
static FILE *saveFile;

// bikin file baru
void savetoFile(char saveFilename[], List L, List listHist, ListMap mapGame)
{
    Word file;
    concateWord(stringToWord("Config/"),stringToWord(saveFilename),&file);
    
    char a[wordLength(file) + 1];
    wordToString(file, a);

    saveFile = fopen(a, "w");

    // save list game
    fprintf(saveFile, "%d\n", L.nEff);
    int i;
    for(i=0; i<length(L); i++){
        int j;
        for(j=0; j<L.A[i].length; j++){
            fprintf(saveFile, "%c", L.A[i].buffer[j]);
        }
        if (i < length(L)-1) {
            fprintf(saveFile, "\n");
        }
    }
    fprintf(saveFile, "\n");

    // save list history
    if (listHist.nEff == 0){
        fprintf(saveFile, "%d", listHist.nEff);
    } else {
        fprintf(saveFile, "%d\n", listHist.nEff);
        for(i=0; i<length(listHist); i++){
            int j;
            for(j=0; j<listHist.A[i].length; j++){
                fprintf(saveFile, "%c", listHist.A[i].buffer[j]);
            }
            if (i < length(listHist)-1) {
                fprintf(saveFile, "\n");
            }
        }
    }

    fprintf(saveFile, "\n");
    // save scoreboard
    for (i=0; i< mapGame.nEff; i++){
        if (i == mapGame.nEff - 1){
            if (IsEmptyMap(mapGame.ElmtListMap[i])){
                fprintf(saveFile, "%d", mapGame.ElmtListMap[i].Count);
            } else {
                fprintf(saveFile, "%d\n", mapGame.ElmtListMap[i].Count);
                int j, k;
                for (j=0; j<mapGame.ElmtListMap[i].Count-1; j++){
                    for (k=0; k<mapGame.ElmtListMap[i].Elements[j].name.length; k++){
                        fprintf(saveFile, "%c", mapGame.ElmtListMap[i].Elements[j].name.buffer[k]);
                    }
                    fprintf(saveFile, " %d\n", mapGame.ElmtListMap[i].Elements[j].score);
                }
                for (k=0; k<mapGame.ElmtListMap[i].Elements[j].name.length; k++){
                    fprintf(saveFile, "%c", mapGame.ElmtListMap[i].Elements[j].name.buffer[k]);
                }
                fprintf(saveFile, " %d", mapGame.ElmtListMap[i].Elements[j].score);
            }
        } else {
            fprintf(saveFile, "%d\n", mapGame.ElmtListMap[i].Count);
            if (!(IsEmptyMap(mapGame.ElmtListMap[i]))){
                int j, k;
                for (j=0; j<mapGame.ElmtListMap[i].Count; j++){
                    for (k=0; k<mapGame.ElmtListMap[i].Elements[j].name.length; k++){
                        fprintf(saveFile, "%c", mapGame.ElmtListMap[i].Elements[j].name.buffer[k]);
                    }
                    fprintf(saveFile, " %d\n", mapGame.ElmtListMap[i].Elements[j].score);
                }
            }
        }
    }

    fclose(saveFile);
    printf("\n");
    printf("Save file berhasil disimpan\n");
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
//     Word check2;
//     boolean cek = wordInput(&check2,1,10);
//     char s2[wordLength(check2) + 1];
//     wordToString(check2, s2);
//     savetoFile(s2, L);
//     return 0;
// }

//compile: gcc utility/save/save.c ADT/list/array.c ADT/word/word.c ADT/word/mesinkata/mesinkata.c ADT/word/mesinkarakter/mesinkarakter.c Misc/io/io.c Misc/ascii/ascii.c -o driver
