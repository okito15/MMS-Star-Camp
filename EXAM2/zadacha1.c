#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>

#define count 10
#define EPS 0.0001

typedef struct {
    char model[20];
    uint8_t maxspeed;
    double price;
} car;

int compareModelAsc(const void*, const void*);
int compareModelDesc(const void*, const void*);
int compareMaxSpeedAsc(const void*, const void*);
int compareMaxSpeedDesc(const void*, const void*);
int comparePriceAsc(const void*, const void*);
int comparePriceDesc(const void*, const void*);
int randInt(int, int);
double randDouble(double,double);
void printCars(car*,size_t);
int (*getComparator(int n))(const void*, const void*);

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

int compareModelAsc(const void* a, const void* b){
    return strcmp(((car*)a) -> model, ((car*)b) -> model);
}

int compareModelDesc(const void* a, const void* b){
    return strcmp(((car*)b) -> model, ((car*)a) -> model);
}
int compareMaxSpeedAsc(const void* a, const void* b){
    return ((car*)a) -> maxspeed - ((car*)b) -> maxspeed;
}

int compareMaxSpeedDesc(const void* a, const void* b){
    return ((car*)b) -> maxspeed - ((car*)a) -> maxspeed;
}

int comparePriceAsc(const void* a, const void* b){
    if(fabs((((car*)a) -> price - ((car*)b) -> price)) < EPS){
        return 0;
    } else if(((car*)a) -> price > ((car*)b) -> price){
        return 1;
    }
    return -1;
}

int comparePriceDesc(const void* a, const void* b){
    if(fabs((((car*)b) -> price - ((car*)a) -> price)) < EPS){
        return 0;
    } else if(((car*)b) -> price > ((car*)a) -> price){
        return 1;
    }
    return -1;
}

int randInt(int min, int max){
    return min + rand() % (max - min + 1);
}

double randDouble(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

void printCars(car* arr, size_t n){
    for(int i = 0; i < n; i++){
        printf("Model: %s, ", arr[i].model);
        printf("Max Speed: %u km/h, ", arr[i].maxspeed);
        printf("Price: %.2lf lv.\n", arr[i].price);
    }
}

int (*getComparator(int n))(const void*, const void*){ //стигнах до тук при подадено n, различно от 1 до 6 (което е грешно) реално изкарва 10 random коли, но не сортирани по никакъв начин, нямам време да я довърша
    if(n == 1){
        return compareModelAsc;
    } else if(n == 2){
        return compareModelDesc;
    } else if (n == 3){
        return compareMaxSpeedAsc;
    } else if (n == 4){
        return compareMaxSpeedDesc;
    } else if (n == 5){
        return comparePriceAsc;
    } else if (n == 6){
        return comparePriceDesc;
    } else return NULL;
}