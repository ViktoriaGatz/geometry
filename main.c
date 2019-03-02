#include "geometry.h"
#include <math.h>
#include <stdio.h>

int main()
{
    circle cle = {{0, 0}, 1.5};
    double p = Perimeter_Circle(cle.r);
    double s = Areal_Circle(cle.r);
    printf("%f, %f\n", p, s);
    return 0;
}
