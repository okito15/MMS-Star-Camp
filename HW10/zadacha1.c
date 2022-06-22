#include <stdio.h>
#include <stdint.h>

int main(){
    uint32_t number;
    scanf("%lu", &number);

    for(int i = sizeof(number) * 8 - 1; i >= 0 ; i--){
        int bit = (number & (1 << i)) >> i;
        printf("%d", bit);
    }
    return 0;
}