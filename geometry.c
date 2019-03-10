#include "geometry.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        strcpy(new->type, B);
    } else if (!(strcmp(B, "circle"))) {
        strcpy(new->type, B);
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
    /*new->coordinates = (double*)realloc(new->coordinates, sizeof(double) * i);
    if (new->coordinates == NULL) {
      printf("Alloceted error");
      return 1;
    }*/
    return 0;
}
