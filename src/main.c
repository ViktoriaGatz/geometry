#include "geometry.h"
#include "parser.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* myfile;
    myfile = fopen("./example/myfile.txt", "r");
    if (myfile == NULL) {
        printf("No file\n");
        return 1;
    }
    int i = 0;
    int j = 0;
    printf("You input:\n");
    int capacity = 100;
    int size = 0;
    char arr[256];
    Figure* new = (Figure*)malloc(sizeof(Figure) * capacity);
    if (new == NULL) {
        printf("Alloceted error\n");
        return 1;
    }
    while ((arr[i++] = fgetc(myfile)) != EOF) {
        if (size < capacity) {
            if (arr[i - 1] == '\n') {
                arr[i - 1] = '\0';
                printf("-----str %d-----\n", size + 1);
                if (!(First_Character(arr)) && !(Parser(&new[size], arr))) {
                    Work(&new[size]);
                }
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
    // Figure a = {TRIANGLE, {-1, 0, 1, 0}, 8};
    // Figure b = {TRIANGLE, {0, -1, 0, 1}, 8};
    printf("SIZE: %d\n", size);
    for (i = 0; i < size; i++) {
        for (j = 0 + i; j < size; j++) {
            if (i != j) {
                // InSecTrTr(&a, &b, i, j);
                InSecTrTr(&new[i], &new[j], i, j);
                // InSecTrCir(&new[i], &new[j], i, j);
                // InSecCirTr(&new[i], &new[j], i, j);
                // InSecCirCir(&new[i], &new[j], i, j);
            }
        }
    }
    return 0;
}
