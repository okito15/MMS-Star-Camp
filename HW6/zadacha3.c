#include <stdio.h>
#include <stdint.h>

#define TINT 1
#define TDOUBLE 2
#define TCHAR 3
#define TFLOAT 4
#define TUINT8_T 5
#define TUINT16_T 6
#define TUINT32_T 7
#define TUINT64_T 8

void printValue(const void*, uint8_t);

int main()
{
    int number = 500;
    double pi = 3.14159265359;
    char symbol = 'A';
    float floating = 1.05;
    uint8_t test1 = 150;
    uint16_t test2 = 55000;
    uint32_t test3 = 3000000000;
    uint64_t test4 = 1000000000000000;

    printValue(&number, TINT);
    printValue(&pi, TDOUBLE);
    printValue(&symbol, TCHAR);
    printValue(&floating, TFLOAT);
    printValue(&test1, TUINT8_T);
    printValue(&test2, TUINT16_T);
    printValue(&test3, TUINT32_T);
    printValue(&test4, TUINT64_T);

    return 0;
}

void printValue(const void* valuePtr, uint8_t flag)
{
    if(flag == 1)
    {
        printf("Value: %d\n", *(int*)valuePtr);
    }
    else if(flag == 2)
    {
        printf("Value: %lf\n", *(double*)valuePtr);
    }
    else if(flag == 3)
    {
        printf("Value: %c\n", *(char*)valuePtr);
    }
    else if(flag == 4)
    {
        printf("Value: %f\n", *(float*)valuePtr);
    }
    else if(flag == 5)
    {
        printf("Value: %u\n", *(uint8_t*)valuePtr);
    }
    else if(flag == 6)
    {
        printf("Value: %u\n", *(uint16_t*)valuePtr);
    }
    else if(flag == 7)
    {
        printf("Value: %lu\n", *(uint32_t*)valuePtr);
    }
    else if(flag == 8)
    {
        printf("Value: %llu\n", *(uint64_t*)valuePtr);
    }
}