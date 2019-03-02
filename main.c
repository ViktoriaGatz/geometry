#include "geometry.h"
#include <math.h>
#include <stdio.h>

int main()
{
    FILE* myfile;
    myfile = fopen("myfile.txt", "r");
    if (myfile == NULL) {
        printf("No file\n");
        return 1;
    }
    char arr[256];
    char figure[256];
    int i = 0;
    while ((arr[i] = fgetc(myfile)) != EOF) {
        i++;
    }
    Get_figure(arr, figure);
    printf("%s\n", figure);
    int all = Counting_Figure(figure);
    if (all == 0) {
        printf("Error input");
        return 1;
    }
    int triangle = all % 10;
    int circle = (all / 10) % 10;
    printf("all = %d\namount of triangles = %d\namount of circle = %d\n",
           all,
           triangle,
           circle);
    
    Circle cle = {{0, 0}, 1.5};
    double p = Perimeter_Circle(cle.r);
    double s = Areal_Circle(cle.r);
    printf("%f, %f\n", p, s);
    return 0;
}
