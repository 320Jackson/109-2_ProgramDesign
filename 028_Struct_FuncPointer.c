#include <stdio.h>
#include <stdlib.h>
#include "028_Struct.h"
#include <math.h>

double getPerimeter() {
    char Type;
    scanf(" %c", &Type);

    double Ans = 0;
    if (Type == 'C') {
        Circle shape;
        NewCircle(&shape);
        Ans = shape.perimeter(&shape);
    }
    else if (Type == 'R') {
        Rectangle shape;
        NewRect(&shape);
        Ans = shape.perimeter(&shape);
    }
    else if (Type == 'S') {
        Square shape;
        NewSquare(&shape);
        Ans = shape.perimeter(&shape);
    }
    else {
        Triangle shape;
        NewTriangle(&shape);
        Ans = shape.perimeter(&shape);
    }
    printf("%.2lf\n", Ans);
    return Ans;
}

int main() {
    int Num;
    scanf("%d", &Num);

    double Ans = 0;
    for(int Run = 0; Run < Num; Run++) {
        Ans += getPerimeter();
    }
    printf("%.2lf", Ans);
    return 0;
}