#include<stdio.h>
#include<math.h>

int main(){
    int Num[3];
    for(int Run = 0; Run < 3; Run++){
        scanf("%d", &Num[Run]);
    }

    double x1, x2;
    x1 = ((-Num[1]) + sqrt((Num[1] * Num[1]) - (4 * Num[0] * Num[2]))) / (2 * Num[0]);
    x2 = ((-Num[1]) - sqrt((Num[1] * Num[1]) - (4 * Num[0] * Num[2]))) / (2 * Num[0]);

    printf("%.1lf\n", x1);
    printf("%.1lf", x2);

    return 0;
}