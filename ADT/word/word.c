/* FILE         : word.c */
/* DESKRIPSI    : Implementasi ADT Word (pengganti string) */

#include <stdio.h>
#include <math.h>
#include "word.h"

/* Membuat kata kosong dengan panjang 0 */
void createWord(Word *w) {

    w->length = 0;

}

/* Menggabung w1 dan w2 dan menyimpannya di w3 */
void concateWord(Word w1, Word w2, Word *w3) {

    int length = wordLength(w1) + wordLength(w2);

    if (length > N_MAX) {
        length = N_MAX;
    }

    for (int i = 0; i < wordLength(w1); i++) {
        w3->buffer[i] = w1.buffer[i];
    }

    for (int i = 0; i < wordLength(w2); i++) {
        w3->buffer[wordLength(w1) + i] = w2.buffer[i];
    }

    wordLength(*w3) = length;

}

/* Menggabung w1 dan w2 dan menyimpannya di w3 */
void copyWord(Word w1, Word *w2) {

    for (int i = 0; i < wordLength(w1); i++) {
        w2->buffer[i] = w1.buffer[i];
    }

    wordLength(*w2) = wordLength(w1);

}

/* Merubah sebuah integer menjadi sebuah word */
Word intToWord(int i) {

    Word w;
    createWord(&w);

    int temp = i;

    int j = 0;

    do {
        temp = temp / 10;
        j = j + 1;
    } while (temp != 0);

    wordLength(w) = j;

    int k = 0;

    do {
        w.buffer[j-1-k] = intToChar(i % 10);
        i = i / 10;
        k = k + 1;
    } while (i != 0);

    return w;

}

Word charToWord(char s)
{
    Word w;
    createWord(&w);
    w.buffer[0] = s;
    wordLength(w) = 1;
    return w;
}

char wordToChar(Word s){
    char kar;
    kar = s.buffer[0];
    return kar;
}

/* Merubah sebuah string menjadi sebuah word */
Word stringToWord(char *s) {

    Word w;
    createWord(&w);

    boolean end = false;
    int i = 0;

    while (!end) {
        if (s[i] == '\0') {
            end = true;
        } else {
            w.buffer[i] = s[i];
            i = i + 1;
        }
    }

    wordLength(w) = i;

    return w;

}

/* Merubah sebuah kata menjadi suatu integer, apabila word bukan integer yang valid maka akan mengembalikan INT_INVALID */
int wordToInt(Word w) {

    long i = 0;
    boolean valid = true;
    boolean neg = false;
    
    int j = 0;
    while (j < wordLength(w) && valid) {
        if (isNumeric(w.buffer[j])) {
            long x = i*10 + (charToInt(w.buffer[j]));
            if (x > 0x7FFFFFFF) {
                i = INVALID_INT;
                valid = false;
            } else {
                i = i*10 + (charToInt(w.buffer[j]));
            }
            j = j + 1;
        } else if (j == 0 && w.buffer[j] == '-') {
            neg = true;
        } else {
            i = INVALID_INT;
            valid = false;
        }
    }

    if (neg) {
        i = i * -1;
    }

    return i;
    // int num = 0, i;
    // for (i = 0; i < wordLength(w); i++) {
    //     num = num*10 + (w.buffer[i] - '0');
    // }
    // return num;
}

/* Merubah sebuah word menjadi suatu string dan menyimpannya di s. PENTING: DEFINISIKAN S TERLEBIH DAHULU DENGAN KAPASITAS WORDLENGTH + 1 */
/* JANGAN DIPAKE KECUALI LU TAU LAGI NGAPAIN */
void wordToString(Word w, char *s) {

    int length = wordLength(w);

    int i = 0;
    while (i < length) {
        s[i] = w.buffer[i];
        i = i + 1;
    }

    s[length] = '\0';

}

/* Mengecek apakah dua buah kata merupakan kata yang sama */
boolean isWordEqual(Word w1, Word w2) {

    boolean equal = (wordLength(w1) == wordLength(w2));

    int i = 0;
    while (equal && i < wordLength(w1)) {
        if (w1.buffer[i] != w2.buffer[i]) {
            equal = false;
        }
        i = i + 1;
    }

    return equal;

}

/* Mencetak sebuah word ke layar, tanpa tambahan karakter didepan + dibelakangnya */
void printWord(Word w) {

    for (int i = 0; i < wordLength(w); i++) {
        printf("%c",w.buffer[i]);
    }

}