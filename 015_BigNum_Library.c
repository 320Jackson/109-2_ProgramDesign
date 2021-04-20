#include <stdlib.h>
#include "015_BigNum_Library.h"

char *BigNum_Addition(BigNum Summand, BigNum Addend){
    /*Decide result size*/
    int ResultSize, Carry = 0;
    if(Addend.Length > Summand.Length){
        ResultSize = Addend.Length;
    }
    else{
        ResultSize = Summand.Length;
    }

    /*Initialization*/
    char *Result = malloc(sizeof(char) * (ResultSize + 1));
    Result[ResultSize] = '\0';
    ResultSize -= 1;
    
    /*Calculation*/
    int Run_Summand = Summand.Length - 2;
    int Run_Addend = Addend.Length - 2;
    while(ResultSize >= 0){
        int Buffer;
        if(Run_Summand < 0 && Run_Addend >= 0){
            Buffer = (Addend.Content[Run_Addend] - 48) + Carry;
        }
        else if(Run_Addend < 0 && Run_Summand >= 0){
            Buffer = (Summand.Content[Run_Summand] - 48) + Carry;
        }
        else if(Run_Addend >= 0 && Run_Summand >= 0){
            Buffer = (Summand.Content[Run_Summand] - 48) + (Addend.Content[Run_Addend] - 48) + Carry;
        }
        else{
            if(Carry != 0){
                Result[ResultSize] = Carry + 48;
            }
            break;
        }
        Result[ResultSize] = (Buffer % 10) + 48;
        Carry = Buffer / 10;
        /*Index control*/
        Run_Summand--;
        Run_Addend--;
        ResultSize--;
    }
    return Result;
}

char *BigNum_Subtraction(BigNum Minute, BigNum Minus){
    /*Deside result size*/
    int ResultSize, Carry;
    if(Minute.Length > Minus.Length){
        ResultSize = Minute.Length;
    }
    else{
        ResultSize = Minus.Length;
    }

    /*Initialization*/
    char *Result = malloc(sizeof(char) * (ResultSize + 1));
    Result[ResultSize] = '\0';
    ResultSize -= 1;

    /*Calculation*/
}