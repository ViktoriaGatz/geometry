#include "geometry.h"
#include "parser.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M_PI 3.14159265358979323846

void S_And_P_Circle(double* S, double* P, Figure* new)
{
    double r = new->c[2];
    *S = M_PI * (r * r);
    *P = 2 * M_PI * r;
}

void S_And_P_Triangle(double* S, double* P, Figure* new)
{
    double a
            = sqrt(pow((new->c[2] - new->c[0]), 2.0)
                   + pow((new->c[3] - new->c[1]), 2.0));
    double b
            = sqrt(pow((new->c[4] - new->c[2]), 2.0)
                   + pow((new->c[5] - new->c[3]), 2.0));
    double c
            = sqrt(pow((new->c[0] - new->c[4]), 2.0)
                   + pow((new->c[1] - new->c[5]), 2.0));
    *P = a + b + c;
    double p = (a + b + c) / 2;
    *S = sqrt(p * (p - a) * (p - b) * (p - c));
}
