#include <stdio.h>
#include <graphics.h>
#include <stddef.h>
#include <dos.h>
#include <alloc.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define PI 3.14159265
#define CENTERX 320
#define CENTERY 400
#define RADIUS  30
#define BACKCOLOR 1
#define FRONTCOLOR 6
#define OUTX   503
#define OUTY   8
int count = 7;
int mousex,mousey,mousekey;
void fruitup(void *bufferup,void *bufferapartl, void *bufferapartr, void *bufferclear, int fruitnum);
void mouseRead();
void clearscreen();
void clearscreenx();
void outch();
void outb();