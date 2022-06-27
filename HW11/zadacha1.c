#include <stdio.h>

#define MAX(x,y,z) ((x)>(y)?((x)>(z)?(x):(z)):((y)>(z)?(y):(z)))
#define MIN(x,y,z) ((x)<(y)?((x)<(z)?(x):(z)):((y)<(z)?(y):(z)))
#define SETBIT(mask, bit) ((mask)|(1llu<<bit))
#define CLEARBIT(mask, bit) ((mask)&(~(1llu<<bit)))
#define INVERSEBIT(mask, bit) ((mask)^(1llu<<bit))
#define CHECKBIT(mask, bit) (((mask)&(1llu<<bit))>>bit)
#define SWAP(a, b) (a)^=(b);(b)^=(a);(a)^=(b)

int main(void){
    int a = 1, b = 2, c = 3, n = 0;
    int num = MAX(a, b, c);
    printf("Max %d\n", num);

    num = MIN(a, b, c);
    printf("Min %d\n", num);

    n = SETBIT(n, 4);
    n = SETBIT(n, 2);
    printf("Number %d\n", n);

    n = CLEARBIT(n, 2);
    printf("Number %d\n", n);

    n = INVERSEBIT(n, 2);
    printf("Number %d\n", n);

    n = CHECKBIT(n, 2);
    printf("Bit %d\n", n);

    n = CHECKBIT(n, 1);
    printf("Bit %d\n", n);

    printf("Swap\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    SWAP(a, b);
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    
    return 0;
}