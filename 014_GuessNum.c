#include<stdio.h>
#include<math.h>

char GuessNum(int int_Num, int int_Answer){
    int A = 0, B = 0;
    for(int Run = 10; Run <= 10000; Run *= 10){
        if((int_Num % Run) / (Run / 10) == (int_Answer % Run) / (Run / 10)){
            A++;
        }
        for(int Inside = 10; Inside <= 10000; Inside *= 10){
            if((int_Num % Inside) / (Inside / 10) == (int_Answer % Run) / (Run / 10) && Inside != Run){
                B++;
            }
        }
    }
    if(A != 4){
        printf("%dA%dB\n", A, B);
        return 'n';
    }
    else{
        printf("win\n");
        return 'y';
    }
}

int main(void){
    /*Input the answer*/
    int int_Answer;
    scanf("%d", &int_Answer);

    char Flag = 'n';
    int Count = 0;
    while(Flag != 'y' && Count < 6){
        int int_InputNum;
        scanf("%d", &int_InputNum);
        Flag = GuessNum(int_InputNum, int_Answer);
        Count++;
    }
    return 0;
}