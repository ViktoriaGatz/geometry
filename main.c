#include "geometry.h"
#include "parser.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* myfile;
    myfile = fopen("myfile.txt", "r");
    if (myfile == NULL) {
        printf("No file\n");
        return 1;
    }
    printf("You input:\n");
    int capacity = 100;
    int size = 0;
    char arr[256];
    int i = 0;
    Figure* new = (Figure*)malloc(sizeof(Figure) * capacity);
    if (new == NULL) {
        printf("Alloceted error\n");
        return 1;
    }
    while ((arr[i++] = fgetc(myfile)) != EOF) {
        if (size < capacity) {
            if (arr[i - 1] == '\n') {
                arr[i - 1] = '\0';
                First_Character(arr);
                Parser(&new[size], arr);
                size++;
                i = 0;
            }
        } else {
            capacity *= 2;
            new = (Figure*)realloc(new, capacity * sizeof(double));
            if (new == NULL) {
                printf("Alloceted error\n");
                return 1;
            }
        }
    }
    for (i = 0; i < size; i++) {
        double S, P;
        if (new[i].type == CIRCLE) {
            printf("Figure circle\n");
            S_And_P_Circle(&S, &P, &new[i]);
            printf("S = %.3f\nP = %.3f\n", S, P);
        } else if (new[i].type == TRIANGLE) {
            printf("Figure triangle\n");
            S_And_P_Triangle(&S, &P, &new[i]);
            printf("S = %.3f\nP = %.3f\n", S, P);
        }
        /*int j = 0;
        while (j < new[i].size) {
            printf("coordinat %d: %.2f\n", j + 1, new[i].c[j]);
            j++;
        }*/
    }
    return 0;
}
