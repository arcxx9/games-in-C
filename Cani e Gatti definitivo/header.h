#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//-----------------------------------------------------------------------------
#define MAXSTEP 15
typedef char tchess [8][8];

double distance(int x1, int x2, int y1, int y2);
void place_animal(tchess s, char animal, int* yanimal, int* xanimal);
void move_cat(tchess s, char cat, int *ycat, int *xcat);
void step_dog(tchess s, char dog, int* ydog, int* xdog, int ycat, int xcat, int* alive);
void move_dog(tchess chess, char dog, int* ydog, int* xdog, int ycat1,int xcat1, int* alive1, int ycat2, int xcat2, int* alive2);
void print_chess(tchess s);
