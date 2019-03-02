#ifndef GEOMETRY_H
#define GEOMETRY_H

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    point centre;
    double r;
} Circle;

typedef struct {
    point a;
    point b;
    point c;
} Triangle;

typedef struct {
} Polygon;

double Perimeter_Circle(double r);
double Areal_Circle(double r);

#endif
