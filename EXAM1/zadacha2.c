#include <stdio.h>
#include <inttypes.h>
#include <math.h>

int main() {
    uint64_t mask1;
    uint32_t mask2;
    uint16_t mask3;
    uint8_t mask4;
    unsigned int bitsNCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4);
    void flipOddBits(uint64_t* mask);

    scanf("%lu %d %hd %hhu", &mask1, &mask2, &mask3, &mask4);

    printf("%lu\n", bitsNCount(mask1, mask2, mask3, mask4));

    uint64_t mask = -1ul;
    flipOddBits(&mask);
    printf("Mask = %ul", mask);
    
    return 0;
}

unsigned int bitsNCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4) {
    int count = 0;

    while (mask1 > 0) {
        if (mask1 & 1)  {
            count++;
        }
        mask1 = mask1 >> 1;
    }

    while (mask2 > 0) {
        if (mask2 & 1)  {
            count++;
        }
        mask2 = mask2 >> 1;
    }

    while (mask3 > 0) {
        if (mask3 & 1)  {
            count++;
        }
        mask3 = mask3 >> 1;
    }

    while (mask4 > 0) {
        if (mask4 & 1)  {
            count++;
        }
        mask4 = mask4 >> 1;
    }
    return count;
}

void flipOddBits(uint64_t* mask) {
    for(int bit = 1; bit < sizeof(uint64_t) * __CHAR_BIT__; bit += 2){
        *mask ^= (1ULL);
    }

}

void mirrorBits(uint16_t* mask) {

}
