#include "random.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_range(int Min, int Max) {

    int div = RAND_MAX / (Max + 1);
    int result = rand();

    while (result > Max) {
        result = rand() / div;
    }

    return (Min + result);

}

// int main() {

//     srand(time(NULL));

//     for (int i = 0; i < 100; i++) {

//         int x = random_range(0,100);
//         printf("%d\n",x);

//     }


// }