#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

int ReadBinaryWriteText(char* src, char* dest){
    int16_t temp;
    FILE* binptr;
    FILE* textptr;

    binptr = fopen(src, "rb");
    textptr = fopen(dest, "w");
    
    if(binptr == NULL || textptr == NULL){
        fprintf(stderr, "Error!");
        return 1;
    }
    while(!feof(binptr)){
        fread(&temp, sizeof(int16_t), 1, binptr);
        fprintf(textptr,"%hd\n",temp);
    }

    fclose(binptr);
    fclose(textptr);
}

int ReadTextWriteBinary(char* src, char* dest){
    int16_t temp;
    FILE* binptr;
    FILE* textptr;

    binptr = fopen(dest, "wb");
    textptr = fopen(src, "r");
    
    if(binptr == NULL || textptr == NULL){
        fprintf(stderr, "Error!");
        return 1;
    }
    while(!feof(textptr)){
        fscanf(textptr,"%hd",&temp);
        fwrite(&temp, sizeof(int16_t), 1, binptr); 
    }

    fclose(binptr);
    fclose(textptr);
}

int main(int argc, char** argv)
{
    char src[30], dest[30], mode[4];

    strcpy(src, argv[1]);
    strcpy(dest, argv[2]);

    if(strcmp(mode, "-BT") == 0){
        ReadBinaryWriteText(src, dest);
    }
    else if(strcmp(mode, "-TB") == 0){
        ReadBinaryWriteText(src, dest);
    }
    else{
        fprintf(stderr, "Invalid!\n");
        return 1;
    }
    return 0;
}