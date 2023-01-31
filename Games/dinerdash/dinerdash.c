#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dinerdash.h"

PQElType addOrder(int i){
    // i -> foodID
    srand(time(NULL));
    PQElType addOrder;
    addOrder.foodId = i;
    addOrder.cookTime = random_range(1,4);
    addOrder.stayTime = random_range(1,4);
    addOrder.price = random_range(1,8) * 5000 + 10000;
    return addOrder;  
}

void countAsTurn(ListDiner *Cook, ListDiner *Serve)
{
    // cek cook
    int j, i, donecooking = 0;
    List cooked, burnt;
    createList(&cooked);
    createList(&burnt);

    if (!isEmptyDiner(*Cook)){
        for (j = 0; j < (*Cook).nEff; j++){
            (*Cook).Data[j].cookTime--;
            if ((*Cook).Data[j].cookTime == 0){
                // masukin idx ke list cooked
                insertLast(&cooked, intToWord(j));

                // masukin ke serve
                insertLastDiner(Serve, (*Cook).Data[j]);
                printf("\nMakanan M%d telah selesai dimasak\n", (*Cook).Data[j].foodId);
                donecooking++;
            }
        }

        for (j = length(cooked); j > 0; j--){
            // hapus di list cook
            deleteAtDiner(Cook, wordToInt(cooked.A[j-1]));
        }
    }

    // cek serve
    if (!isEmptyDiner(*Serve)){
        for (i = 0; i < (*Serve).nEff - donecooking; i++){
            (*Serve).Data[i].stayTime--;
            if ((*Serve).Data[i].stayTime == 0){
                // masukin idx ke list burnt
                insertLast(&burnt, intToWord(i));

                printf("\nMasakan M%d telah hangus. Silahkan masak ulang.\n", (*Serve).Data[i].foodId);
            }
        }
        
        for (i = length(burnt); i > 0; i--){
            // hapus di list serve
            deleteAtDiner(Serve, wordToInt(burnt.A[i-1]));
        }  

    }
}

void dinerDash(ListMap *M, ListSet *S)
{
    header();

    dinerSplash();

    printf("\nTekan [ENTER] untuk melanjutkan...");
    blankInput();

    header();

    PrioQueue Order;
    ListDiner Cook;
    ListDiner Serve;
    createQueuePQ(&Order);
    createListDiner(&Cook);
    createListDiner(&Serve);

    // 3 order pertama (default)
    srand(time(NULL));
    int i;
    PQElType defaultOrder;
    for (i = 0; i < 3; i++){
        defaultOrder.foodId = i;
        defaultOrder.cookTime = random_range(1,4);
        defaultOrder.stayTime = random_range(1,4);
        defaultOrder.price = random_range(1,8) * 5000 + 10000;
        enqueuePQ(&Order, defaultOrder);
    }

    int saldo = 0;
    int custserved = 0;
    printf("SALDO: %d\n\n", saldo);

    printOrders(Order);
    printCookingDiner(Cook);
    printServingDiner(Serve);
    printf("\n");

    while (!isFullPQ(Order) && custserved < 15){
        // command
        List input;
        createList(&input);
        printf("\nMasukkan command: ");
        boolean valid = multiWordInput(&input, 1, 2);
        if (valid){
            if (length(input) == 1){
                if (isWordEqual(getElmt(input, 0), stringToWord("SKIP"))){
                    enqueuePQ(&Order, addOrder(i));
                    i++;

                    countAsTurn(&Cook, &Serve);
                } else {
                    printf("\nCommand tidak valid\n");
                }

            } else if (length(input) == 2){
                if (isWordEqual(getElmt(input, 0), stringToWord("COOK"))){
                    Word orderId = getElmt(input, 1);
                    int id = 0;
                    for (int k = 1; k < wordLength(orderId); k++){
                        id = id * 10 + (orderId.buffer[k] - '0');
                    }

                    // cek apakah id ada di queue
                    if (isMemberPQ(Order, id)){

                        // maks memasak 5 makanan di satu waktu
                        if (lengthDiner(Cook) < 5){
                            countAsTurn(&Cook, &Serve);
                            PQElType temp = getElmtPQ(Order, id);
                            insertLastDiner(&Cook, temp);
                            printf("\nBerhasil memasak M%d\n", id);

                            // nambah order baru
                            enqueuePQ(&Order, addOrder(i));
                            i++;
                        } else {
                            // tidak dihitung sebagai putaran
                            printf("\nMeja memasak penuh\n");
                        }
                    } else {
                        // tidak dihitung sebagai putaran
                        printf("\nOrder tidak ditemukan\n");
                    }
                } else if (isWordEqual(getElmt(input, 0), stringToWord("SERVE"))){
                    Word orderId = getElmt(input, 1);
                    int id = 0;
                    for (int k = 1; k < wordLength(orderId); k++){
                        id = id * 10 + (orderId.buffer[k] - '0');
                    }

                    if (isMemberListDiner(Serve, id)){
                        // first come, first served
                        if (HEAD(Order).foodId == id){
                            PQElType temp;
                            int idx = getidxDiner(Serve, id);
                            deleteAtDiner(&Serve, idx);
                            dequeuePQ(&Order, &temp);
                            printf("\nBerhasil mengantar M%d\n", temp.foodId);
                            custserved++;
                            saldo += temp.price;

                            countAsTurn(&Cook, &Serve);

                            // nambah order baru
                            enqueuePQ(&Order, addOrder(i));
                            i++;
                        } else {
                            // tidak dihitung sebagai putaran
                            printf("\nMakanan M%d tidak dapat disajikan karena M%d belum selesai\n", id, HEAD(Order).foodId);
                        }
                    } else {
                        // tidak dihitung sebagai putaran
                        printf("\nMakanan tidak ditemukan dalam antrian hidangan yang siap disajikan\n");
                    }

                } else {
                    printf("\nCommand tidak valid\n");
                }
            } else {
                printf("\nCommand tidak valid\n");
            }
        } else {
            printf("\nCommand tidak valid\n");
        }
       
        printf("===================================================\n");

        printf("\n");
        printf("SALDO: %d\n\n", saldo);
        printOrders(Order);
        printCookingDiner(Cook);
        printServingDiner(Serve);
        printf("\n \n");

    }
        
    printf("==================== GAME OVER ====================\n");
    
    if (custserved == 15){
        printf("\nAnda menang! Anda berhasil melayani 15 pelanggan!\n");
    } else {
        printf("\nAnda kalah! Antrian penuh dengan pelanggan kecewa!\n");
    }
    printf("\nSkor Anda: %d\n", saldo);
    inputDataListMap(M, S, 1, saldo);
}

void dinerSplash()
{
printf("WELCOME TO DINER DASH!     \n\n");    
printf("        .--,--.             \n");
printf("        `.  ,.'             \n");
printf("         |___|              \n");
printf("         :o o:   O          \n");    
printf("        _`~^~'_  |          \n");    
printf("      /'   ^   `\\=)         \n");         
printf("    .'  _______ '~|         \n");
printf("    `(<=|     |= /'         \n");
printf("        |     |             \n");
printf("        |_____|             \n");
printf(" ~~~~~~~ ===== ~~~~~~~~     \n");
printf("\n");
printf("           SERVE or be SERVED \n");

}

// int main(){
//     ListMap M;
//     ListSet S;
//     dinerDash(&M, &S);
//     return 0;
// }

// compile : gcc src/ADT/map/map.c src/ADT/map/listMap.c src/ADT/set/set.c src/ADT/set/listSet.c src/Games/random.c src/Games/dinerdash/dinerdash.c src/ADT/list/listDiner.c src/ADT/word/mesinkarakter/mesinkarakter.c src/ADT/word/mesinkata/mesinkata.c src/ADT/queue/prioqueue.c src/Misc/io/io.c src/ADT/word/word.c src/Misc/ascii/ascii.c src/ADT/list/array.c -o driver