#include "015_BigNum_Library.h"
#include <stdlib.h>

char BigNum_Pretreatment(BigNum *First, BigNum *Second){
    if((*First).Content[0] == '-' && (*Second).Content[0] == '-'){
        (*First).Content[0] = ' ';
        (*Second).Content[0] = ' ';
        ArrayFix((*First).Content, &(*First).Length);
        ArrayFix((*Second).Content, &(*Second).Length);
        return '-';
    }
    return 0;
}

void ArrayFix(char *Num, int *Length){
    for(int Run = 1; Run < *Length; Run++){
        Num[Run - 1] = Num[Run];
    }
    *Length -= 1;
}