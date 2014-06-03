#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<graphics.h>
#include<bios.h>
#include<fcntl.h>
int msvisible,mousex,mousey,mousekey;
#define TRUE 1

#define FALSE 0

int init();
int read();
void clrscr(void);
void cursorOn()
{
union REGS r;
struct SREGS s;
r.x.ax=1;
msvisible=TRUE;
int86x(0x33,&r,&r,&s);
}
void cursorOff()
{
union REGS r;
struct SREGS s;
r.x.ax=2;
msvisible=FALSE;
int86x(0x33,&r,&r,&s);
}
void mouseRead(){
union REGS r1,r2;
struct SREGS s;
r1.x.ax=3;
int86x(0x33,&r1,&r2,&s);
mousex=r2.x.cx;
mousey=r2.x.dx;
mousekey=r2.x.bx;
}
void wait(int i)
{
do{
mouseRead();
}while(mousekey==i);
}
void cursor(),newxy();
void main()
{
int i,graphdriver,graphmode,size,page;
int buttons,xm,ym,x0,y0,x,y;
char str[100];
int driver=VGA;
int mode=VGAHI;
char s[30];
graphdriver=DETECT;
initgraph(&graphdriver,&graphmode,"");
cleardevice();
cursorOn();
setbkcolor(GREEN);
setfillstyle(1,2);
setcolor(BLUE);
floodfill(50,50,14);
setfillstyle(1,13);
floodfill(10,100,18);
setcolor(YELLOW);
settextstyle(1,0,6);
outtextxy(100,60,"Fruit Naji");
setviewport(100,200,540,380,0);
setcolor(14);
setfillstyle(1,12);
rectangle(20,30,300,100);
settextstyle(2,0,18);
floodfill(30,100,14);
sprintf(s,"Start");
setcolor(YELLOW);
outtextxy(60,40,s);
setcolor(YELLOW);
settextstyle(4,0,3);
rectangle(20,150,300,210);
settextstyle(2,0,15);
outtextxy(60,160,"Exit");
setcolor(YELLOW);
for (; ;)
{
mouseRead();
if(mousex>=120&&mousex<=400&&mousey>=230&&mousey<=300&&mousekey==1)
{
clrscr();
cleardevice();
break;
}
if(mousex>=120&&mousex<=400&&mousey>=350&&mousey<=410&&mousekey==1)
exit(1);
}
}