#include "geometry.h"
#include <math.h>
#include <stdio.h>
#define PI 3.14

int main()
{
    struct circle cle = {0, 0, 1.5};
    double p = P_circle(cle.r);
    double s = S_circle(cle.r);
    printf("%f, %f\n", p, s);
    return 0;
}
