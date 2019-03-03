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
    int i = 0;
    while ((arr[i] = fgetc(myfile)) != EOF) {
        i++;
    }
    arr[i] = '\0';
    double all = Counting_Figure(arr);
    if (all == 0) {
        printf("Error input\n");
        return 1;
    }
    printf("%.0f\n", all);
    Circle cle = {{0, 0}, 1.5};
    double p = Perimeter_Circle(cle.r);
    double s = Areal_Circle(cle.r);
    printf("%f, %f\n", p, s);
    return 0;
}
