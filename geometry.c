#include "geometry.h"
#include <math.h>
#include <stdio.h>

double Perimeter_Circle(double r)
{
    double p = 2 * M_PI * r;
    return p;
}

double Areal_Circle(double r)
{
    double s = M_PI * (r * r);
    return s;
}

void Intersects(){}
