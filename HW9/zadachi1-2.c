#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <float.h>

#define COUNT 5

typedef struct {
    char title[150];
    char author[100];
    int pages;
    double price;
} book;

int randInt(int min, int max){
    return min + rand() % (max - min + 1);
}

double randDouble(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

void printBooks(book* arr, size_t n){
    for(int i = 0; i < n; i++){
        printf("Title: %s, ", arr[i].title);
        printf("Author: %s, ", arr[i].author);
        printf("Pages: %d, ", arr[i].pages);
        printf("Price: %.2lf lv.\n", arr[i].price);
    }
}

int compTitleAsc(const void* a, const void* b){
    return strcmp(((book*)a) -> title, ((book*)b) -> title);
}

int compTitleDesc(const void* a, const void* b){
    return strcmp(((book*)b) -> title, ((book*)a) -> title);
}

int compAuthorAsc(const void* a, const void* b){
    return strcmp(((book*)a) -> author, ((book*)b) -> author);
}

int compAuthorDesc(const void* a, const void* b){
    return strcmp(((book*)b) -> author, ((book*)a) -> author);
}

int compPagesAsc(const void* a, const void* b){
    return ((book*)a) -> pages - ((book*)b) -> pages;
}

int compPagesDesc(const void* a, const void* b){
    return ((book*)b) -> pages - ((book*)a) -> pages;
}

int compPriceAsc(const void* a, const void* b){
    if(fabs((((book*)a) -> price - ((book*)b) -> price)) < DBL_MIN){
        return 0;
    } else if(((book*)a) -> price > ((book*)b) -> price){
        return 1;
    }
    return -1;
}

int compPriceDesc(const void* a, const void* b){
    if(fabs((((book*)b) -> price - ((book*)a) -> price)) < DBL_MIN){
        return 0;
    } else if(((book*)b) -> price > ((book*)a) -> price){
        return 1;
    }
    return -1;
}

int compDouble(const void* a, const void* b){
    return *(double*) b - *(double*) a;
}

void *linearSearch(const void* key, void* arr, size_t n, size_t size, int (*comp)(const void*, const void*)){
    for(int i = 0; i < n * size; i += size){
        if(comp((arr + i), key) == 0){
            return arr + i;
        }
    }
    return NULL;
}

int main(){
    srand(time(NULL));
    book books[COUNT];
    double key = 20.50;

    for(int i = 0; i < COUNT; i++){
        books[i].price = randDouble(1.00, 1000.00);
        books[i].pages = randInt(5, 2000);
        int countLowercase = randInt(10, 20);
        books[i].title[0] = randInt('A', 'Z');
        books[i].author[0] = randInt('A', 'Z');
        for(int j = 1; j < countLowercase; j++){
            books[i].title[j] = randInt('a', 'z');
            books[i].author[j] = randInt('a', 'z');
        }
        books[i].title[countLowercase] = 0;
        books[i].author[countLowercase] = 0;
    }

    // -> Разкоментирай реда, по който искаш да сортираш масива от книги
    //qsort(books, COUNT, sizeof(book), compTitleAsc);
    //qsort(books, COUNT, sizeof(book), compTitleDesc);
    //qsort(books, COUNT, sizeof(book), compAuthorAsc);
    //qsort(books, COUNT, sizeof(book), compAuthorDesc);
    //qsort(books, COUNT, sizeof(book), compPagesAsc);
    //qsort(books, COUNT, sizeof(book), compPagesDesc);
    //qsort(books, COUNT, sizeof(book), compPriceAsc);
    //qsort(books, COUNT, sizeof(book), compPriceDesc);

    int *element = linearSearch(&key, books, sizeof(book), sizeof(int), compDouble);
    if(element == NULL){
        printf("There is no book with such price!\n");
    } else
        printf("%d\n", *element);
    printf("\n");
    printBooks(books, COUNT);
    return 0;
}