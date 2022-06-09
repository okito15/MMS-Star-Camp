#include <stdio.h>
#include <math.h>

int main() {
    double mass, height, bmi1, bmi2;

    printf("Mass in kg = ");
    scanf("%lf", &mass);

    printf("Height in m = ");
    scanf("%lf", &height);

    bmi1 = mass / (height * height);
    printf("BMI1 = %.2lf\n", bmi1);

    bmi2 = (1.3 * mass) / (sqrt(pow(height, 5)));
    printf("BMI2 = %.2lf\n", bmi2);

    return 0;
}