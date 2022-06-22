#include <stdio.h>
#include <stdint.h>

void swapBytes(uint16_t* word){
    uintptr_t x = *word;
    x = ((*word << 8) & 0xff00) | ((*word >> 8) & 0x00ff);
}

int main(){
    uint16_t number = 54328;
    swapBytes(&number);
    return 0;
}