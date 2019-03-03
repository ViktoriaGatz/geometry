#include "geometry.h"
#include <math.h>
#include <stdio.h>

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

int Counting_Figure(char* A)
{
    double all = 0;
    int i = 0;
    double k = 10;
    double j = 10;
    double n = 0;
    while (A[i] != '\0') {
        if (A[i] == 't') {
            if (A[i + 1] == 'r') {
                if (A[i + 2] == 'i') {
                    if (A[i + 3] == 'a') {
                        if (A[i + 4] == 'n') {
                            if (A[i + 5] == 'g') {
                                if (A[i + 6] == 'l') {
                                    if (A[i + 7] == 'e') {
                                        all += 1000000000;
                                        all += pow(j, n) * 100000;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if (A[i] == 'c') {
            if (A[i + 1] == 'i') {
                if (A[i + 2] == 'r') {
                    if (A[i + 3] == 'c') {
                        if (A[i + 4] == 'l') {
                            if (A[i + 5] == 'e') {
                                all += 10000;
                                all += pow(k, n);
                            }
                        }
                    }
                }
            }
        } else if (A[i] == '\n') {
          n++;
        }
        i++;
    }
    return all;
}
