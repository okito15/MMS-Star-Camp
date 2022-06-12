#include <stdio.h>
#include <stdint.h>

unsigned int onesCount(uint64_t mask){
    unsigned int count = 0;
    while (mask) {
        count += mask & 1;
        mask >>= 1;
    }
    return count;
}

int main(){
    uint64_t mask = 1ULL;
    printf("Number of 1s in the mask is %u\n", onesCount(mask));
    return 0;
}