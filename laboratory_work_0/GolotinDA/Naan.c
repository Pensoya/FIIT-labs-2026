
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main() {
    double x1, y1, r1, x2, y2, r2;
    printf("Введите x1, y1, r1:\n");
    scanf("%lf %lf %lf", &x1, &y1, &r1);
    printf("Введите x2, y2, r2:\n");
    scanf("%lf %lf %lf", &x2, &y2, &r2);
    double dist = pow(pow(x1-x2, 2)+pow(y1-y2, 2), 0.5);
    double ans = dist-(r1+r2);
    if (ans<=0) {
        printf("0\n");
    } else {
        printf("%lf\n", ans);
    }
    return 0;
}
