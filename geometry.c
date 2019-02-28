#include "geometry.h"
#include <math.h>
#include <stdio.h>
#define PI 3.14

double P_circle(double r)
{
    double p = 2 * PI * r;
    return p;
}

double S_circle(double r)
{
    double s = PI * r * r;
    return s;
}

void intersects()
