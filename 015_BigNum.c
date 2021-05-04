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
    char b_Flag;
    BigNum Ans;
    switch(int_Mode){
        case 1:
            b_Flag = BigNum_Pretreatment(&FirstNum, &SecondNum, &int_Mode);
            Ans = BigNum_Subtraction(FirstNum, SecondNum, int_Mode);
            break;
        case 2:
            b_Flag = BigNum_Pretreatment(&FirstNum, &SecondNum, &int_Mode);
            Ans = BigNum_Subtraction(FirstNum, SecondNum, int_Mode);
            if(b_Flag == '-'){
                Complement(Ans.Content, &Ans.Length);
                ZeroFix(Ans.Content, &Ans.Length);
            }
            break;
        case 3:
            break;
    }
    printf("%s, %s, %c\n", FirstNum.Content, SecondNum.Content, b_Flag);
    printf("%c%s", b_Flag, Ans.Content);

    /*Release memory*/
    free(FirstNum.Content);
    free(SecondNum.Content);
    free(Ans.Content);
    return 0;
}