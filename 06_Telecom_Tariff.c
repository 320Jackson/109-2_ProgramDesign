#include<stdio.h>

typedef struct Tariff Tariff;
struct Tariff{
    double Inside;
    double Outside;
    double House;
    double InsideSMS;
    double OutsideSMS;
};
int Found_Best(Tariff);

int main(void){
    Tariff TelecomTariff;
    scanf("%lf", &TelecomTariff.Inside);
    scanf("%lf", &TelecomTariff.Outside);
    scanf("%lf", &TelecomTariff.House);
    scanf("%lf", &TelecomTariff.InsideSMS);
    scanf("%lf", &TelecomTariff.OutsideSMS);

    printf("%d", Found_Best(TelecomTariff));

    return 0;
}

int Found_Best(Tariff Input){    
    int Name[3] = {183, 383, 983};
    double Inside[3] = {0.08, 0.07, 0.06};
    double Outside[3] = {0.1393, 0.1304, 0.1087};
    double House[3] = {0.1349, 0.1217, 0.1018};
    double InsideSMS[3] = {1.1287, 1.1127, 0.9572};
    double OutsideSMS[3] = {1.4803, 1.2458, 1.1243};

    int Buffer[3];
    for(int Run = 0; Run < 3; Run++){
        Buffer[Run] = Input.Inside * Inside[Run];
        Buffer[Run] += Input.Outside * Outside[Run];
        Buffer[Run] += Input.House * House[Run];
        Buffer[Run] += Input.InsideSMS * InsideSMS[Run];
        Buffer[Run] += Input.OutsideSMS * OutsideSMS[Run];
        Buffer[Run] -= Name[Run];
        if(Buffer[Run] < Name[Run]){
            Buffer[Run] = Name[Run];
        }
    }

    int Output = Name[0];
    for(int Run = 0; Run < 2; Run++){
        if(Buffer[Run] >= Name[Run + 1]){
            Output = Name[Run + 1];
        }
        else{
            break;
        }
    }
    return Output;
}
