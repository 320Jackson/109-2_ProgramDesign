#include<stdio.h>
#include<stdlib.h>

char *GrayCode(int, int);
char *getOriginCode(int, int);

int main(){
    int Mode; /*n個位元數, k號元素*/
    int n, k;

    while(1) {
        scanf("%d", &n);
        scanf("%d", &k);
        
        char *Code = GrayCode(k, n);
        printf("%s\n", Code);
        free(Code);

        scanf("%d", &Mode);
        if(Mode == -1){
            break;
        }
    }
    return 0;
}

char *GrayCode(int Data, int n){   
    char *OriginCode = getOriginCode(Data, n);
    char *Code = malloc(sizeof(char) * (n + 1));
    
    Code[0] = OriginCode[0];
    for(int Run = 1; Run <= n; Run++){
        if(Run == n){
            Code[Run] = '\0';
            break;
        }
        if(OriginCode[Run] == OriginCode[Run - 1]){
            Code[Run] = '0';
        }
        else{
            Code[Run] = '1';
        }
    }
    free(OriginCode);
    
    return Code;
}

char *getOriginCode(int Dec, int n){
    char *Code = malloc(sizeof(char) * n);
    for(int Run = n - 1; Run >= 0; Run--){
        Code[Run] = (Dec % 2) + 48;
        Dec /= 2;
    }
    return Code;
}