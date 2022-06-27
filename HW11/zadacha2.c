#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double randReal(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

void print(double *arr, int count){
    for(int i = 0; i < count; i++)
    {
        printf("%lf ", arr[i]);
    }
    putchar('\n');
}

int main(void){
    srand(time(NULL));
    int n;
    scanf("%d", &n);
    double *arr = malloc(n * sizeof(double));
    size_t i;

    if(NULL == arr){
        fprintf(stderr, "Malloc error!");
        return -1;
    }

    for (i = 0; i < n; i++){
        arr[i] = randReal(0.0, 1.0);
    }

    int m;
    scanf("%d", &m);
    int count = m + n;
    arr = realloc(arr, count * sizeof(double));
    if(NULL == arr){
        fprintf(stderr, "Realloc error!");
        return -1;
    }
    for (; i < count; i++){
        arr[i] = randReal(1.0, 2.0);
    }

    int p;
    scanf("%d", &p);
    int count2 = m + n + p;
    arr = realloc(arr, count2 * sizeof(double));
    if(NULL == arr){
        fprintf(stderr, "Realloc error!");
        return -1;
    }
    for (; i < count2; i++){
        arr[i] = randReal(2.0, 3.0);
    }
    
    print(arr, count2);
    free(arr);

    return 0;
}