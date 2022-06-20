#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <float.h>

#define COUNT 5

typedef struct point{
    double x;
    double y;
} point_t;

typedef struct rectangle{
    point_t A;
    point_t B;
} rectangle_t;

typedef struct node{
    rectangle_t rec;
    struct node* next;
} node_t;

double randDouble(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

void push(node_t** list, rectangle_t rec){
    node_t* n = malloc(sizeof(node_t));
    n -> rec = rec;
    n -> next = *list;
    *list = n;
}

double areaRects(node_t* list){
    if(list == NULL){
        return -1;
    }

    node_t* areaRects = list;
    double fabsX, fabsY, area;
    double sumArea = 0;

    for(int i = 0; i < COUNT; i++){
        fabsX = fabs(areaRects -> rec.A.x - areaRects -> rec.B.x);
        fabsY = fabs(areaRects -> rec.A.y - areaRects -> rec.B.y);
        area = fabsX * fabsY;
        sumArea += area;
        areaRects = areaRects -> next;
    }
    return sumArea;
}

void print_list(node_t* list){
    node_t* current = list;
    while (current){
        printf("A.x = %.2lf A.y = %.2lf B.x = %.2lf B.y = %.2lf \n", current -> rec.A.x, current -> rec.A.y, current -> rec.B.x, current -> rec.B.y);
        current = current -> next;
    }
    printf("\n");
}

void deleteNth(node_t** list, size_t n){
    if (*list == NULL){
        return;
    }
    if (n == 0){
        node_t* temp = *list;
        *list = (*list) -> next;
        free(temp);
        return;
    }
    node_t* current = *list;
    node_t* prev = current;
    while (current && n--) {
        prev = current;
        current = current -> next;
    }
    prev -> next = current -> next;
    free(current);
}

void filterRects(node_t** list, double min, double max){
    int n = 0;
    node_t* filteredList = *list;
    while (filteredList != NULL){
        double area = areaRects(filteredList);
        if(area > min && area < max){
            deleteNth(list, n);
        }
        n++;
        filteredList = filteredList -> next;
    }
}

int main(){
    srand(time(NULL));
    node_t* list = NULL;

    for(int i = 0; i < COUNT; i++){
        rectangle_t* r1 = malloc(sizeof(rectangle_t));
        r1->A.x = randDouble(-10.0, 10.0);
        r1->B.x = randDouble(-10.0, 10.0);
        r1->A.y = randDouble(-10.0, 10.0);
        r1->B.y = randDouble(-10.0, 10.0);
        push(&list, *r1);
    }
    printf("Here are the example rectangles created:\n");
    print_list(list);
    printf("The sum of all rectangle areas is: %.2lf\n", areaRects(list));
    filterRects(&list, 25.50, 75.50);
    printf("The list of rectangles after the filter:\n");
    print_list(list);

    return 0;
}