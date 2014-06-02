#include <stdio.h>
#include <graphics.h>
#include <stddef.h>
#include <dos.h>
#include <alloc.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159265
#define CENTERX 320
#define CENTERY 400
#define RADIUS  30
#define BACKCOLOR 1
#define FRONTCOLOR 6
int count;
int colorstyle;
int mousex,mousey,mousekey;
void fruitup(void *bufferup,void *bufferapartl, void *bufferapartr, void *bufferclear, int fruitnum);
void mouseRead();
#define OUTX   455            /* 信息显示框的右边显示起始x坐标 */
#define OUTY   68             /* 信息显示框的右边显示起始y坐标 */
