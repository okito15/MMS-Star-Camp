#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
 
#define COUNT 10
 
int main(int argc, char const *argv[]){   
int fd[2];
if(pipe(fd) == -1){
    perror("Pipe Error");
    return EXIT_FAILURE;
}
if(argc == 1){
        perror("Missing arguments!");
        return EXIT_FAILURE;
}
 
for (int i = 1; i < argc; i++){
        pid_t pid = fork();
        if (-1 == pid){
        perror("fork error");
        return EXIT_FAILURE;
        } else if (0 == pid){
            close(fd[0]);
            FILE* srcfile = fopen(argv[i], "rb");
            if (NULL == srcfile){
            perror("error");
            return EXIT_FAILURE;
            }
        int num = 0;
        int sum = 0;
    
    while (fread(&num, sizeof(int), 1, srcfile)){
        sum += num;              
    }
    fclose(srcfile);
 
    write(fd[1], &sum, sizeof(sum));
    close(fd[1]);
            
    exit(EXIT_SUCCESS);
    
    } else {
        close(fd[1]);
        for (int i = 1; i < argc; i++){
        wait(NULL);
    }
        int sumChild;
        read(fd[0], &sumChild, sizeof(sumChild));
        close(fd[0]);
        printf("Sum of child = %d\n", sumChild);
    }
    return EXIT_SUCCESS;
  }
}