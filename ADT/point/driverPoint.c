#include <stdio.h>
#include "point.h"

int main()
{
    Point p;
    createPoint(&p, 1, 2);
    if(isOrigin(p)){
        printf("p di titik asal\n");
    } else {
        printf("p tidak di titik asal\n");
    }
    if(isFirstQuadrant(p)){
        printf("p di kuadran pertama\n");
    } else {
        printf("p tidak di kuadran pertama\n");
    }
    Point X = translate(p, 1, 1);
    printf("p ditranslasi ke titik X(%d, %d)\n", ABSCISSA(X), ORDINATE(X));
    movePoint(&p, 1, 1);
    printf("p digeser ke (%d, %d)\n", ABSCISSA(p), ORDINATE(p));
    return 0;
}

// compile : gcc src/ADT/point/driverPoint.c src/ADT/point/point.c -o driver