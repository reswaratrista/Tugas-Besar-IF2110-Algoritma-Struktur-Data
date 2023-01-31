#include <stdio.h>
#include <stdlib.h>
#include "map.h"

void CreateEmptyMap(Map *M)
{
    (*M).Elements = (infotype*) malloc (InitialSize * sizeof(infotype));
    (*M).CapacityMap = InitialSize;
    (*M).Count = Nil;
}

void deallocateMap(Map *M)
{
    free((*M).Elements);
    (*M).CapacityMap = 0;
    (*M).Count = Nil;
}

void updateCapacityMap(Map *M)
{
    int newCapacity = 2 * InitialSize;
    infotype *newBuffer = (infotype*) malloc (newCapacity * sizeof(infotype));
    int i;
    for (i = 0; i < (*M).Count; i++){
        newBuffer[i] = (*M).Elements[i];
    }
    free((*M).Elements);
    (*M).Elements = newBuffer;
    (*M).CapacityMap = newCapacity;
}

boolean IsEmptyMap(Map M)
{
    return (M.Count == Nil);
}

boolean IsFullMap(Map M)
{
    return (M.Count == M.CapacityMap);
}

valuetype Value(Map M, keytype k)
{
    if (IsMemberMap(M, k)){
        boolean found = false;
        int i = 0;
        while (i < M.Count){
            if (isWordEqual(M.Elements[i].name, k)){
                return (M.Elements[i].score);
            }
            i++;
        }
    } else {
        return Undefined;
    }
    return 0;
}

void InsertMap(Map *M, keytype k, valuetype v)
{
    if (IsFullMap(*M)){
        updateCapacityMap(M);
    }

    if (!(IsMemberMap(*M, k))){
        (*M).Count++;
        (*M).Elements[(*M).Count-1].name = k;
        (*M).Elements[(*M).Count-1].score = v;
    }
}

void DeleteMap(Map *M, keytype k)
{
    if (IsMemberMap(*M, k)){
        boolean found = false;
        int i = 0;
        while (i < (*M).Count && (!found)){
            if (isWordEqual((*M).Elements[i].name, k)){
                found = true;
            } else {
                i++;
            }
        }

        int j;
        for (j=i; j<(*M).Count-1; j++){
            (*M).Elements[j].name = (*M).Elements[j+1].name;
            (*M).Elements[j].score = (*M).Elements[j+1].score;
        }
        (*M).Count--;
    }
}

boolean IsMemberMap(Map M, keytype k)
{
    boolean found = false;
    int i = 0;
    while (i < M.Count && (!found)){
        if (isWordEqual(M.Elements[i].name, k)){
            found = true;
        } else {
            i++;
        }
    }
    return found;
}

void PrintMap(Map M, Word GameName)
{
    printf("**** SCOREBOARD GAME ");
    printWord(GameName);
    printf(" ****\n");
    printf("| Nama           | SKOR           |\n");
    if(!(IsEmptyMap(M))){
        printf("|---------------------------------|\n");
        int i, j;
        for (i = 0; i<M.Count; i++){
            printf("| ");
            for (j=0; j<M.Elements[i].name.length; j++){
                printf("%c",M.Elements[i].name.buffer[j]);
            }
            int k;
            for(k = M.Elements[i].name.length; k<15; k++){
                printf(" ");
            }
            printf("| %-15d", M.Elements[i].score);
            printf("|\n");
        }
        printf("\n");
    }
    else {
        printf("------- SCOREBOARD KOSONG -------- \n\n");
    }
    printf("\n");
}

void inputData(Map *M, Set *S, int score)
{
    boolean repeat = true;
    while (repeat){
        printf("Masukkan nama: ");
        Word name;
        boolean valid = wordInput(&name, 1, 15);

        if (valid){
            // nama yang ada spasinya tidak valid
            int i=0;
            boolean cek = true;
            while (i<wordLength(name)){
                if (name.buffer[i] == ' '){
                    cek = false;
                }
                i++;
            }
            if (cek){
                if (InsertSet(S, name)){
                    InsertMap(M, name, score);
                    repeat = false;
                } else {
                    printf("Nama sudah ada di dalam scoreboard. Silakan masukkan nama lain.\n");
                }
            } else {
                printf("Nama tidak boleh mengandung spasi. Silakan masukkan nama lain.\n");
            }
        } else {
            if (wordLength(name) == 0){
                printf("Nama tidak boleh kosong. \n");
            } else {
                printf("Nama tidak boleh lebih dari 15 karakter. \n");
            }
        }
    }
}

void sortMap(Map *M)
{
    int i, j;
    for (i=0; i<(*M).Count-1; i++){
        for (j=i+1; j<(*M).Count; j++){
            if ((*M).Elements[i].score < (*M).Elements[j].score){
                infotype temp = (*M).Elements[i];
                (*M).Elements[i] = (*M).Elements[j];
                (*M).Elements[j] = temp;
            }
        }
    }
}