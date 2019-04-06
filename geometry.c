#include "geometry.h"
#include "parser.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M_PI 3.14159265358979323846

void Work(Figure* new)
{
    double S, P;
    double a, b, c;
    if (new->type == CIRCLE) {
        printf("Figure circle\n");
        S_Circle(&S, new);
        P_Circle(&P, new);
        printf("S = %.3f\nP = %.3f\n", S, P);
    } else if (new->type == TRIANGLE) {
        printf("Figure triangle\n");
        Vector(new, &a, &b, &c);
        P_Triangle(&P, a, b, c);
        S_Triangle(&S, a, b, c);
        printf("S = %.3f\nP = %.3f\n", S, P);
        printf("Coordinats:\n");
    }
    Print_Coordinats(new);
}

void Print_Coordinats(Figure* new)
{
    int j = 0;
    while (j < new->size) {
        printf("%d: %.2f\n", j + 1, new->c[j]);
        j++;
    }
}

void S_Circle(double* S, Figure* new)
{
    double r = new->c[2];
    *S = M_PI * (r * r);
}

void P_Circle(double* P, Figure* new)
{
    double r = new->c[2];
    *P = 2 * M_PI * r;
}

void Vector(Figure* new, double* a, double* b, double* c)
{
    *a
            = sqrt(pow((new->c[2] - new->c[0]), 2.0)
                   + pow((new->c[3] - new->c[1]), 2.0));
    *b
            = sqrt(pow((new->c[4] - new->c[2]), 2.0)
                   + pow((new->c[5] - new->c[3]), 2.0));
    *c
            = sqrt(pow((new->c[0] - new->c[4]), 2.0)
                   + pow((new->c[1] - new->c[5]), 2.0));
}

void P_Triangle(double* P, double a, double b, double c)
{
    *P = a + b + c;
}

void S_Triangle(double* S, double a, double b, double c)
{
    double p = (a + b + c) / 2;
    *S = sqrt(p * (p - a) * (p - b) * (p - c));
}
