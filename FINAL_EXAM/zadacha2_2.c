#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
 
#define COUNT 10
pthread_mutex_t mux;
int cmpfunc (const void * a, const void * b);
 
void* sort(void* arg)
{   
    int* retval = malloc(sizeof(int));
    pthread_mutex_lock(&mux);
    FILE* srcfile = fopen((char*)arg, "rb");
        if (NULL == srcfile){
            perror("Error");
            *retval = -1;
            return retval;
        }
    int num = 0;
    int sum = 0;
    
    while (fread(&num, sizeof(int), 1, srcfile)){
         sum += num;  
    }
    fclose(srcfile);
    pthread_mutex_unlock(&mux);
    return (void *)sum;
}
 
int main(int argc, char const *argv[]){
    pthread_mutex_init(&mux, NULL);
    if(argc == 1){
        perror("Missing arguments!");
        return EXIT_FAILURE;
    }   
    pthread_t th[argc - 1];
 
    for (int i = 1; i < argc; i++){
        pthread_create(th + i, NULL, &sort, &argv[i]);
    }
    
    int total = 0;
    
    for (int i = 1; i < argc; i++){
        void* retval;
        pthread_join(th[i], (void**)&retval);
        total += (int)&retval;
 
        printf("The sum is: %d", total);
 
        if(pthread_join(th[i], &retval)){
            perror("join error");
            return EXIT_FAILURE;
        }
    }  
    return EXIT_SUCCESS;
}