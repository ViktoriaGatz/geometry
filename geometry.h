#ifndef GEOMETRY_H
#define GEOMETRY_H

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point centre;
    double r;
} Circle;

typedef struct {
    Point a;
    Point b;
    Point c;
} Triangle;

typedef struct {
} Polygon;

double Perimeter_Circle(double r);
double Areal_Circle(double r);
int Counting_Figure(char* array);

#endif
