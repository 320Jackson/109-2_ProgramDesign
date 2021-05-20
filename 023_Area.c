#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f1(double a, double x) {
    double output = sqrt(a - pow(x, 2.0));
    return output;
}

double f2(double a, double x) {
    return (a * pow(x, 3.0) + (7.0 * x)) / sqrt(a + x);
}

int main() {
    int next;
    int mode;
    scanf("%d", &mode);
    do {
        double a, p, q, err;
        scanf("%lf", &a);
        scanf("%lf", &p);
        scanf("%lf", &q);
        scanf("%lf", &err);
        scanf("%d", &next);

        int n = 1;
        double PreArea = 0, NowArea = 0;
        do {
            PreArea = NowArea;
            NowArea = 0;
            double x = (q - p) / (double)n;
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
            NowArea *= (q - p) / (2.0 * (double)n);
            n *= 2;
        }
        while ((fabs(NowArea - PreArea) >= pow(10.0, (-err)) || (NowArea == 0)));
        printf("%.12lf\n", fabs(NowArea));
    }
    while (next != 0);
    return 0;
}