#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>

unsigned bitsNCount(unsigned count, unsigned bitscnt, ...);

int main() {
    printf("%u\n", bitsNCount(4, 2, 0x0a, 0xff, 0, 1));
    printf("%u\n", bitsNCount(3, 8, 0xff, 0x13f1, 0xaaaa));
    printf("%u\n", bitsNCount(5, 10, 0x0a, 0xa0ff, 0, 10, 0b1010111110111)); // тук изкарва 1 вместо 2, не знам защо

    return 0;
}

unsigned bitsNCount(unsigned count, unsigned bitscnt, ...){
    int total = 0;
    uint64_t mask;

    va_list args;
    va_start(args, bitscnt);
    while ((mask = va_arg(args, uint64_t)) > 0){
    int count1sMask = 0;

       for (int bit = 0; bit < sizeof(uint64_t) * __CHAR_BIT__; bit++){
        count1sMask += (mask & (1UL << bit)) >> bit;
        }
            if(count1sMask == bitscnt){
            total++;
            }
    }
    va_end(args);

    return total;
}