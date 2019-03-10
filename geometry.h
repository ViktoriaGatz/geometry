#ifndef GEOMETRY_H
#define GEOMETRY_H

typedef struct {
    char type[256];
    double* coordinates;
    int size;
} Figure;

double Perimeter_Circle(double r);
double Areal_Circle(double r);
int Parser(Figure* new, char* A);

#endif
