#include "geometry.h"
#include "parser.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b)
{
    if (a < b)
        return a;
    if (a > b)
        return b;
    return 0;
}

int max(int a, int b)
{
    if (a < b)
        return b;
    if (a > b)
        return a;
    return 0;
}

int det(int a, int b, int c, int d)
{
    return a * d - b * c;
}

int between(int a, int b, double c)
{
    int exp_1;
    int exp_2;
    if (min(a, b) <= c + EPS)
        exp_1 = 1;
    else
        exp_1 = 0;
    if (c <= max(a, b) + EPS)
        exp_2 = 1;
    else
        exp_2 = 0;
    return exp_1 * exp_2;
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int intersect_1(int a, int b, int c, int d)
{
    if (a > b)
        swap(&a, &b);
    if (c > d)
        swap(&c, &d);
    if (max(a, c) <= min(b, d))
        return 1;
    if (max(a, c) > min(b, d))
        return 0;
    return 0;
}

void InSecTrTr(Figure* a, Figure* b, int a_1, int b_1)
{
    if (a && b) {
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
                zn = det(A1, B1, A2, B2);

                if (zn != 0) {
                    x = -det(C1, B1, C2, B2) * 1. / zn;
                    y = -det(A1, C1, A2, C2) * 1. / zn;

                    bool = between(a->c[0], a->c[2], x)
                            * between(a->c[1], a->c[3], y)
                            * between(b->c[0], b->c[2], x)
                            * between(b->c[1], b->c[3], y);
                    if (bool == 0) {
                        return;
                    } else if (bool == 1) {
                        printf("Figure %d and %d intersection\n",
                               (a_1 + 1),
                               (b_1 + 1));
                    }
                } else {
                    if ((det(A1, C1, A2, C2) == 0)
                        && (det(B1, C1, B2, C2) == 0)) {
                        if ((intersect_1(a->c[0], a->c[2], b->c[0], b->c[2])
                             * intersect_1(a->c[1], a->c[3], b->c[3], b->c[3]))
                            == 1) {
                            printf("Figure %d and %d "
                                   "intersection\n",
                                   (a_1 + 1),
                                   (b_1 + 1));
                        }
                    }
                }
            }
        } else {
            return;
        }
    }
}

void InSecCirTr(Figure* a, Figure* b, int a_1, int b_1)
{
    if (a && b) {
        int A1, B1, C1;
        int A2, B2, C2;
        int zn;
        double x;
        double y;
        int bool;
        if (a->type == CIRCLE || a->size == 3) {
            if (b->type == TRIANGLE || b->size == 8) {
                for (int i = 0; i < 6; i += 2) {
                    A1 = a->c[2] * cos(0);
                    B1 = a->c[2] * sin(0);
                    C1 = pow(a->c[2], 2);
                    A2 = b->c[1 + i] - b->c[3 + i],
                    B2 = b->c[2 + i] - a->c[0 + i],
                    C2 = -A2 * b->c[0 + i] - B2 * b->c[1 + i];
                    zn = det(A1, B1, A2, B2);

                    if (zn != 0) {
                        x = -det(C1, B1, C2, B2) * 1. / zn;
                        y = -det(A1, C1, A2, C2) * 1. / zn;

                        bool = between(a->c[0 + i], a->c[2 + i], x)
                                * between(a->c[1 + i], a->c[3 + i], y)
                                * between(b->c[0 + i], b->c[2 + i], x)
                                * between(b->c[1 + i], b->c[3 + i], y);
                    }
                    if (bool >= 1) {
                        if ((det(A1, C1, A2, C2) == 0)
                            && (det(B1, C1, B2, C2) == 0)) {
                            if ((intersect_1(
                                         a->c[0 + i],
                                         a->c[2 + i],
                                         b->c[0 + i],
                                         b->c[2 + i])
                                 * intersect_1(
                                           a->c[1 + i],
                                           a->c[3 + i],
                                           b->c[3 + i],
                                           b->c[3 + i]))
                                == 1) {
                                printf("Figure %d and %d "
                                       "intersection\n",
                                       (a_1 + 1),
                                       (b_1 + 1));
                            }
                        }
                    }
                }
            } else {
                return;
            }
        }
    }
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
