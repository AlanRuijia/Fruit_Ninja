#include "Fruit.h"

void main()
{
        int i,graphdriver,graphmode,fruitnum,k,page;
        unsigned memorysize;
        void *bomb,*bufferup,*bufferapartl,*bufferapartr,*bufferclear,*orange,*orangeleft,*orangeright;
        long anglef,angles;
        int buttons,xm,ym,x0,y0,x,y;
        char str[100];
        char s[30];
        graphdriver=DETECT;
        initgraph(&graphdriver,&graphmode,"C:\\TC20\\BGI");
        cleardevice();
        setlinestyle(0,0,3);
        setbkcolor(10);
        line(100,120,200,120);
        line(100,121,200,121);
        line(100,122,200,122);
        putpixel(100,120,RED);
        putpixel(101,120,RED);
        putpixel(102,120,RED);
        putpixel(103,120,RED);
        setcolor(4);
        setfillstyle(1,2);
        setcolor(4);
        floodfill(50,50,18);
        setfillstyle(1,13);
        floodfill(20,100,18);
        setcolor(YELLOW);
        settextstyle(1,0,6);
        outtextxy(100,60,"Fruit Ninja");
        setviewport(100,200,540,380,0);
        setcolor(14);
        setfillstyle(1,12);
        rectangle(20,30,300,100);
        settextstyle(3,0,6);
        floodfill(21,100,14);
        sprintf(s,"Start");
        setcolor(YELLOW);
        outtextxy(60,40,s);
        setcolor(YELLOW);
        settextstyle(3,0,6);
        rectangle(20,150,300,210);
        settextstyle(3,0,5);
        outtextxy(60,160,"Exit");
        setcolor(YELLOW);
        cursorOn();
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
        initgraph(&graphdriver,&graphmode,"C:\\TC20\\BGI");
        setpalette(1,1);
        setpalette(4,4);
        setpalette(0,0);
        setcolor(FRONTCOLOR);
        cleardevice();
        setbkcolor(BACKCOLOR);
        setlinestyle(0,0,1);
        setfillstyle(1,4);
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

        /*The next part is about to draw an orange.*/
        setcolor(14);
        circle(CENTERX,CENTERY,RADIUS);
        setfillstyle(1,14);
        floodfill(CENTERX,CENTERY,14);  
        setlinestyle(0,0,3);
        setcolor(2);
        setfillstyle(1,4);
        line(CENTERX,CENTERY-4,CENTERX,CENTERY-10);
        line(CENTERX-3,CENTERY-7,CENTERX+3,CENTERY-7);
        setlinestyle(0,0,1);
        setcolor(FRONTCOLOR);
        memorysize = imagesize(280,340,360,440);
        orange = malloc(memorysize);
        getimage(280,340,360,440,orange);
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

        /*Orange apart.*/
        setcolor(14);
        setfillstyle(1,14);
        line( CENTERX+21, CENTERY+21, CENTERX-21, CENTERY-21);
        anglef = 135;
        arc(CENTERX, CENTERY, anglef, anglef+180,RADIUS);
        floodfill(CENTERX-10,CENTERY,14);
        memorysize = imagesize(280,340,360,440);
        orangeleft = malloc(memorysize);
        getimage(280,340,360,440,orangeleft);
        cleardevice();

        line( CENTERX-21, CENTERY+21, CENTERX+21, CENTERY-21);
        angles = 225;
        arc(CENTERX, CENTERY, angles, angles-180,RADIUS);
        floodfill(CENTERX+10,CENTERY,14);
        memorysize = imagesize(280,340,360,440);
        orangeright = malloc(memorysize);
        getimage(280,340,360,440,orangeright);
        cleardevice();

        /*bomb*/
        setcolor(15);
        setfillstyle(1,15);
        circle(CENTERX,CENTERY,RADIUS);
        floodfill(CENTERX,CENTERY,15);
        setcolor(FRONTCOLOR);
        setlinestyle(0,0,3);
        line(CENTERX,CENTERY-24,CENTERX,CENTERY-40);
        setcolor(4);
        line(CENTERX,CENTERY-38,CENTERX,CENTERY-40);
        setlinestyle(0,0,1);
        memorysize = imagesize(280,340,360,440);
        bomb = malloc(memorysize);
        getimage(280,340,360,440,bomb);
        cleardevice();

        /*This part is going to draw a rectangle whose color is backcolor.*/
        memorysize = imagesize(280,340,360,440);
        bufferclear = malloc(memorysize);
        getimage(280,340,360,440,bufferclear);
        cleardevice();

        /*This part is about to init the score board.*/
        initboard();
        outscore();
        outbest();

        /*This part is about to set the amount of fruits.*/
        randomize();
        cursorOn();
        for (;;)
        {
                fruitnum =1 + random(3);
                /*Next part is about to move the fruit.*/
                colorstyle =random(3);
                if (colorstyle == 0)
                        k = fruitup(bufferup,bufferapartl,bufferapartr,bufferclear,fruitnum);
                if (colorstyle == 1)
                        k = fruitup(orange,orangeleft,orangeright,bufferclear,fruitnum);
                if (colorstyle == 2)
                        k = fruitup(bomb,orangeleft,orangeright,bufferclear,fruitnum);
                if (k == 1)
                {
                        cleardevice();
                        /*
                        if (newrecord())
                        {
                        		setcolor(3);
                        		settextstyle(1,0,6);
                        		outtextxy(200,200,"Cong! New record!");	
                        }
                        */
                        newrecord();
                        setcolor(4);
                        settextstyle(1,0,6);
                        outtextxy(200,200,"You Lose!");	
                        break;
                }
        }

        free(bufferup);
        free(bufferapartl);
        free(bufferapartr);
        free(bufferclear);
        free(orange);
        free(orangeleft);
        free(orangeright);
        free(bomb);
}

int fruitup(void *bufferup,void *bufferapartl, void *bufferapartr, void *bufferclear, int fruitnum)
{
        int i,j,action = 0,color,x[3][3]={330,0,0,150,450,0,130,300,460};
        int y[2][5] = {400,400,400,400,400,1,1,1,1,1},modifier,judge;
        float acceleration = 0.04,accelerationup = 0.04,speedup=4,speed[5]={1,1,1,1,1};
        if (colorstyle == 0)
                judge = 4;
        if (colorstyle == 1)
                judge = 14;
        if (colorstyle == 2)
        {
                judge = 15;
                fruitnum = 1;
        }
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
                                                x[i][j] = x[i][j] +1;
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
                                                if (color == judge && judge != 15)
                                                {
                                                        y[1][i] = 0;
                                                        count++;
														outscore();
                                                }
                                                if (color == judge && judge == 15)
                                                        return 1;
                                        }
                                        if (y[1][i]==0)
                                        {	
                                                putimage(x[j][i],y[0][i],bufferapartl,COPY_PUT);
                                                putimage(x[j][i]+80,y[0][i],bufferapartr,COPY_PUT);
                                                y[0][i] = y[0][i] + speed[i];
                                                if (speed[i] != 4)
                                                        speed[i] = speed[i] + acceleration;
                                        }
                                        if (y[0][i] > 400 || x[i][j] >= 600 || x[i][j] <= 30)
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
                        if ((inportb(0x3da)&0x08) == 0 &&action == 1)
                        {
                                {
                                        for (i = 0;i<=j;i++)
                                        {
                                                if (y[1][i]==1)
                                                {
                                                        putimage(x[j][i],y[0][i],bufferup,COPY_PUT);
                                                        y[0][i] = y[0][i] - speedup;
                                                        x[i][j] = x[i][j] +1;
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
                                                        if (color == judge && judge != 15)
                                                        {
                                                                y[1][i] = 0;
                                                                count++;
																outscore();
                                                        }
                                                        if (color == judge && judge == 15)
                                                                return 1;
                                                }
                                                if (y[1][i]==0)
                                                {	
                                                        putimage(x[j][i],y[0][i],bufferapartl,COPY_PUT);
                                                        putimage(x[j][i]+80,y[0][i],bufferapartr,COPY_PUT);
                                                        y[0][i] = y[0][i] + speed[i];
                                                        if (speed[i] != 4)
                                                                speed[i] = speed[i] + acceleration;
                                                }
                                                if (y[0][i] > 400 || x[i][j] >= 600 || x[i][j] <= 30)
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
                }
        } while (1);

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

void cursorOn()
{
    union REGS r;
    struct SREGS s;
    r.x.ax=1;
    msvisible=TRUE;
    int86x(0x33,&r,&r,&s);
}

void wait(int i)
{
    do {
        mouseRead();
    } while (mousekey==i);
}

/*****************************************************
 *  函数原型：void initboard()   					 *
 *  传入参数：无                                	 *
 *  返 回 值：无                                     *
 *  函数功能：初始化计分板							 *
 *****************************************************/
void initboard()
{
        setfillstyle(SOLID_FILL,GREEN);
        bar(500,10,635,50);

}

/*****************************************************
 *  函数原型：void clearscreen()   				 *
 *  传入参数：无                                	 *
 *  返 回 值：无                                     *
 *  函数功能：清空刷新计分板						 *
 *****************************************************/
void clearscreen()
{
        setfillstyle(SOLID_FILL,GREEN);
        bar(500,10,635,30);

}

/*****************************************************
 *  函数原型：void outscore()   					 *
 *  传入参数：无                                	 *
 *  返 回 值：无                                     *
 *  函数功能：输出当前得分							 *
 *****************************************************/
void outscore()
{
        int i=0,fig;
        char FIG[8];
        char temp[2]="";
        long int xu;
        xu = count * 100;
        clearscreen();
        settextstyle(1, 0, 1);
        outtextxy(OUTX,OUTY,"Score:");
        while (xu!=0)
        {
                FIG[i++]=xu%10+'0';
                xu=floor(xu/10);
        }
        for (fig=0;fig<i;fig++)
        {
                temp[0]=FIG[fig];
                settextstyle(1, 0, 1);
                outtextxy(OUTX+60+15*(i-fig),OUTY,temp);
        }
}

/*****************************************************
 *  函数原型：void outscore()   					 *
 *  传入参数：无                                	 *
 *  返 回 值：无                                     *
 *  函数功能：输出最高得分							 *
 *****************************************************/
void outbest()
{
        FILE *fp;
        int i=0,fig;
        char FIG[8];
        char temp[2]="";
        fp = fopen("BEST.TXT", "r");
        fgets(FIG, 10, fp);
        fclose(fp);
        settextstyle(1, 0, 1);
        outtextxy(OUTX,OUTY+20,"Best :");
        i = strlen(FIG);
        for (fig=0;fig<i;fig++)
        {
                temp[0]=FIG[fig];
                settextstyle(1, 0, 1);
                outtextxy(OUTX+75+15*(fig),OUTY+20,temp);
        }
}

/*****************************************************
 *  函数原型：int newrecord()   					 *
 *  传入参数：无                                	 *
 *  返 回 值：若破纪录返回1，未破纪录则返回0         *
 *  函数功能：输出最高得分							 *
 *****************************************************/

 /* 在游戏结束时调用.如果破纪录则返回1，未破纪录返回0，该注释写完即可删除 */
int newrecord()
{
		FILE *fp;
		int num = 0;
		int i, j;
		char FIG[8];
		int tmp = 1;
		char newbest[8];
		int flag = FALSE;
		fp = fopen("BEST.TXT", "r+");
        fgets(FIG, 10, fp);
        fclose(fp);
        for (i = 0; i < strlen(FIG); ++i)
        {
        		num = num*10 + (FIG[i]-'0');
        }
        
		if (num < count*100)
		{
				flag = TRUE;
				fp = fopen("BEST.TXT", "w");
				/* convert number to string */
				for (i = 0; ; ++i)
				{
						if(!(count/tmp))
						{
								break;
						}
						tmp *= 10;
				}
				for (j = i-1; j >= 0; --j)
				{
					newbest[j] = count%10+'0';
                	count /= 10;
				}
				newbest[i] = '0';
				newbest[i+1] = '0';
				newbest[i+2] = '\0';

				/* write into the file */
				fputs(newbest, fp);
				fclose(fp);
		}
		return flag;
}