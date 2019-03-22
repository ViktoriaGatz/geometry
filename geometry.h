#ifndef GEOMETRY_H
#define GEOMETRY_H

typedef struct {
    int type;
    double c[40];
    int size;
} Figure;

enum F { TRIANGLE = 1, CIRCLE = 2, POINT = 3 };

void Work(Figure* new);
void Print_Coordinats(Figure* new);
void S_Circle(double* S, Figure* new);
void P_Circle(double* P, Figure* new);
void Vector(Figure* new, double* a, double* b, double* c);
void P_Triangle(double* P, double a, double b, double c);
void S_Triangle(double* S, double a, double b, double c);

#endif
