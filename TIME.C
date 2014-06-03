/***************************************
 *  								   *
 *	文件名： TIME.C					   *
 *  								   *
 *	功  能： 设置定时器，在游戏中计时  *
 *									   *
 ***************************************/

#define TIMER 0x1c /* 时钟中断的中断号 */

unsigned int TimerCounter =0;
int newtime= 40;
int mark=0;

/*定时器时间控制显示函数*/ 
void dispTime();

void interrupt (*oldtimer)(void);

void interrupt newtimer(void)
{
	(*oldtimer)();
	TimerCounter++; 
	if(TimerCounter>=18){
		TimerCounter = 0;
		dispTime(); 
	}
}
void setTimer(void interrupt (*IntProc)(void))
{
	oldtimer = getvect(TIMER);
	disable();
	setvect(TIMER,IntProc);
	enable();
}

/*****************************************************
 *  函数原型：int getTime()   						 *
 *  传入参数：无                                	 *
 *  返 回 值：若为0则游戏结束        				 *
 *  函数功能：获取剩余时间							 *
 *****************************************************/
int getTime()
{ 
	return newtime;
}
/*
if (getTime()==0)
{
	gameRes = -1;
	break;
}
*/
/*****************************************************
 *  函数原型：void killTimer()   					 *
 *  传入参数：无                                	 *
 *  返 回 值：无        							 *
 *  函数功能：移除定时器							 *
 *****************************************************/
void killTimer()
{
	disable();
	setvect(TIMER,oldtimer);
	enable();
}

/*****************************************************
 *  函数原型：void dispTime()   					 *
 *  传入参数：无                                	 *
 *  返 回 值：无        							 *
 *  函数功能：显示时间								 *
 *****************************************************/
void dispTime()
{
	char buf[64];

	sprintf(buf, "Time left: %c%c%c", 1, 1, 1);
	setcolor(BLACK);
	outtextxy(STARTX, STARTY-SIZEY-20, buf);

	sprintf(buf, "Time left: %c%c%c", 2, 2, 2);
	setcolor(BLACK);
	outtextxy(STARTX, STARTY-SIZEY-20, buf);

	newtime--;

	sprintf(buf, "Time left: %3d", newtime);
	setcolor(WHITE);
	outtextxy(STARTX, STARTY-SIZEY-20, buf);

	if(0==newtime)
		killTimer();
}