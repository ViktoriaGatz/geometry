#ifndef GEOMETRY_H
#define GEOMETRY_H

typedef struct {
    int type;
    double* coordinates;
    int size;
} Figure;

int Parser(Figure* new, char* A);
void S_And_P_Circle(double* S, double* P, Figure* new);
void S_And_P_Triangle(double* S, double* P, Figure* new);

#endif
