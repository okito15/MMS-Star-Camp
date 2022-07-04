#include <stdio.h>
#include <stdlib.h>

int Compare( const void* a, const void* b){
     return *((int*) a) - *((int*) b);
}

int main(){
    unsigned int N, M;
    printf("N and M: ");
    fscanf(stdin, "%u %u", &N, &M);
    char storeRow[3];
    int matrix[N][M + 1];
    int rowCnt = 0, indexCnt = 0;

    while (scanf("%d", &matrix[rowCnt][indexCnt])){
        if (indexCnt == M + 1){
            rowCnt++;
            if (rowCnt > N){
                printf("Index error");
                break;
            }
            indexCnt = 0;
            continue;
        }
        indexCnt++;
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M + 1; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}