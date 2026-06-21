#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool checkSequence(char *str){
    int state = 0;
    FILE *ptr;

    ptr = fopen("Entrada.txt", "r");

    if(ptr == NULL){
        return false;
    }

    char c, prev = '\0';

    c = fgetc(ptr);

    while(!feof(ptr)){
        if(c == str[state] && (prev == '\0' || prev == ' ' || prev == '\n' || state > 0)){
            state++;
        } else {
            state = 0;
        }

        if(state == strlen(str) - 1){
            prev = c;
            c = fgetc(ptr);
            if(c == ' ' || c == '\n' || c == '.' || c == ',' || c == '!' || c == '?' || c == ';' || c == ':' || feof(ptr)){
                return true;
            } else {
                state = 0;
            }
        } else {
            prev = c;
            c = fgetc(ptr);
        }

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
