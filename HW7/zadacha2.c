#include <stdio.h>

unsigned sumArrayDigits(const int* arr, size_t n){
    int sum = 0;
 
    for(int i = 0; i < n; i++){
        int x = arr[i];
        while(x){
            sum += x % 10;
            x /= 10;
        }
    }
    return sum;
}

int main(){
    int arr[] = {12, 34, 5, 70};
    printf("%d\n", sumArrayDigits(arr, sizeof(arr) / sizeof(int)));
    return 0;
}