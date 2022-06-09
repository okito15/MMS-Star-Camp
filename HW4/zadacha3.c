//TODO
//number validation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int value(char c){
	if(c >= '0' && c<= '9'){
		int result = c - '0';
		return result;
	} else{
		int result = c - 'A' + 10;
		return result;
	}
}

long long int baseNToDecimal(char *str, int base){
	int len = strlen(str);
	int power = 1;
	long long int num = 0;
	for(int i = len - 1; i >= 0; i--){
		if(value(str[i]) >= base){
			fprintf(stderr, "Invalid number\n");
			return -1;
		}

		num += value(str[i]) * power;
		power *= base;
	}
	return num;
}

void decimalToBaseN(long int number, int base){
	char convertedNumber[16];
	int counter = 0;
	while(number!=0){
		int var = 0;
		var = number % base;
		if(var < 10){
			convertedNumber[counter] = var + 48;
			counter++;
		} else{
			convertedNumber[counter] = var + 55;
			counter++;
		}
		number /= base;
	}
	for(int i = counter - 1; i >= 0; i--){
		printf("%c", convertedNumber[i]);
	}
	printf("\n");
}


int main(){
	int length, inputBase, outputBase;
	char number[16];
	printf("Enter the number: ");
	scanf("%s", number);
	printf("Enter the starting base and the required base: ");
	scanf("%d %d", &inputBase, &outputBase);
	decimalToBaseN(baseNToDecimal(number, inputBase), outputBase);
	return 0;
}
