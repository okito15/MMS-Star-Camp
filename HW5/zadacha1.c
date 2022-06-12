#include <stdio.h>

int main()
{
    double num1, num2;
    char symbol;
    while(scanf("%lf %c %lf", &num1, &symbol, &num2) != EOF){
        if (symbol == '+'){
            printf("%.2lf\n", num1 + num2);
        } else if (symbol == '-') {
            printf("%.2lf\n", num1 - num2);
        } else if (symbol == '/') {
            printf("%.2lf\n", num1 / num2);
        } else if (symbol == 'x') {
            printf("%.2lf\n", num1 * num2);
        } else printf("Not supported operation!\n");
    }
}