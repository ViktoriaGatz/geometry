#ifndef PARSER_H
#define PARSER_H
#include "geometry.h"

int Sumbol(char* arr);
int Parser(Figure* new, char* A);
int Coordinats(Figure* new, char* A);
int Extra_sumbol(char* arr, int i);
int Punctuation_for_triangle(char* arr, int i);
int Punctuation_for_circle(char* arr, int i);
int Punctuation(char* arr);
int First_Character(char* arr);

#endif
