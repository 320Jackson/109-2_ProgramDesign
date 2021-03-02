#include<stdio.h>

int main(){
    int x, y;
    int Hrs[2];

    for(int Run = 0; Run < 2; Run++){
        scanf("%d", &Hrs[Run]);
        fflush(stdin);
    }
    scanf("%d", &x);
    scanf("%d", &y);

    float f_TotalSalary, f_Taxes, f_LP;
    f_LP = y * 0.05;
    f_TotalSalary = (Hrs[0] * x) + (Hrs[1] * x);
    f_Taxes = f_TotalSalary * 0.08;

    printf("%.1f\n", f_TotalSalary - f_LP - f_Taxes);
    printf("%.1f\n", f_LP);
    printf("%.1f", f_Taxes);
}