#include <stdio.h>
#include <graphics.h>
#include <stddef.h>
#include <dos.h>
#include <alloc.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define PI 3.14159265
#define CENTERX 320
#define CENTERY 400
#define RADIUS  30
#define BACKCOLOR 1
#define FRONTCOLOR 6
#define OUTX   503
#define OUTY   15
#define TRUE   1
#define FALSE  0
#define STARTX 10
#define STARTY 60
#define SIZEY  20
int count;
int colorstyle;
int msvisible,mousex,mousey,mousekey;
int fruitup(void *bufferup,void *bufferapartl, void *bufferapartr, void *bufferclear, int fruitnum);
int init();
int read();
int newrecord();
void clrscr(void);
void cursor(),newxy();
void cursorOn();
void mouseRead();
void wait(int i);
void initboard();
void clearscreen();
void outscore();
void outbest();