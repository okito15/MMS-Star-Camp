#include <stdio.h>
#include <math.h>

int main() {
    double R, L, H, volume1, volume2, cosinus;

    //a

    printf("Radius R = ");
    scanf("%lf", &R);

    printf("Height of water H = ");
    scanf("%lf", &H);

    volume1 = R * R * M_PI * H;
    printf("a) Volume = %.2lf m3\n", volume1);

    //b

    printf("Radius R = ");
    scanf("%lf", &R);

    printf("Length L (height of the cylinder) = ");
    scanf("%lf", &L);

    printf("Height of water H = ");
    scanf("%lf", &H);

    cosinus = cos((R - H) / R);
    cosinus = 1 / cosinus;
    volume2 = cosinus * (R * R) - ((R - H) * sqrt((2 * R * H) - (H * H)));
    volume2 = volume2 * L * M_PI / 2 ;
    printf("b) Volume = %.2lf m3\n", volume2);
}