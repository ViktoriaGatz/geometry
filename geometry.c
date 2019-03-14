#include "geometry.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRIANGLE 1
#define CIRCLE 2

int Parser(Figure* new, char* A)
{
    char B[256];
    int i = 0;
    while (A[i] >= 'a' && A[i] <= 'z') {
        B[i] = A[i];
        i++;
    }
    B[i] = '\0';
    if (!(strcmp(B, "triangle"))) {
        new->type = TRIANGLE;
    } else if (!(strcmp(B, "circle"))) {
        new->type = CIRCLE;
    } else {
        printf("Unknown type\n");
        return 1;
    }
    char* end;
    end = A;
    i = -1;
    new->coordinates = (double*)malloc(sizeof(double) * 100);
    if (new->coordinates == NULL) {
        printf("Alloceted error");
        return 1;
    }
    while (*A) {
        new->coordinates[i] = strtod(A, &end);
        A = end;
        i++;
        while (!(isdigit(*A) || *A == '-' || *A == '+') && *A) {
            A++;
        }
    }
    new->size = i;
    return 0;
}

void S_And_P_Circle(double* S, double* P, Figure* new)
{
    double r = new->coordinates[2];
    *S = M_PI * (r * r);
    *P = 2 * M_PI * r;
}

void S_And_P_Triangle(double* S, double* P, Figure* new)
{
    double a
            = sqrt(pow((new->coordinates[2] - new->coordinates[0]), 2.0)
                   + pow((new->coordinates[3] - new->coordinates[1]), 2.0));
    double b
            = sqrt(pow((new->coordinates[4] - new->coordinates[2]), 2.0)
                   + pow((new->coordinates[5] - new->coordinates[3]), 2.0));
    double c
            = sqrt(pow((new->coordinates[0] - new->coordinates[4]), 2.0)
                   + pow((new->coordinates[1] - new->coordinates[5]), 2.0));
    *P = a + b + c;
    double p = (a + b + c) / 2;
    *S = sqrt(p * (p - a) * (p - b) * (p - c));
}
