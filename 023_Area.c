#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f1(int a, double x) {
    return sqrt((double)a - pow(x, 2.0));
}

double f2(int a, double x) {
    return ((double)a * pow(x, 3.0) + (7.0 * x)) / sqrt(a + x);
}

int main() {
    int next;
    int mode;
    scanf("%d", &mode);
    do {
        int a, p, q, err;
        scanf("%d", &a);
        scanf("%d", &p);
        scanf("%d", &q);
        scanf("%d", &err);
        scanf("%d", &next);

        int n = 1;
        double PreArea = 0, NowArea = 0;
        do {
            PreArea = NowArea;
            NowArea = 0;
            double x = (double)(q - p) / (double)n;
            for (double i = p; i <= q; i += x) {
                if (mode == 1) {
                    if (i == p || i == q) {
                        NowArea += fabs(f1(a, i));
                    }
                    else {
                        NowArea += (2 * fabs(f1(a, i)));
                    }
                }
                else {
                    if (i == p || i == q) {
                        NowArea += fabs(f2(a, i));
                    }
                    else {
                        NowArea += (2 * fabs(f2(a, i)));
                    }
                }
            }
            NowArea *= (double)(q - p) / (2.0 * (double)n);
            n *= 2;
        }
        while ((fabs(NowArea - PreArea) >= pow(10.0, (double)(-err)) || (NowArea == 0)));
        printf("%.12lf\n", fabs(NowArea));
    }
    while (next != 0);
    return 0;
}