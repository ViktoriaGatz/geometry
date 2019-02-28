#ifndef GEOMETRY_H
#define GEOMETRY_H

typedef struct {
    double x;
    double y;
} point;

typedef struct {
    struct point centre;
    double r;
} circle;

typedef struct {
    struct point a;
    struct point b;
    struct point c;
    struct point a_finish;
} triangle;

typedef struct {
} polygon;

double P_circle(double r);
double S_circle(double r);

#endif
