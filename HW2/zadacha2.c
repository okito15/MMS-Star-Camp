#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    file = fopen("numbers.txt", "r");
    char ch;
    int count = 0, number1, number2, number3, result;

    if(file == NULL)
    {
        printf("Can't open file!\n");
        exit(1);
    }

    do {
        ch = fgetc(file);
        count++;
    } while(ch != EOF);
    count = count / 2;

    fscanf(file, "%d", &number1);
    fscanf(file, "%d", &number2);
    if (count == 3) fscanf(file, "%d", &number3);
    
    if(count == 2) result = number1 ^ number2;
    else result = (number1 ^ number2) ^ number3;

    printf("Result is %d\n", result);
    return 0;
}
