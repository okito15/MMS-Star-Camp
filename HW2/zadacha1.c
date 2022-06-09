#include <stdio.h>

int main()
{
    FILE *file;
    file = fopen("numbers.txt", "r");
    double numberArray[3];

    for (int i = 0; i < 3; i++)
    {
        fscanf(file, "%lf", &numberArray[i]);
    }

    if (numberArray[0] > numberArray[1])
    {
        if (numberArray[0] > numberArray[2]) {
            printf("%lf", numberArray[0]);
        }
        else { printf("%lf", numberArray[2]);
        }
    }
            else if (numberArray[1] > numberArray[2]) {
                    printf("%lf", numberArray[1]);
            }
                    else printf("%lf", numberArray[2]);
    return 0;
}