#include <stdio.h>
#include "word.h"

int main()
{
    Word test, test1, concat, test3;
    createWord(&test);
    createWord(&test1);
    createWord(&test3);
    printf("%d\n", wordLength(test));
    test = stringToWord("hai");
    test1 = stringToWord("halo");
    copyWord(test, &test3);
    printWord(test3);
    printWord(test);
    printf("\n");
    if (isWordEqual(test, test1)) {
        printf("Sama\n");
    } else {
        printf("Tidak sama\n");
    }
    createWord(&concat);
    concateWord(test, test1, &concat);
    printWord(concat);
    printf("\n");
    char s[wordLength(test) + 1];
    wordToString(test, s);
    printf("%s\n", s);
    test = intToWord(123);
    Word a = stringToWord("123");
    int num = wordToInt(a);
    printf("print inttoword ");
    printWord(test);
    printf("\n");
    printf("print wordtoint %d\n", num);
    return 0;
}

// compile: gcc src/ADT/word/driverWord.c src/ADT/word/word.c src/Misc/ascii/ascii.c -o driver