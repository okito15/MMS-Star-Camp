#include <stdio.h>

int strlenC(char*);
int strnlenC(char*, size_t);
void strcpyC(char*, const char*);
void strncpyC(char*, const char*, int);
void strcatC(char*, const char*);
void strncatC(char*, const char*, int);
int strcmpC(const char*, const char*);
int strncmpC(const char*, const char*, int);
int strstrC(char*, char*);

int main(){
    char a[31] = "stringA";
    char b[31] = "stringB";
    char c[31] = "stringC";
    char d[31] = "stringD";
    char e[31] = "str";

    printf("Length of string = %d\n", strlenC(a));
    printf("Length of the string until the n-th symbol = %d\n", strnlenC(a, 5));
    printf("\n");

    printf("String a before strcpy() = %s\n", a);
    strcpyC(a, b);
    printf("String a after strcpy() = %s\n", a);

    strncpyC(a, b, 3);
    printf("String a after strncpy() = %s\n", a);
    printf("\n");

    strcatC(a, c);
    printf("String a after strcat() with String c = %s\n", a);

    strncatC(a, c, 6);
    printf("String a after strncat() with String c = %s\n", a);
    printf("\n");

    printf("String c and String d compared = %d\n", strcmpC(c, d));
    printf("String c and String d compared to n = %d\n", strncmpC(c, d, 5));
    printf("\n");

    if(strstrC(d, e)) printf("The substring exists within in the main string.\n");
    return 0;
}

int strlenC(char* c){
    int count = 0;
    int i = 0;
    while (c[i] !='\0')
    {
        i++;
        count++;
    }
    return count;
}

int strnlenC(char* c, size_t n){
    int count = 0;
    int i = 0;
    while (c[i] != '\0')
    {
        i++;
        count++;
        if(i == n){
            break;
        }        
    }
    return count;
}

void strcpyC(char* dest, const char* src){
    int i = 0;
    while (dest[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void strncpyC(char* dest, const char* src, int n){
    int i = 0;
    while (dest[i] != '\0')
    {
        dest[i] = src[i];
        i++;
        if(i == n){
            break;
        }
    }
    dest[i] = '\0';
}

void strcatC(char* str1, const char* str2){
    int i = 0;
    int j = 0;
    while (str1[i] != '\0'){
        i++;
    }

    while (str2[j] != '\0'){
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
}

void strncatC(char* str1, const char* str2, int n){
    int i = 0;
    int j = 0;
    while (str1[i] != '\0'){
        i++;
    }
    while (j != n){
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
}

int strcmpC(const char * str1, const char * str2){
    while (*str1){
        if (*str1 != *str2){
            break;
        }
        str1++;
        str2++;
    }
    return *(const unsigned char*) str1 - *(const unsigned char*) str2;
}

int strncmpC(const char* str1, const char* str2, int n){
    while (*str1 && sizeof(str1) < n)
    {
        if (*str1 != *str2) {
            break;
        }
        str1++;
        str2++;
    }
    return *(const unsigned char*) str1 - *(const unsigned char*) str2;
}

int strstrC(char* str1, char* str2){
    int i = 0, j = 0;
    int nTemp = i;
    int nStrLen = strlenC(str1);
    int nStrSubLen = strlenC(str2);
    for(i = 0; i < nStrLen - nStrSubLen; i++){
        nTemp = i;
        for(j = 0; j < nStrSubLen; j++){
             
            if(str1[nTemp] == str2[j])
            {
                if(j == nStrSubLen -1)
                    return 1;
                nTemp++;
            }
            else break;
        }
    }
    return 0;
}