#include <stdio.h>
#include <stdlib.h>
#include "String_Input.h"

int Staggered(char *, int);

int main(){
    int k;
    scanf("%d ", &k);

    String str_Input;
    str_Input.Content = InputStr(&str_Input.Length);

    printf("%d\n", Staggered(&str_Input.Content[0], k));
    free(str_Input.Content);
    return 0;
}

int Staggered(char *String, int k){
    int lower = 0, upper = 0, length = 0, buffer = 0;
    do{
        /*大小寫字串記數*/
        if(*String >= 65 && *String <= 90){
            upper++;
            lower = 0;
        }
        else if(*String >= 97 && *String <= 122){
            lower++;
            upper = 0;
        }        

        if(upper > k){
            upper = k;
        }
        if(lower > k){
            lower = k;
        }

        /*下個為交錯*/
        if(upper == k && (*(String + 1) >= 97 && *(String + 1) <= 122)){
            buffer += upper;
            upper = 0;
        }        
        else if(lower == k && (*(String + 1) >= 65 && *(String + 1) <= 90)){
            buffer += lower;
            lower = 0;
        }
        /*下個不交錯*/
        else if(lower == k && (*(String + 1) >= 97 && *(String + 1) <= 122) || *(String + 1) == '\0'){
            buffer += lower;
            if(buffer > length){
                length = buffer;
            }
            buffer = 0;
        }
        else if(upper == k && (*(String + 1) >= 65 && *(String + 1) <= 90) || *(String + 1) == '\0'){
            buffer += upper;
            if(buffer > length){
                length = buffer;
            }
            buffer = 0;
        }
        
        String++;
    }
    while(*String != '\0');
    
    return length;
}