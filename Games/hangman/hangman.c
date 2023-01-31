#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hangman.h"
static FILE *saveFileKata;

void inputGuess(List Guesses, Word *guess) {
    boolean repeat = true;
    while (repeat){
        printf("\nMasukkan tebakan Anda: ");
        boolean valid = wordInput(guess,1,1);
        if (valid) {
            // lower((*guess).buffer[0]);
            if ((*guess).buffer[0] >= 'A' && (*guess).buffer[0] <= 'Z') {
                (*guess).buffer[0] += 32;
            }

            if (isMemberList(Guesses, *guess)) {
                printf("Anda sudah pernah menebak huruf %c\n", (*guess).buffer[0]);
                printf("Silakan masukkan huruf lain\n\n");
            } else {
                repeat = false;
            }
        } else {
            if (wordLength(*guess) == 0) {
                printf("Tebakan tidak boleh kosong!\n");
                printf("\n");
            } else {
                printf("Tebakan hanya boleh 1 huruf!\n");
                printf("\n");
            }
        }
    }
}

void man(int chance){
    header();
    if (chance>=1 && chance<=10){
        printf("THIS HANGED MAN IS ABOUT TO BE YOU!\n\n");
        if (chance == 9){
            one();
        } else if (chance == 8){
            two();
        } else if (chance == 7){
            three();
        } else if (chance == 6){
            four();
        } else if (chance == 5){
            five();
        } else if (chance == 4){
            six();
        } else if (chance == 3){
            seven();
        } else if (chance == 2){
            eight();
        } else if (chance == 1){
            nine();
        } else if (chance == 10){
            zero();
        } 
    } else {
        if (chance == 0){
            printf("YOU'RE DEAD! GOODBYE :D\n\n");
            ten();
        }
    }
    // toContinue();
}

void toContinue(){
    printf("Tekan [ENTER] untuk melanjutkan...");
    startKata(false, "");
}

void displayKata(List L){
    int i;
    for (i=0; i<length(L); i++){
        printf("%c", getElmt(L,i).buffer[0]);
    }
    printf("\n");
}

Word randomWord(List L){
    Word randomword;
    boolean valid = true;
    int Num;
    while(valid){
        srand(time(NULL));
        Num = random_range(0, length(L)-1);
        if (Num>=0 && Num<length(L)){
            valid = false;
        }
    }
    randomword = getElmt(L, Num);
    
    return randomword;
}

void readListKata(List *ListKata){
    Word file;
    concateWord(stringToWord("src/Games/hangman/"), stringToWord("listKata.txt"), &file);

    char a[wordLength(file) + 1];
    wordToString(file, a);

    startKata(true, a);

    while (!endKata) {
        insertLast(ListKata, currentKata);
        advKata();
    }
}

void addToListKata(List *L){
    boolean repeat = true;
    Word kata;
    while (repeat){
        header();
        printf("Masukkan kata yang ingin Anda tambahkan ke dictionary kata: ");
        
        boolean valid = wordInput(&kata, 1, 50);
        if (valid){
            // all uppercase
            int k;
            for(k=0; k<kata.length; k++){
                // upper(kata.buffer[k]);
                if (kata.buffer[k] >= 'a' && kata.buffer[k] <= 'z'){
                    kata.buffer[k] -= 32;
                }
            }
            if (isMemberList(*L, kata)) {
                printf("Kata sudah ada di dalam dictionary kata!\n\n");
                toContinue();
            } else {
                // kata yang ada spasinya tidak valid
                int i=0;
                boolean cek = true;
                while (i<wordLength(kata)){
                    if (kata.buffer[i] == ' '){
                        cek = false;
                    }
                    i++;
                }

                if (cek){
                    insertLast(L, kata);
                    printf("Kata berhasil ditambahkan ke dictionary kata!\n\n");
                    toContinue();
                    Word yesnoinput;
                    boolean loop = true;
                    while (loop){
                        header();
                        printf("Apakah Anda ingin menambahkan kata lain? (Y/N)\n");
                        printf("Silahkan masukkan pilihan Anda: ");
                        boolean ans = wordInput(&yesnoinput, 1, 1);
                        if (ans){
                            if (yesnoinput.buffer[0] == 'Y' || yesnoinput.buffer[0] == 'y'){
                                loop = false;
                                repeat = true;
                            } else if (yesnoinput.buffer[0] == 'N' || yesnoinput.buffer[0] == 'n'){
                                loop = false;
                                repeat = false;
                            } else {
                                printf("Input tidak valid!\n");
                                printf("Masukkan Y/N!\n\n");
                                toContinue();
                            }
                        } else {
                            printf("Input tidak valid!\n");
                            printf("Masukkan Y/N!\n\n");
                            toContinue();
                        }
                    }
                } else {
                    printf("Kata tidak boleh mengandung spasi!\n\n");
                    toContinue();
                }
            }
        } else {
            if (wordLength(kata) == 0) {
                printf("Kata tidak boleh kosong!\n");
                printf("\n");
                toContinue();
            } else {
                printf("Kata melebihi batas karakter!\n");
                printf("Kata hanya boleh 1-50 huruf!\n");
                printf("\n");
                toContinue();
            }
        }
    }
}

void saveListKata(List L){
    Word file;
    concateWord(stringToWord("src/Games/hangman/"), stringToWord("listKata.txt"), &file);

    char a[wordLength(file) + 1];
    wordToString(file, a);

    saveFileKata = fopen(a, "w");
    int i, j;
    for (i=0; i<length(L); i++){
        for (j=0; j<L.A[i].length; j++){
            fprintf(saveFileKata, "%c", L.A[i].buffer[j]);
        }
        if (i < length(L)-1) {
            fprintf(saveFileKata, "\n");
        }
    }

    fclose(saveFileKata);
}

void playHangman(List L, ListMap *M, ListSet *S)
{
    int chance = 10;
    Word guess;
    Word randWord;
    int i;

    List GuessWord, kata, Guesses;
    createList(&GuessWord);
    createList(&kata);
    createList(&Guesses);

    boolean cek;
    int valid;
    int score = 0;
    while (chance != 0){
        randWord = randomWord(L);
        for (i=0; i<wordLength(randWord); i++){
            insertLast(&GuessWord, charToWord(randWord.buffer[i]));
        }

        for (i=0; i<length(GuessWord); i++){
            insertLast(&kata, stringToWord("_"));
        }

        valid = 0;
        while (valid != length(GuessWord) && chance != 0){
            header();
            if (isEmpty(Guesses)){
                printf("Tebakan sebelumnya:-\n");
            } else {
                printf("Tebakan sebelumnya: ");
                displayKata(Guesses);
            }
            printf("Kata: ");
            displayKata(kata);
            printf("Sisa kesempatan: %d\n", chance);
            inputGuess(Guesses, &guess);
            insertLast(&Guesses, guess);

            cek = false;
            for (i=0; i<length(GuessWord); i++){
                char uppercase = upper(wordToChar(guess));
                if (isWordEqual(charToWord(uppercase), getElmt(GuessWord,i))){
                    Word kar = charToWord(upper(guess.buffer[0]));
                    setElmt(&kata, i, kar);
                    cek = true;
                    valid++;
                }
            }

            if (cek){
                printf("Selamat, Tebakan Anda benar!\n\n");
                toContinue();
            } else {
                printf("Tebakan Anda salah!\n");
                printf("Kesempatan Anda berkurang!\n\n");
                chance--;
                toContinue();
            }
            printf("\n");
            man(chance);
            printf("Nyawa Anda tersisa %d\n\n", chance);
            toContinue();
        }

        header();
        if (valid == length(GuessWord)){
            printf("Selamat, Anda berhasil menebak kata!\n");
            printf("Kata yang harus ditebak: ");
            displayKata(GuessWord);
            printf("\nSkor Anda bertambah %d poin!\n", valid);
            score += valid;
            printf("Skor Anda: %d\n", score);
            printf("Silahkan lanjut ke kata selanjutnya!\n\n");
            toContinue();
        }

        // kosonging semua list
        if (chance != 0){
            while (!isEmpty(GuessWord)){
                deleteFirst(&GuessWord);
            }
            while (!isEmpty(kata)){
                deleteFirst(&kata);
            }
            while (!isEmpty(Guesses)){
                deleteFirst(&Guesses);
            }
        }

        // benerin newline
        printf("\n");
    }

    header();
    if (chance == 0){
        printf("Anda kalah!\n");
        printf("Kata yang harus ditebak: ");
        displayKata(GuessWord);
        printf("Skor Anda: %d\n\n", score);
    } else {
        printf("Anda menang!\n");
        printf("Skor Anda: %d\n\n", score);
    }

    inputDataListMap(M, S, 2, score);
    toContinue();

    boolean loop = true;
    Word yesnoinput;
    while (loop){
        header();
        printf("Apakah Anda ingin bermain lagi? (Y/N)\n");
        printf("Silahkan masukkan pilihan Anda: ");
        boolean ans = wordInput(&yesnoinput, 1, 1);
        if (ans){
            if (yesnoinput.buffer[0] == 'Y' || yesnoinput.buffer[0] == 'y'){
                playHangman(L, M, S);
                loop = false;
            } else if (yesnoinput.buffer[0] == 'N' || yesnoinput.buffer[0] == 'n'){
                printf("Terima kasih telah bermain!\n\n");
                toContinue();
                loop = false;
            } else {
                printf("Input tidak valid!\n");
                printf("Masukkan Y/N!\n\n");
                toContinue();
            }
        } else {
            printf("Input tidak valid!\n");
            printf("Masukkan Y/N!\n\n");
            toContinue();
        }
    }
}

void hangman(ListMap *M, ListSet *S)
{
    header();
    
    hangmanSplash();

    toContinue();
    header();

    // baca list kata dari listKata.txt
    List L;
    createList(&L);
    readListKata(&L);

    Word input;
    boolean repeat = true;
    while (repeat){
        header();
        printf("Silakan pilih mode permainan:\n");
        printf("1. Bermain Hangman\n");
        printf("2. Menambah kata ke dictionary kata untuk permainan Hangman\n\n");
        printf("Silahkan masukkan pilihan Anda: ");
        boolean valid = wordInput(&input,1,1);
        if (valid){
            if (input.buffer[0] == '1'){
                playHangman(L, M, S);
                repeat = false;
            } else if (input.buffer[0] == '2'){
                addToListKata(&L);
                Word yesnoinput;
                boolean loop = true;
                while (loop){
                    header();
                    printf("Apakah Anda ingin bermain Hangman? (Y/N)\n");
                    printf("Silahkan masukkan pilihan Anda: ");
                    boolean ans = wordInput(&yesnoinput, 1, 1);
                    if (ans){
                        if (yesnoinput.buffer[0] == 'Y' || yesnoinput.buffer[0] == 'y'){
                            playHangman(L, M, S);
                            loop = false;
                        } else if (yesnoinput.buffer[0] == 'N' || yesnoinput.buffer[0] == 'n'){
                            printf("Terima kasih telah bermain!\n\n");
                            toContinue();
                            loop = false;
                        } else {
                            printf("Input tidak valid!\n");
                            printf("Masukkan Y/N!\n\n");
                            toContinue();
                        }
                    } else {
                        printf("Input tidak valid!\n");
                        printf("Masukkan Y/N!\n\n");
                        toContinue();
                    }
                }
                repeat = false;
            } else {
                printf("Masukan pilihan Anda salah!\n");
                printf("Masukkan 1 atau 2!\n\n");
                toContinue();
            }
        } else {
            printf("Masukan pilihan Anda salah!\n");
            printf("Masukkan 1 atau 2!\n\n");
            toContinue();
        }
    }

    saveListKata(L);
}

void hangmanSplash()
{
printf("              WELCOME TO HANGMAN!           \n\n");
printf("                     ___________.._______           \n");
printf("                    | .__________))______|          \n");
printf("                    | | / /      ||                 \n");
printf("                    | |/ /       ||                 \n");
printf("                    | | /        ||.-''.            \n");
printf("                    | |/         |/  _  \\           \n");
printf("                    | |          ||  `/,/           \n");
printf("                    | |          (\\`_.'            \n");
printf("                    | |         .-`--'.             \n");
printf("                    | |        /Y     Y\\            \n");
printf("                    | |       // |   | \\\\           \n");
printf("                    | |      //  |   |  \\\\          \n");
printf("                    | |     ')   |   |   (`         \n");
printf("                    | |          || ||              \n");
printf("                    | |          || ||              \n");
printf("                    | |          || ||              \n");
printf("                    | |          || ||              \n");
printf("                    | |         / | | \\             \n");
printf("                                `-' `-'            \n");
printf("\n\n");
printf("                            Guess the COUNTRY or else ...\n");
printf("\n\n");
}

// int main()
// {
//     hangmanSplash();
//     // List L;
//     // createList(&L);
//     // readListKata(&L);
//     // addToListKata(&L);
//     // saveListKata(L);

//     // ListMap M;
//     // createListMap(&M);
//     // hangman(&M);

//     hangman();

//     // toContinue();
//     return 0;
// }

// compile : gcc src/ADT/map/listMap.c src/ADT/set/listSet.c src/ADT/set/set.c src/ADT/map/map.c src/Games/hangman/man.c src/Utility/splash.c src/Games/random.c src/Games/hangman/hangman.c src/ADT/list/array.c src/ADT/word/mesinkata/mesinkata.c src/ADT/word/mesinkarakter/mesinkarakter.c src/ADT/word/word.c src/Misc/ascii/ascii.c src/Misc/io/io.c -o driver