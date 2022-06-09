#include <stdio.h>
#include <math.h>

int main() {
    double r, h, S, V;

    while (scanf("%lf %lf", &r, &h) != EOF) {
        if(r > 0 && h > 0) {
            S = 2 * M_PI * r * h + 2 * M_PI * r * r;
            V = M_PI * r * r * h;
            printf("S = %.2lf V = %.2lf\n", S, V);
        }
        else {
            printf("Invalid data\n");
        }
    }
    return 0;
}

int cylinder(double r, double h, double *V, double *S) {
    if(r > 0 && h > 0 && V > 0 && S > 0) return 0;
    else return -1;
}