#ifndef GEOMETRY_H
#define GEOMETRY_H
#define M_PI 3.14159265358979323846
#define EPS 1E-9
typedef struct {
    int type;
    double c[40];
    int size;
} Figure;

enum F { TRIANGLE = 1, CIRCLE = 2, POINT = 3 };

int Min(int a, int b);
int Max(int a, int b);
int Det(int a, int b, int c, int d);
int Between(int a, int b, double c);
void Swap(int* a, int* b);
int Intersect_1(int a, int b, int c, int d);
int InSecTrTr(Figure* a, Figure* b, int a_1, int b_1);
void InSecTrCir(Figure* a, Figure* b, int a_1, int b_1);
void InSecCirTr(Figure* a, Figure* b, int a_1, int b_1);
void InSecCirCir(Figure* a, Figure* b, int a_1, int b_1);
// int Intersection(Figure* x, Figure* y)
void Work(Figure* new);
void Print_Coordinats(Figure* new);
void S_Circle(double* S, Figure* new);
void P_Circle(double* P, Figure* new);
void Vector(Figure* new, double* a, double* b, double* c);
void S_Triangle(double* S, double a, double b, double c);
void P_Triangle(double* P, double a, double b, double c);

#endif
