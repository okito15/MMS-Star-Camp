#include <stdio.h>

const double pi = 3.14159265359;

double sin(double x){
    double sign = 1;
    if (x < 0){
        sign = -1.0;
        x = -x;
    }

    if (x > 360){
        x -= (int) x / 360 * 360;
    }

    x *= pi / 180.0;
    double res = 0;
    double term = x;
    int k = 1;
    while (res + term != res){
        res += term;
        k += 2;
        term *= -x * x / k / (k - 1);
    }
    return sign * res;
}

int main(){
    int x = -270;
    printf("The sine of x %d is: %.2lf\n", x, sin(x));
}