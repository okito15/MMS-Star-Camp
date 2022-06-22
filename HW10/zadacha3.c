#include <stdio.h>
#include <stdint.h>

#define COUNT 5

int clearBit(uint32_t* maskArr, size_t nitems, size_t bit){
    for(int i = 0; i < nitems; i++){
        maskArr[i] &= ~(1 << bit);
    }
    return 0;
}

int setBit(uint32_t* maskArr, size_t nitems, size_t bit){
    for(int i = 0; i < nitems; i++){
        maskArr[i] |= (1 << bit);
    }
    return 0;
}

int checkBit(uint32_t* maskArr, size_t nitems, size_t bit){
    return (maskArr[0] & (1 << bit)) >> bit;
}

void uint32ToBinary(uint32_t n){
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--){
        int bit = (n & (1 << i)) >> i;
        printf("%d", bit);
    }
    printf("\n");
}

int main()
{
    uint32_t arr[COUNT];
    setBit(arr, COUNT, 1);
    setBit(arr, COUNT, 2);
    setBit(arr, COUNT, 3);

    for(int i = 0; i < COUNT; i++){
        uint32ToBinary(arr[i]);
    }

    clearBit(arr, COUNT, 5);

    for(int i = 0; i < COUNT; i++){
        uint32ToBinary(arr[i]);
    }
    return 0;
}