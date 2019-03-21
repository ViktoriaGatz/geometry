
#include "geometry.h"
#include "parser.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRIANGLE 1
#define CIRCLE 2

int Parser(Figure* new, char* A)
{
  char B[256];
  int i = 0;
  while (A[i] >= 'a' && A[i] <= 'z') {
    B[i] = A[i];
    i++;
  }
  B[i] = '\0';
  Coordinats(new, A);
  if (!(strcmp(B, "triangle"))) {
    new->type = TRIANGLE;
    return 0;
  } else if (!(strcmp(B, "circle"))) {
    new->type = CIRCLE;
    return 0;
  } else {
    printf("Unknown type\n");
    return 1;
  }
}

int Coordinats(Figure* new, char* A)
{
  char* end;
  end = A;
  int i = -1;
  while (*A) {
    new->c[i] = strtod(A, &end);
    A = end;
    i++;
    while (!(isdigit(*A) || *A == '-' || *A == '+') && *A) {
      A++;
    }
  }
  new->size = i;
  return 0;
}


int Extra_sumbol(char* arr, int i)
{
  for (int j = i; arr[j] != '\0'; j++) {
    if (arr[j] > 'a' && arr[j] < 'z') {
      printf("Extra sumbol\n");
      return 1;
    }
  }
  return 0;
}

int Punctuation_for_triangle(char* arr, int i)
{
  int k = 0;
  int j;
  for (j = i; arr[j] != '\0'; j++) {
    if (arr[j] == ',') {
      k++;
    }
  }
  if (k == 3) {
    if (!(arr[j - 2] == ')' && arr[j - 1] == ')')) {
      printf("lacks ')'\n");
      return 1;
    }
  } else {
    printf("lacks or extra ','\n");
    return 1;
  }
  return 0;
}

int Punctuation_for_circle(char* arr, int i)
{
  int k = 0;
  int j;
  for (j = i; arr[j] != '\0'; j++) {
    if (arr[j] == ',') {
      k++;
    }
  }
  if (k == 1) {
    if (!(arr[j - 1] == ')')) {
      printf("lacks ')'\n");
      return 1;
    }
  } else {
    printf("lacks or extra ','\n");
    return 1;
  }
  return 0;
}

int Punctuation(char* arr)
{
  int done = 0;
  for (int i = 0; arr[i] != '\0'; i++) {
    if (arr[i] == '(') {
      if (arr[i + 1] == '(') {
        done = 1;
        Extra_sumbol(arr, (i + 1));
        Punctuation_for_triangle(arr, (i + 1));
        return 0;
      } else {
        done = 1;
        Extra_sumbol(arr, i);
        Punctuation_for_circle(arr, i);
        return 0;
      }
    }
  }
  if (done == 0) {
    printf("Punctuation error (lacks '(')\n");
    return 1;
  }
  return 0;
}

int First_Character(char* arr)
{
  if (arr[0] > 'a' && arr[0] < 'z') {
    Punctuation(arr);
  } else {
    printf("Error in the first character.\n");
  }
  return 0;
}
