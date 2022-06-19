#include<stdio.h>

int binarySearch(int* array, size_t n, int key){
    int i, j, temp;

    for (i = 0; i < n; ++i){
        for (j = i + 1; j < n; ++j){
                if (array[i] > array[j]){
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }

    for(i = 0; i < n; i++){
        if(array[i] == key){
            return i;
        }
    }
    return -1;
}

int main(){
    int array[] = {50, 40, 30, 200, 60, 15};
    int key = 15;

    if(binarySearch(array, sizeof(array) / sizeof(int), key) == -1){
        printf("The key is not found\n");
    } else{
        printf("Index of the key is %d\n", binarySearch(array, sizeof(array) / sizeof(int), key));
    }
    return 0;
}