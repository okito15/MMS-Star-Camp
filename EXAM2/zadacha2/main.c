#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include "car.h"
#include "car.c"

int main(){
    srand(time(NULL));
    car cars[count];

    for(int i = 0; i < count; i++){
        cars[i].price = randDouble(1000.00, 100000.00);
        cars[i].maxspeed = randInt(100, 300);
        int countLowercase = randInt(4, 10);
        cars[i].model[0] = randInt('A', 'Z');
        for(int j = 1; j < countLowercase; j++){
            cars[i].model[j] = randInt('a', 'z');
        }
        cars[i].model[countLowercase] = 0;
    }

    int n;
    printf("Enter number between 1 and 6: ");
    scanf("%d\n", &n);
    
    qsort(cars, count, sizeof(cars), getComparator(n));
    printCars(cars, count);

    return 0;
}