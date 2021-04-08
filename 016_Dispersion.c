#include <stdio.h>
#include <stdlib.h>
#include "String_Input.h"
typedef struct String String;

struct String{
    char *Content;
    int Length;
};

char CheckRepeat(char *str, int Start, int End){
    for(int Outside = Start; Outside < End; Outside++){
        for(int Inside = Start; Inside < End; Inside++){
            if(Outside == Inside){
                continue;
            }
            if(str[Outside] == str[Inside]){
                return '0';
            }
        }
    }
    return '1';
}

void SlidingWindow(String str, int m){
    int Count = 0;
    for(int Run = 0; Run <= (str.Length - 1) - m; Run++){
        char Flag = CheckRepeat(str.Content, Run, Run + m);
        if(Flag == '1'){
            Count++;
        }
    }
    printf("%d", Count);
}

int main(){
    /*Input arr*/
    String str_Input;
    str_Input.Content = InputStr(&str_Input.Length);
    
    /*Input sub arr quantity*/
    int m;
    scanf("%d", &m);
    SlidingWindow(str_Input, m);

    /*Release RAM space*/
    free(str_Input.Content);
    return 0;
}