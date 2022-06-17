#include <stdio.h>

void map(int*, size_t, int (*func)(int));
int currentNumberPlus1(int);

int main(){
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    map(arr, sizeof(arr) / sizeof(int), currentNumberPlus1);
    return 0;
}

void map(int* array, size_t n, int (*func)(int)){
    for(int i = 0; i < n; i++){
        printf("%d ", currentNumberPlus1(array[i]));
    }
}

int currentNumberPlus1(int number){
    return ++number;
}