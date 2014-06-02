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
int mousex,mousey,mousekey;
void fruitup(void *bufferup,void *bufferapartl, void *bufferapartr, void *bufferclear, int fruitnum);
void mouseRead();
int main()
{
	int i,graphdriver,graphmode,fruitnum,num;
	unsigned memorysize;
	void *bufferup,*bufferapartl,*bufferapartr,*bufferclear;
	long anglef,angles;
	graphdriver = DETECT;
	initgraph(&graphdriver,&graphmode,"C:\\TC20\\BGI");
	setpalette(1,1);
	setpalette(4,4);
	setpalette(0,0);
	setcolor(FRONTCOLOR);
	cleardevice();
	setbkcolor(BACKCOLOR);
	setlinestyle(0,0,1);
	setfillstyle(1,5);
	/*Next part is about to draw an intact fruit.*/
	circle(CENTERX,CENTERY,RADIUS);
	floodfill(CENTERX,CENTERY,FRONTCOLOR);
	setlinestyle(0,0,3);
	line(CENTERX,CENTERY-24,CENTERX,CENTERY-40);
	setlinestyle(0,0,1);
    memorysize = imagesize(280,340,360,440);
	bufferup = malloc(memorysize);
	getimage(280,340,360,440,bufferup);
	cleardevice();
	/*Next part is about to draw a fruit which is splitted. */
	line( CENTERX+21, CENTERY+21, CENTERX-21, CENTERY-21);
	anglef = 135;
	arc(CENTERX, CENTERY, anglef, anglef+180,RADIUS);
	floodfill(CENTERX-10,CENTERY,FRONTCOLOR);
    memorysize = imagesize(280,340,360,440);
	bufferapartl = malloc(memorysize);
	getimage(280,340,360,440,bufferapartl);
	cleardevice();

	line( CENTERX-21, CENTERY+21, CENTERX+21, CENTERY-21);
	angles = 225;
	arc(CENTERX, CENTERY, angles, angles-180,RADIUS);
	floodfill(CENTERX+10,CENTERY,FRONTCOLOR);
    memorysize = imagesize(280,340,360,440);
	bufferapartr = malloc(memorysize);
	getimage(280,340,360,440,bufferapartr);
	cleardevice();
	/*This part is going to draw a rectangle whose color is backcolor.*/
    memorysize = imagesize(280,340,360,440);
	bufferclear = malloc(memorysize);
	getimage(280,340,360,440,bufferclear);
	cleardevice();

	/*This part is about to set the amount of fruits.*/
	randomize();
	for (num=0;num<5;num++)
	{
		fruitnum =1 + random(3);
		/*Next part is about to move the fruit.*/
		fruitup(bufferup,bufferapartl,bufferapartr,bufferclear,fruitnum);
	}
	free(bufferup);
	free(bufferapartl);
	free(bufferapartr);
	free(bufferclear);

}

void fruitup(void *bufferup,void *bufferapartl, void *bufferapartr, void *bufferclear, int fruitnum)
{
	int i,j,action = 0,color,x[3][3]={330,0,0,150,450,0,130,300,460};
	int y[2][5] = {400,400,400,400,400,1,1,1,1,1},modifier;
	float acceleration = 0.04,accelerationup = 0.04,speedup=4,speed[5]={1,1,1,1,1};
	j = fruitnum-1;
	do{
		if((inportb(0x3da)&0x08) != 0 && action == 0)
		{
			{
				for (i = 0;i<=j;i++)
				{
					if(y[1][i]==1)
					{
						putimage(x[j][i],y[0][i],bufferup,COPY_PUT);
						y[0][i] = y[0][i] - speedup;
					}
				}
				speedup = speedup - accelerationup;
				if (speedup == 0)
					speedup = -1;
				if (speedup == -6)
					acceleration = 0;
				mouseRead();
				for (i=0;i<=j;i++)
				{
					if (mousekey ==1 && mousex>x[j][i]-30 && mousex<x[j][i]+30)
					{
						color= getpixel(mousex,mousey);
						if (color == 4)
						{
							y[1][i] = 0;
							count++;
						}
					}
					if (y[1][i]==0)
					{	
						putimage(x[j][i],y[0][i],bufferapartl,COPY_PUT);
						putimage(x[j][i]+80,y[0][i],bufferapartr,COPY_PUT);
						y[0][i] = y[0][i] + speed[i];
						if (speed[i] != 4)
							speed[i] = speed[i] + acceleration;
					}
						if (y[0][i] > 400)
						{
						putimage(x[j][i],y[0][i],bufferclear,COPY_PUT);
						putimage(x[j][i]+80,y[0][i],bufferclear,COPY_PUT);
						y[1][i] = 2;
						}
				}

			for (i=0;y[1][i]==2 && i<fruitnum ;i++)
				;
			if (i == fruitnum)
				break;
				action = 1;
			}
		}
		
		else
		{
			if((inportb(0x3da)&0x08) == 0 &&action == 1)
			{
				for (i = 0;i<=j;i++)
				{
					if(y[1][i]==1)
					{
						putimage(x[j][i],y[0][i],bufferup,COPY_PUT);
						y[0][i] = y[0][i] - speedup;
					}
				}
				speedup = speedup - accelerationup;
				if (speedup == 0)
					speedup = -1;
				if (speedup == -6)
					acceleration = 0;
				mouseRead();
				for (i=0;i<=j;i++)
				{
					if (mousekey ==1 && mousex>x[j][i]-30 && mousex<x[j][i]+30)
					{	
						color= getpixel(mousex,mousey);
						if (color == 4)
							y[1][i] = 0;
					}
					if (color ==4 && mousekey ==1 && mousex>x[j][i]-30 && mousex<x[j][i]+30)
					if (y[1][i]==0)
					{	
						putimage(x[j][i],y[0][i],bufferapartl,COPY_PUT);
						putimage(x[j][i]+80,y[0][i],bufferapartr,COPY_PUT);
						y[0][i] = y[0][i] + speed[i];
						if (speed[i] != 4)
							speed[i] = speed[i] + acceleration;
					}
						if (y[0][i] > 400)
						{
						putimage(x[j][i],y[0][i],bufferclear,COPY_PUT);
						putimage(x[j][i]+80,y[0][i],bufferclear,COPY_PUT);
						y[1][i] = 2;
						}	
				}
			for (i=0;y[1][i]==2 && i<fruitnum ;i++)
				;
			if (i == fruitnum)
				break;
				action = 0;
			}
		}
	}while(1);

}

void mouseRead()
{
	union REGS r1,r2;
	struct SREGS s;
	r1.x.ax =3;
	int86x(0x33,&r1,&r2,&s);
	mousex = r2.x.cx;
	mousey = r2.x.dx;
	mousekey = r2.x.bx;
}
