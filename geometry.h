#ifndef GEOMETRY_H
#define GEOMETRY_H

typedef struct {
    int type;
    double c[40];
    int size;
} Figure;

enum F { TRIANGLE = 1, CIRCLE = 2, POINT = 3 };

void Work(Figure* new);
void S_And_P_Circle(double* S, double* P, Figure* new);
void S_And_P_Triangle(double* S, double* P, Figure* new);

#endif
