#include <stdio.h>

double squareRoot(int num){
    double temp, sqrt;

    sqrt = num / 2;
    temp = 0.0000001;

    while(sqrt != temp){
        temp = sqrt;
        sqrt = (num / temp + temp) / 2;
    }
    return sqrt;
}

int main(){
    int num = 64;
    printf("The square root of %d is %.2lf\n", num, squareRoot(num));
}