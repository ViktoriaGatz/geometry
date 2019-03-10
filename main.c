#include "geometry.h"
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
    int capacity = 100;
    int size = 0;
    char arr[256];
    int i = 0;
    Figure* new = (Figure*)malloc(sizeof(Figure) * capacity);
    while ((arr[i++] = fgetc(myfile)) != EOF) {
        if (size < capacity) {
            if (arr[i - 1] == '\n') {
                arr[i - 1] = '\0';
                Parser(&new[size], arr);
                size++;
                i = 0;
            }
        } else {
            capacity *= 2;
            new = (Figure*)realloc(new, capacity * sizeof(double));
        }
    }
    int j;
    for (i = 0; i < size; i++) {
        printf("Figure %s\n", new[i].type);
        j = 0;
        while (j < new[i].size) {
            printf("coordinat %d: %.2f\n", j + 1, new[i].coordinates[j]);
            j++;
        }
    }
    return 0;
}
