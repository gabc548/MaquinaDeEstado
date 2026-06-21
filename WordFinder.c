#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool checkSequence(char *str){
    int state = 0;
    FILE *ptr;

    ptr = fopen("Entrada.txt", "r");

    char c;

    c = fgetc(ptr);

    while(!feof(ptr)){
        if(c == str[state]){
            state++;
        } else {
            state = c == str[state] ? 1 : 0;
        }

        if(state == strlen(str) - 1){
            return true;
        }

        c = fgetc(ptr);
    }

    fclose(ptr);
    return false;
}

int main(){
    char str[50];
    fgets(str, 50, stdin);

    bool searchSequence = checkSequence(str);

    printf("%d\n", searchSequence);

    return 0;
}