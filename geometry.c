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

int Counting_Figure(char* figure)
{
    int all = 0;
    int i = 0;
    while (figure[i] != '\0') {
        if (figure[i] == 't') {
            if (figure[i + 1] == 'r') {
                if (figure[i + 2] == 'i') {
                    if (figure[i + 3] == 'a') {
                        if (figure[i + 4] == 'n') {
                            if (figure[i + 5] == 'g') {
                                if (figure[i + 6] == 'l') {
                                    if (figure[i + 7] == 'e') {
                                        all = all + 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if (figure[i] == 'c') {
            if (figure[i + 1] == 'i') {
                if (figure[i + 2] == 'r') {
                    if (figure[i + 3] == 'c') {
                        if (figure[i + 4] == 'l') {
                            if (figure[i + 5] == 'e') {
                                all = all + 10;
                            }
                        }
                    }
                }
            }
        }
        i++;
    }
    return all;
}
//-S
