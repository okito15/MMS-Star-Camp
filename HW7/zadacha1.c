#include <stdio.h>
#include <stdlib.h>

int compare(const void*, const void*);

int main(){
    double arr[] = {1.3, 5.5, 1.7};
    int size = sizeof(arr) / sizeof(double);

    if(arr == NULL){
        printf("The array is empty!");
        return 0;
    }
    else if(size == 0 || size == 1){
        printf("The array is either with 0 or 1 element so there can't be a second max element.");
        return 0;
    }

    qsort(arr, size, sizeof(double), compare);

    if(arr[0] == arr[size - 1]){
        printf("There is no second max element, they are all the same.");
    }
    else {
        printf("The second largest number is: %.2lf\n", arr[1]);
    }
    return 0;
}

int compare(const void* ptr1, const void* ptr2){
    double a = *(const double *) ptr1;
    double b = *(const double *) ptr2;

    if(a == b){
        return 0;
    }
    else if(a > b){
        return -1;
    }
    return 1;
}