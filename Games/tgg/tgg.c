#include <stdio.h>
#include "tgg.h"

boolean yesno()
{
    boolean done = false;
    while (!done){
        printf("\nEnter [y] for yes or [n] for no: ");
        Word input;
        createWord(&input);
        boolean valid = wordInput(&input, 1, 1);
        if (valid){
            if (isWordEqual(input, stringToWord("y")) || isWordEqual(input, stringToWord("Y"))){
                return false;
            } else if (isWordEqual(input, stringToWord("n")) || isWordEqual(input, stringToWord("N"))){
                return true;
            } else {
                printf("\nInvalid input! Please try again.\n");
            }
        } else {
            printf("\nInvalid input! Please try again.\n");
        }
    }
    return false;
}

int moveInTree(BinTree T)
{
    header();
    // yes -> left no -> right
    if (ROOT(T) == 0){
        printf("Is it big?\n");
        if (yesno()){  
            moveInTree(RIGHT(T));
        } else {
            moveInTree(LEFT(T));
        }
    } else if (ROOT(T) == 1){
        printf("Does it lay eggs?\n");
        if (yesno()){  
            moveInTree(RIGHT(T));
        } else {
            moveInTree(LEFT(T));
        }
    } else if (ROOT(T) == 2){
        printf("Is it a mammal?\n");
        if (yesno()){  
            moveInTree(RIGHT(T));
        } else {
            moveInTree(LEFT(T));
        }
    } else if (ROOT(T) == 3){
        printf("Is it a reptile?\n");
        if (yesno()){  
            moveInTree(RIGHT(T));
        } else {
            moveInTree(LEFT(T));
        }
    } else if (ROOT(T) == 4 || ROOT(T) == 7 || ROOT(T) == 8 || ROOT(T) == 13 || ROOT(T) == 14){
        printf("Can it live underwater?\n");
        if (yesno()){  
            moveInTree(RIGHT(T));
        } else {
            moveInTree(LEFT(T));
        }
    } else if (ROOT(T) == 5 || ROOT(T) == 6){
        printf("Is it a carnivore?\n");
        if (yesno()){  
            moveInTree(RIGHT(T));
        } else {
            moveInTree(LEFT(T));
        }
    } else if (ROOT(T) == 9){
        printf("Does it travel in groups?\n");
        if (yesno()){  
            moveInTree(RIGHT(T));
        } else {
            moveInTree(LEFT(T));
        }
    } else if (ROOT(T) == 10){
        printf("Is it a predator?\n");
        if (yesno()){  
            moveInTree(RIGHT(T));
        } else {
            moveInTree(LEFT(T));
        }
    } else if (ROOT(T) == 11 || ROOT(T) == 12){
        printf("Is it a house pet?\n");
        if (yesno()){  
            moveInTree(RIGHT(T));
        } else {
            moveInTree(LEFT(T));
        }
    } else if (ROOT(T) == 15){
        printf("Ohh, I know!\n");
        printf("It's a CROCODILE, isn't it?\n");
        if (yesno()){  
            return 100;
        } else {
            return 0;
        }
    } else if (ROOT(T) == 16){
        printf("Ohh, I know!\n");
        printf("It's a KOMODO, isn't it?\n");
        if (yesno()){  
            return 100;
        } else {
            return 0;
        }
    } else if (ROOT(T) == 17){
        printf("Ohh, I know!\n");
        printf("It's a SHARK, isn't it?\n");
        if (yesno()){  
            return 100;
        } else {
            return 0;
        }
    } else if (ROOT(T) == 18){
        printf("Ohh, I know!\n");
        printf("It's an ORCHID, isn't it?\n");
        if (yesno()){  
            return 100;
        } else {
            return 0;
        }
    } else if (ROOT(T) == 19){
        printf("Ohh, I know!\n");
        printf("It's a DOLPHIN, isn't it?\n");
        if (yesno()){  
            return 100;
        } else {
            return 0;
        }
    } else if (ROOT(T) == 20){
        printf("Ohh, I know!\n");
        printf("It's a WHALE, isn't it?\n");
        if (yesno()){  
            return 100;
        } else {
            return 0;
        }
    } else if (ROOT(T) == 21){
        printf("Ohh, I know!\n");
        printf("It's a LION, isn't it?\n");
        if (yesno()){  
            return 100;
        } else {
            return 0;
        }
    } else if (ROOT(T) == 22){
        printf("Ohh, I know!\n");
        printf("It's an ELEPHANT, isn't it?\n");
        if (yesno()){  
            return 100;
        } else {
            return 0;
        }
    } else if (ROOT(T) == 23){
        printf("Ohh, I know!\n");
        printf("It's a CAT, isn't it?\n");
        if (yesno()){  
            return 100;
        } else {
            return 0;
        }
    } else if (ROOT(T) == 24){
        printf("Ohh, I know!\n");
        printf("It's a SNAKE, isn't it?\n");
        if (yesno()){  
            return 100;
        } else {
            return 0;
        }
    } else if (ROOT(T) == 25){
        printf("Ohh, I know!\n");
        printf("It's a RABBIT, isn't it?\n");
        if (yesno()){  
            return 100;
        } else {
            return 0;
        }
    } else if (ROOT(T) == 26){
        printf("Ohh, I know!\n");
        printf("It's a KOALA, isn't it?n");
        if (yesno()){  
            return 100;
        } else {
            return 0;
        }
    } else if (ROOT(T) == 27){
        printf("Ohh, I know!\n");
        printf("It's a CATFISH, isn't it?\n");
        if (yesno()){  
            return 100;
        } else {
            return 0;
        }
    } else if (ROOT(T) == 28){
        printf("Ohh, I know!\n");
        printf("It's an OWL, isn't it?\n");
        if (yesno()){  
            return 100;
        } else {
            return 0;
        }
    } else if (ROOT(T) == 29){
        printf("Ohh, I know!\n");
        printf("It's a NEMO, isn't it?\n");
        if (yesno()){  
            return 100;
        } else {
            return 0;
        }
    } else if (ROOT(T) == 30){
        printf("Ohh, I know!\n");
        printf("It's a PARROT, isn't it?\n");
        if (yesno()){  
            return 100;
        } else {
            return 0;
        }
    }   
}

void guessingGenie(ListMap *M, ListSet *S)
{
//                              0
//                 /                             \\
//               1                                2
//          /         \\                     /         \\  
//         3           4                    5            6
//      /     \\    /     \\             /     \\     /     \\
//     7       8   9       10           11       12  13       14
//    / \     / \  / \     / \         / \     / \   / \     / \
//  15   16 17  18 19 20 21   22     23  24   25 26 27  28  29  30


    header();

    genieSplash();

    printf("Press [ENTER] to continue...");
    blankInput();

    BinTree T = NewTree(0,NewTree(1,NewTree(3,NewTree(7,NewTree(15,NULL,NULL),NewTree(16,NULL,NULL)),NewTree(8,NewTree(17,NULL,NULL),NewTree(18,NULL,NULL))),NewTree(4,NewTree(9,NewTree(19,NULL,NULL),NewTree(20,NULL,NULL)),NewTree(10,NewTree(21,NULL,NULL),NewTree(22,NULL,NULL)))),NewTree(2,NewTree(5,NewTree(11,NewTree(23,NULL,NULL),NewTree(24,NULL,NULL)),NewTree(12,NewTree(25,NULL,NULL),NewTree(26,NULL,NULL))),NewTree(6,NewTree(13,NewTree(27,NULL,NULL),NewTree(28,NULL,NULL)),NewTree(14,NewTree(29,NULL,NULL),NewTree(30,NULL,NULL)))));
    int score = moveInTree(T);
    if (score == 100){
        printf("\nYOU WIN :( I can't guess what you're thinking of!\n\n");
        printf("Your final score: %d\n", score);
    } else {
        printf("\nYOU LOSE! Your mind is so predictable :D\n\n");
        printf("Your final score: %d\n", score);
    }

    inputDataListMap(M, S, 6, score);
    
}

void genieSplash()
{
printf("\nWELCOME TO THE GAME!\n\n");

printf("                _.---.___               \n");
printf("             /      ____  \\            \n");
printf("            \\/  / /    |_/             \n");
printf("             `\\/|/    _(_)             \n");
printf("           ___  /|_.--'    `.   .       \n");
printf("          \\  `--' .---.    \\ /|       \n");
printf("            )   `       \\     //|       \n");
printf("            | __    __   |   '/||       \n");
printf("            |/  \\  /  \\      / ||       \n");
printf("           \\|  |  |   /        |       \n");
printf("           __\\@/  |@ | ___ \\--'        \n");    
printf("          (     /' `--'  __)|           \n");
printf("         __>   (  .  .--' & \\           \n");
printf("        |   `--|_/--'     &  |          \n");
printf("         \\              ,ad#'           \n");
printf("          `.________.ad####'            \n");
printf("            `#####""""""''              \n");
printf("              &#   &                     \n");
printf("               #__//                    \n");

printf("\n                          MEET OUR GUESSING GENIE!\n");

printf("\n\nThink of an ANIMAL!\n"); 
printf("I bet i can guess what animal you're thinking of with just 5 questions!\n\n");
}

// int main()
// {
//     ListMap M;
//     ListSet S;
//     guessingGenie(&M, &S);
//     // genieSplash();
//     return 0;

// }


// compile : gcc src/ADT/map/map.c src/ADT/map/listMap.c src/ADT/set/set.c src/ADT/set/listSet.c src/Utility/splash.c src/ADT/list/array.c src/Misc/ascii/ascii.c src/Misc/io/io.c src/ADT/word/mesinkata/mesinkata.c src/ADT/word/mesinkarakter/mesinkarakter.c src/ADT/word/word.c src/Games/tgg/tgg.c src/ADT/tree/tree.c -o driver