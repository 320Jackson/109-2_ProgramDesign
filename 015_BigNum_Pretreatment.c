#include "015_BigNum_Library.h"
#include <stdlib.h>

char BigNum_Pretreatment(BigNum *First, BigNum *Second, int *Mode){
    char b_Flag;
    if((*First).Content[0] == '-' && (*Second).Content[0] == '-'){
        (*First).Content[0] = ' ';
        (*Second).Content[0] = ' ';
        ArrayFix((*First).Content, &(*First).Length);
        ArrayFix((*Second).Content, &(*Second).Length);
        b_Flag = '-';
    }
    else if((*First).Content[0] != '-' && (*Second).Content[0] != '-'){
        b_Flag = 0;
    }
    else{
        if((*First).Content[0] == '-'){
            BigNum *Change = First;
            First = Second;
            Second = Change;
        }
        switch(*Mode){
            case 1:
                *Mode = 2;
                break;
            case 2:
                *Mode = 1;
                break;
        }
        (*Second).Content[0] = ' ';
        ArrayFix((*Second).Content, &(*Second).Length);
        b_Flag = BigNum_Comparison(First, Second);
    }
    if(*Mode == 2){
        Complement((*Second).Content, &(*Second).Length);
    }
    return b_Flag;
}

char BigNum_Comparison(BigNum *First, BigNum *Second){
    if((*First).Length < (*Second).Length){
        BigNum *Change = First;
        First = Second;
        Second = Change;
        return '-';
    }
    else if((*First).Length > (*Second).Length){
        return 0;
    }
    else{
        for(int Run = 0; Run < (*First).Length; Run++){
            if((*First).Content[Run] < (*Second).Content[Run]){
                BigNum *Change = First;
                First = Second;
                Second = Change;
                return '-';
            }
            else if((*First).Content[Run] > (*Second).Content[Run]){
                return 0;
            }
        }
    }
}

void Complement(char *Num, int *Length){
    int Run = *Length - 2;
    Num[Run] = (10 - (Num[Run] - 48)) + 48;
    Run--;
    while(Run >= 0){
        Num[Run] = (9 - (Num[Run] - 48)) + 48;
        Run--;
    }
    //ZeroFix(Num, Length);
}

void ArrayFix(char *Num, int *Length){
    for(int Run = 1; Run < *Length; Run++){
        Num[Run - 1] = Num[Run];
    }
    *Length -= 1;
}

void ZeroFix(char *Num, int *Length){
    while(Num[0] == '0'){
        for(int Run = 1; Run <= *Length; Run++){
            Num[Run - 1] = Num[Run];
        }
        *Length -= 1;
        if(Num[1] == '\0'){
            break;
        }
    }
}