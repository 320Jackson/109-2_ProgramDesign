#include<stdio.h>
#include<stdlib.h>
#include "String_Input.h"
#include "015_BigNum_Library.h"

int main(void){
    /*Input mode*/
    int int_Mode;
    scanf("%d ", &int_Mode);
    
    /*Input two big number*/
    BigNum FirstNum, SecondNum;
    FirstNum.Content = InputStr(&FirstNum.Length);
    SecondNum.Content = InputStr(&SecondNum.Length);
    
    /*Pretreatment*/
    char b_Flag = BigNum_Pretreatment(&FirstNum, &SecondNum);
    printf("%s, %s, %c\n", FirstNum.Content, SecondNum.Content, b_Flag);
    char *Ans;
    switch(int_Mode){
        case 1:
            *Ans = BigNum_Addition(FirstNum, SecondNum);
            break;
        case 2:
            *Ans = BigNum_Subtraction(FirstNum, SecondNum);
            break;
    }
    printf("%c%s", b_Flag, Ans);

    /*Release memory*/
    free(FirstNum.Content);
    free(SecondNum.Content);
    free(Ans);
    return 0;
}