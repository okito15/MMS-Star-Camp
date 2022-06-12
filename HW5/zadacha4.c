#include <stdio.h>
#include <math.h>

int quadEq(double, double, double, double*, double*);


int main(){
    double a, b, c, x1, x2;
    scanf("%lf %lf %lf", &a, &b, &c);
    quadEq(a, b, c, &x1, &x2);
    return 0;
}

int quadEq(double a, double b, double c, double* x1, double* x2){
    double discriminant = b * b - 4 * a * c;

    if(discriminant > 0){
        *x1 = (-b - sqrt(discriminant)) / (2 * a);
        *x2 = (-b + sqrt(discriminant)) / (2 * a);
        printf("x1 = %.2lf\nx2 = %.2lf\n", *x1, *x2);
    }
    else if(discriminant == 0){
        *x1 = -b / (2 * a);
        *x2 = -b / (2 * a);
        printf("x1 = %.2lf\nx2 = %.2lf\n", *x1, *x2);
    }
    else {
        printf("No real roots\n");
    }
}