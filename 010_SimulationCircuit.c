#include<stdio.h>
#include<math.h>
#include<stdlib.h>

char *getGiveBackCode(char *);
int Circuit(int);

int main(){
    char m[8]; /*輸入資料*/
    int Mode; /*Mode*/

    while(1){
        scanf(" %s", &m);

        char *GiveBack = getGiveBackCode(m);
        printf("%s\n", GiveBack);
        free(GiveBack);

        scanf("%d", &Mode);
        if(Mode == -1){
            break;
        }
    }
    return 0;
}

int Circuit(int m){
    if(m == 0 || m == 1){
        return m;
    }
    else if (m % 2 == 0){
        return Circuit(m / 2) + 1;
    }
    else{
        return Circuit((m + 1) / 2) + 1;
    }
}

char *getGiveBackCode(char *m){
    /*次數轉換*/
    int Num = 0;
    for(int Run = 0; Run < 8; Run++){
        //Num += (m[Run] - 48) * pow(2, 7 - Run);
        Num += (m[Run] - 48);
        if(Run < 8 - 1){
            Num = Num << 1;
        }
    }
    //printf("%d\n", Num);
    /*取得電路次數，編碼*/
    int Buffer = Circuit(Num);
    if(Num != 0){
        Buffer -= 1;
    }
    char *Output = malloc(sizeof(char) * 5);
    for(int Run = 4 - 1; Run >= 0; Run--){
        Output[Run] = (Buffer % 2) + 48;
        Buffer /= 2;
    }
    Output[4] = '\0';
    return Output;
}