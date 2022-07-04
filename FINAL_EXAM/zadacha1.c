#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <inttypes.h>

#define ITEMS_COUNT 3

typedef struct item{
	uint16_t number;
	char description[250];
	double weight;
	double price;
	struct item* next;
} item;

uint16_t randomInt(uint16_t min, uint16_t max){
	return min + rand() % (max - min + 1);
}

double randomDouble(double min, double max){
	return min + ((double)rand() / RAND_MAX) * (max - min);
}

void push(item** head){
	srand(time(NULL));
	item* items = malloc(sizeof(item));
	if(!items){
		fprintf(stderr, "Error with memory allocation!");
		exit(-1);
	}
	
	items -> next = (*head);
	items -> number = randomInt(0, 65535);

	for(int i = 0; i < ITEMS_COUNT; i++){
	int descriptionLength = randomInt(5, 10);
	char randomLowerCase = 'a' + rand() % ('z' - 'a' + 1);
	char randomUpperCase = 'A' + rand() % ('Z' - 'A' + 1);
	
		for(int j = 0; j < descriptionLength; j++){
		
			if(i == 1 && j == 1){
			randomLowerCase = 'a' + rand() % ('z' - 'a' + 1);
			randomUpperCase = 'A' + rand() % ('Z' - 'A' + 1);
			int randomBit = rand() % 2;
			
				if(randomBit){
				items -> description[j] = randomLowerCase;
				}
				else{
				items -> description[j] = randomUpperCase;
				}
			else{
			randomLowerCase = 'a' + rand() % ('z' - 'a' + 1);
			}
			
			items -> description[descriptionLength] = '\0';
			}
			
	items -> weight = randomDouble(0.100 , 100.00);
	items -> price = randomDouble(1.00, 1500.00);
	(*head) = items;
		}
	}	
}

double totalItemsWeight(item* head){
    double* sum = malloc(sizeof(double));
    sum = 0;
    item* current = head;
    while (current){
        *sum += current -> weight;
        current = current -> next;
    }
    if(sum == 0){
        return -1;
    }
    return *sum;
}

item *minPriceItem(item* head){
    item* current = head;
    int count = 0;
    double* min = malloc(sizeof(double));
    *min = 0;
    while (current){
        if(*min > current -> price){
        *min = current -> price;
        count++;
        }
        current = current -> next;
    }
	if(count > 0){
		return &min;
	}
	else{
		return 0;
	}
}

void freeList(item** head){
    item* current = *head;
    while (current != NULL){
        item* temp = current;
        current = current -> next;
        free(temp);
    }
    *head = NULL;
}

void printItems(item* head){
    item* current = head;
    while (current != NULL){
        printf("Number: %hu ", current -> number); 
        printf("Description: %s ", current -> description);
        printf("Weight: %.2lf ", current -> weight)
        printf("Price: %.2lf\n", current -> price);
        current = current -> next;
    }
    putchar('\n');
}

int main(int argc, char const *argv[]){
    item* head = NULL;

    for(int i = 0; i < ITEMS_COUNT; i++){
        push(&head);
    }
    printItems(&head);

    printf("Sum of weight is: %.2lf", totalItemsWeight(head));
    printf("Min price is: %.2lf", minPriceItem(head));

    freeList(&head);
    return 0;
}