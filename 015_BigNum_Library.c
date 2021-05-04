#include <stdlib.h>
#include <math.h>
#include "015_BigNum_Library.h"

BigNum BigNum_Subtraction(BigNum Minute, BigNum Minus, int Mode){
    /*Deside result size*/
    int RunResult, ResultSize, Carry = 0;
    switch(Mode){
        case 1:
            ResultSize = 0;
            break;
        case 2:
            ResultSize = -1;
            break;
    }
    if(Minute.Length > Minus.Length){
        ResultSize += Minute.Length;
    }
    else{
        ResultSize += Minus.Length;
    }
    RunResult = ResultSize;

    /*Initialization*/
    BigNum Output;
    Output.Content = malloc(sizeof(char) * (ResultSize + 1));
    Output.Length = ResultSize + 1;
    Output.Content[RunResult] = '\0';
    RunResult--;

    /*Calculation*/
    int Run_Minute = Minute.Length - 2;
    int Run_Minus = Minus.Length - 2;
    while(RunResult >= 0){
        int Buffer;
        if(Run_Minute < 0 && Run_Minus >= 0){
            Buffer = (Minus.Content[Run_Minus] - 48) + Carry;
        }
        else if(Run_Minus < 0 && Run_Minute >= 0){
            Buffer = (Minute.Content[Run_Minute] - 48) + Carry;
        }
        else if(Run_Minus >= 0 && Run_Minute >= 0){
            Buffer = (Minute.Content[Run_Minute] - 48) + (Minus.Content[Run_Minus] - 48) + Carry;
        }
        else{
            if(Carry != 0){
                Output.Content[RunResult] = Carry + 48;
            }
            break;
        }
        Output.Content[RunResult] = (Buffer % 10) + 48;
        Carry = Buffer / 10;
        /*Index control*/
        Run_Minute--;
        Run_Minus--;        
        RunResult--;
    }
    if(Mode == 2){        
        for(int Run = 0; Run < abs(Minute.Length - Minus.Length); Run++){
            if(Minute.Length > Minus.Length){
                Output.Content[Run] = Minute.Content[Run];
            }
            else{
                Output.Content[Run] = Minus.Content[Run];
            }
        }
        ZeroFix(Output.Content, &ResultSize);
    }
    return Output;
}