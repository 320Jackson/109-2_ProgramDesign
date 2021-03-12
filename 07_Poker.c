#include<stdio.h>
#include<stdlib.h>
double getPoint();

int main(){
    double PointA, PointB;
    PointA = getPoint();
    if(PointA > 10.5){
        PointA = 0;
    }
    PointB = getPoint();
    if(PointB > 10.5){
        PointB = 0;
    }

    printf("%.1lf\n%.1lf\n", PointA, PointB);
    if(PointA > PointB){
        printf("A wins.");
    }
    else if(PointA < PointB){
        printf("B wins.");
    }
    else{
        printf("It's a tie.");
    }
    return 0;
}

double getPoint(){
    double Output = 0;
    for(int Run = 0; Run < 3; Run++){
        char Input[2];
        scanf("%s", &Input);
        if(Input[0] == 'A'){
            Output += 1;
        }
        else if(Input[0] == 'J' || Input[0] == 'Q' || Input[0] == 'K'){
            Output += 0.5;
        }
        else{
            Output += atof(Input);
        }
    }
    return Output;
}