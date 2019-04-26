#include "geometry.h"
#include "parser.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Min(int a, int b)
{
    if (a < b)
        return a;
    if (a > b)
        return b;
    return 0;
}

int Max(int a, int b)
{
    if (a < b)
        return b;
    if (a > b)
        return a;
    return 0;
}

int Det(int a, int b, int c, int d)
{
    return a * d - b * c;
}

int Between(int a, int b, double c)
{
    int exp_1;
    int exp_2;
    if (Min(a, b) <= c + EPS)
        exp_1 = 1;
    else
        exp_1 = 0;
    if (c <= Max(a, b) + EPS)
        exp_2 = 1;
    else
        exp_2 = 0;
    return exp_1 * exp_2;
}

void Swap(int* a, int* b)
{
    if (a && b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

int Intersect_1(int a, int b, int c, int d)
{
    if (a > b)
        Swap(&a, &b);
    if (c > d)
        Swap(&c, &d);
    if (Max(a, c) <= Min(b, d))
        return 1;
    if (Max(a, c) > Min(b, d))
        return 0;
    return 0;
}

int InSecTrTr(Figure* a, Figure* b, int a_1, int b_1)
{
    if (a && b && a_1 >= 0 && b_1 >= 0) {
        int A1, B1, C1;
        int A2, B2, C2;
        int zn;
        double x;
        double y;
        int bool;
        if (a->type == TRIANGLE || a->size == 8) {
            if (b->type == TRIANGLE || b->size == 8) {
                A1 = a->c[1] - a->c[3], B1 = a->c[2] - a->c[0],
                C1 = -A1 * a->c[0] - B1 * a->c[1];
                A2 = b->c[1] - b->c[3], B2 = b->c[2] - a->c[0],
                C2 = -A2 * b->c[0] - B2 * b->c[1];
                zn = Det(A1, B1, A2, B2);

                if (zn != 0) {
                    x = -Det(C1, B1, C2, B2) * 1. / zn;
                    y = -Det(A1, C1, A2, C2) * 1. / zn;

                    bool = Between(a->c[0], a->c[2], x)
                            * Between(a->c[1], a->c[3], y)
                            * Between(b->c[0], b->c[2], x)
                            * Between(b->c[1], b->c[3], y);
                    if (bool == 0) {
                        // параллельны или совпадают
                        return 1;
                    } else if (bool == 1) {
                        printf("Figure %d and %d intersection\n",
                               (a_1 + 1),
                               (b_1 + 1));
                        return 0;
                    }
                } else {
                    if ((Det(A1, C1, A2, C2) == 0)
                        && (Det(B1, C1, B2, C2) == 0)) {
                        if ((Intersect_1(a->c[0], a->c[2], b->c[0], b->c[2])
                             * Intersect_1(a->c[1], a->c[3], b->c[3], b->c[3]))
                            == 1) {
                            printf("Figure %d and %d "
                                   "intersection\n",
                                   (a_1 + 1),
                                   (b_1 + 1));
                            return 0;
                        }
                    }
                }
            }
        } else {
            return 1;
        }
    }
    return -1;
}

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
        printf("S = %.12f\nP = %.12f\n", S, P);
        printf("Coordinats:\n");
    }
    Print_Coordinats(new);
}

void Print_Coordinats(Figure* new)
{
    if (new == NULL) {
        return;
    }
    int j = 0;
    while (j < new->size) {
        printf("%d: %.2f\n", j + 1, new->c[j]);
        j++;
    }
}

void S_Circle(double* S, Figure* new)
{
    if (new == NULL) {
        *S = 0.0;
        return;
    } else if (new->type == CIRCLE) {
        if (new->size < 3 || new->c[2] <= 0) {
            *S = 0.0;
            return;
        }
        double r = new->c[2];
        *S = M_PI * (r * r);
        return;
    }
    *S = 0.0;
}

void P_Circle(double* P, Figure* new)
{
    if (new == NULL) {
        *P = 0.0;
        return;
    } else if (new->type == CIRCLE) {
        if (new->size < 3 || new->c[2] <= 0) {
            *P = 0.0;
            return;
        }
        double r = new->c[2];
        *P = 2 * M_PI * r;
        return;
    }
    *P = 0.0;
}

void Vector(Figure* new, double* a, double* b, double* c)
{
    if (new == NULL || a == NULL || b == NULL || c == NULL) {
        if (a)
            *a = 0;
        if (b)
            *b = 0;
        if (c)
            *c = 0;
        return;
    } else if (new->type == TRIANGLE && new->size >= 8) {
        *a
                = sqrt(pow((new->c[2] - new->c[0]), 2.0)
                       + pow((new->c[3] - new->c[1]), 2.0));
        *b
                = sqrt(pow((new->c[4] - new->c[2]), 2.0)
                       + pow((new->c[5] - new->c[3]), 2.0));
        *c
                = sqrt(pow((new->c[0] - new->c[4]), 2.0)
                       + pow((new->c[1] - new->c[5]), 2.0));
        return;
    }
    *a = *b = *c = 0;
    return;
}

void P_Triangle(double* P, double a, double b, double c)
{
    if (P == NULL) {
        return;
    }
    *P = a + b + c;
}

void S_Triangle(double* S, double a, double b, double c)
{
    if (S == NULL) {
        return;
    }
    double p = (a + b + c) / 2;
    *S = sqrt(p * (p - a) * (p - b) * (p - c));
}
