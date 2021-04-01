#include<stdlib.h>
#include<stdio.h>
#include "String_Input.h"

char *InputStr(int *int_Length){
    int Count = 0;
    int int_Size = 32;
    char *Output = malloc(sizeof(char) * int_Size);

    for(Count = 0;; Count++){
        int Buffer = getchar();
        if(Buffer == EOF || Buffer == '\n'){
            Output[Count] = '\0';
            *int_Length = (Count + 1);
            Output = realloc(Output, sizeof(char) * (*int_Length));
            break;
        }
        else{
            Output[Count] = Buffer;
        }
        /*Input oversize*/
        if(int_Size - 1 <= Count){
            int_Size += 32;
            Output = realloc(Output, sizeof(char) * int_Size);
        }
    }
    return Output;
}