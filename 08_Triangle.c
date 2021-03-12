#include<stdio.h>
#include<math.h>
void LeftTriangle(int);
void RightTriangle(int);
void Rectangle(int);

int main(){
    int Mode;
    int Lines;
    scanf("%d", &Mode);
    scanf("%d", &Lines);

    if(Mode == 1){
        LeftTriangle(Lines);
    }
    else if(Mode == 2){
        RightTriangle(Lines);
    }
    else{
        Rectangle(Lines);
    }
    return 0;
}

void LeftTriangle(int Line){
    int Start = Line / 2;
    for(int Run = -Start; Run <= Start; Run++){
        int Num = abs(Run);
        for(int Inside = 0; Inside < ((Start + 1) - Num); Inside++){
            printf("*");
        }
        printf("\n");
    }
}

void RightTriangle(int Line){
    int Start = Line / 2;
    for(int Run = -Start; Run <= Start; Run++){
        int Num = abs(Run);
        for(int Inside = 0; Inside < Num; Inside++){
            printf(".");
        }
        for(int Inside = 0; Inside < ((Start + 1) - Num); Inside++){
            printf("*");
        }
        printf("\n");
    }
}

void Rectangle(int Line){
    int Start = Line / 2;
    for(int Run = -Start; Run <= Start; Run++){
        int Num = abs(Run);
        for(int Inside = 0; Inside < Num; Inside++){
            printf(".");
        }
        for(int Inside = 0; Inside < Line - (Num * 2); Inside++){
            printf("*");
        }
        printf("\n");
    }
}