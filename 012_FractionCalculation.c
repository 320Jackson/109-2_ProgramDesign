#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int GCD(int a, int b){
    if(b == 0){
        return a;
    }
    return GCD(b, a % b);
}

int LCM(int a, int b){
    int GCDNum;
    if(a < b){
        GCDNum = GCD(b, a);
    }
    else{
        GCDNum = GCD(a, b);
    }
    return (a * b) / GCDNum;
}

int Calculation(int Num0, int Num1, char Symbol){
    switch(Symbol){
        case '+':
            return Num0 + Num1;
        case '-':
            return Num0 - Num1;
        case '*':
            return Num0 * Num1;
    }
}

void Pretreatment(int *Nump, int *Denump){
    if(*Denump < 0){
        *Nump = -(*Nump);
        *Denump = -(*Denump);
    }
}

int main(void){
    char Flag = 'y';
    while(Flag == 'y' || Flag == 'Y'){
        int Nump0 = 0, Nump1 = 0, Denump0 = 0, Denump1 = 0;
        char Symbol;
        /*Input fraction*/
        scanf("%d/%d", &Nump0, &Denump0);
        scanf("%d/%d", &Nump1, &Denump1);
        scanf(" %c", &Symbol);
        scanf(" %c", &Flag);
        if(Denump0 == 0 || Denump1 == 0){
            printf("ERROR\n");
            continue;
        }

        /*Pretreatment input number*/
        Pretreatment(&Nump0, &Denump0);
        if(Symbol == '/'){
            int Change = Nump1;
            Nump1 = Denump1;
            Denump1 = Change;
            Symbol = '*';
        }
        Pretreatment(&Nump1, &Denump1);
        

        /*Fraction calculate*/
        int Nump, Denump;
        if(Symbol == '+' || Symbol == '-'){
            Denump = LCM(Denump0, Denump1);
            Nump0 *= (Denump / Denump0);
            Nump1 *= (Denump / Denump1);
        }
        else{
            Denump = Calculation(Denump0, Denump1, Symbol);
        }
        Nump = Calculation(Nump0, Nump1, Symbol);
        
        /*Answer process*/
        char sign = ' ';
        if(Nump < 0){
            sign = '-';
            Nump = -Nump;
        }
        int Num = Nump / Denump;
        Nump = Nump % Denump;
        
        /*Reduce fraction*/
        if(Nump > Denump){
            int GCDNum = GCD(Nump, Denump);
            Nump /= GCDNum;
            Denump /= GCDNum;
        }
        else{
            int GCDNum = GCD(Denump, Nump);
            Nump /= GCDNum;
            Denump /= GCDNum;
        }

        /*Output*/
        if(sign == ' '){
            if(Nump == 0){
                printf("%d\n", Num);
            }
            else{
                if(Num == 0){
                    printf("%d/%d\n", Nump, Denump);
                }
                else{
                    printf("%d(%d/%d)\n", Num, Nump, Denump);
                }                
            }
        }
        else{
            if(Nump == 0){
                printf("-%d\n", Num);
            }
            else{
                if(Num == 0){
                    printf("-%d/%d\n", Nump, Denump);
                }
                else{
                    printf("-%d(%d/%d)\n", Num, Nump, Denump);
                }
            }
        }
    }
}