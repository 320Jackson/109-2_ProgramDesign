#include<stdio.h>

int main(){
    int Base[3] = {0, 0, 0};
    int OCount = 0;
    for(int Run = 0; Run < 5; Run++){
        char Player;
        scanf(" %c", &Player);

        if(Player == 'O'){
            OCount += 1;
            if(OCount == 3){
                OCount = 0;
                for(int Count = 0; Count < 3; Count++){
                    Base[Count] = 0;
                }
            }
            continue;
        }
        else if(Player == 'H'){
            for(int Count = 0; Count < 3; Count++){
                Base[Count] = 0;
            }
        }
        else{
            int Limit = (int)Player - 49;
            for(int Count = 2; Count >= 0; Count--){
                if(Count > Limit){
                    Base[Count] = Base[Count - (Limit + 1)];
                }
                else if(Count == Limit){
                    Base[Count] = 1;
                }
                else{
                    Base[Count] = 0;
                }
            }
        }
    }

    //Output
    for(int Run = 0; Run < 3; Run++){
        printf("%d\n", Base[Run]);
    }
    return 0;
}