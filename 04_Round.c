#include<stdio.h>
#define PI 3.14159

int main(){
    float f_r;
    scanf("%f", &f_r);

    float f_Area, f_Length;
    f_Area = f_r * f_r * PI;
    f_Length = (2 * f_r) * PI;

    printf("%.3f\n", f_Area);
    printf("%.3f", f_Length);
}