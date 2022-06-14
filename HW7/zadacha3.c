#include <stdio.h>

int sum(int* arr, int n){
	int sum = 0;
	for(int i = 0; i < n; i++) sum += *(arr + i);
	return sum;
}

void arrayEvaluate(int* arr, size_t n, int(*f)(int*, int)){
	int sum;
	for(int i = 0; i < n - 1; i++){
		sum = (*f)(arr, n);
	}
	printf("%d\n", sum);
}

int main(){
	int arr[] = {1, 2, 3};
	arrayEvaluate(arr, sizeof(arr) / sizeof(int), sum);
	return 0;
}