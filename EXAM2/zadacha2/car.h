#ifndef _CAR_H__
#define _CAR_H__

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

#endif