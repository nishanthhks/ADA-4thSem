#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void main(){
    char a[1000];
    char b[1000];
    printf("Enter main string: ");
    gets(a);
    printf("Enter string to search: ");
    gets(b);
    for(int i = 0; i < strlen(a) - strlen(b) + 1; i++){
        for(int j = 0; j < strlen(b); j++){
            if(a[i+j] != b[j]){
                break;
            }
            if(j == strlen(b) - 1){
                printf("String matches from position %d", i + 1);
                return;
            }
        }
    }
    printf("String doesn't match");
}
