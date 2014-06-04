#define N1 64
#define N2 32
#define N4 16
#define N8 8
#define N16 4
#define END 0

void interrupt(* handler)( );
void interrupt music( );
int handle,control;



enum NOTES
{
    C10=131,D10=147,E10=165,F10=175,G10=196,A10=220,B10=247,
    C0=262, D0=296, E0=330, F0=349, G0=392, A0=440, B0=494,
    C1=523, D1=587, E1=659, F1=698, G1=784, A1=880, B1=988,
    C2=1047, D2=1175, E2=1319, F2=1397, G2=1568, A2=1760, B2=1796
}song[]={
    E1,N4,E1,N8,E1,N8,F1,N4,G1,N4,F1,N4,F1,N4,E1,N4,D1,
    N4,C1,N4,C1,N4,D1,N4,E1,N4,E1,N4,D1,N4,D1,N4,E1,N4,
    E1,N8,E1,N8,F1,N4,G1,N4,G1,N4,F1,N4,E1,N4,D1,N4,C1,
    N4,C1,N4,D1,N4,E1,N4,D1,N4,D1,N4,C1,N4,D1,N4,D1,N8,
    D1,N8,E1,N4,C1,N4,D1,N4,E1,N8,F1,N8,E1,N4,C1,N4,D1,
    N4,E1,N8,F1,N8,E1,N4,C1,N4,C1,N4,D1,N4,G0,N4,E1,N4,
    E1,N4,E1,N8,F1,N4,G1,N4,G1,N4,F1,N4,E1,N4,D1,N4,C1,
    N4,C1,N4,D1,N4,E1,N4,E1,N4,D1,N4,C1,N4,D1,N4,N4,E1,
    E1,N4,E1,N8,E1,N8,F1,N4,G1,N4,F1,N4,F1,N4,E1,N4,D1,
    N4,C1,N4,C1,N4,D1,N4,E1,N4,E1,N4,D1,N4,D1,N4,E1,N4,
    E1,N8,E1,N8,F1,N4,G1,N4,G1,N4,F1,N4,E1,N4,D1,N4,C1,
    N4,C1,N4,D1,N4,E1,N4,D1,N4,D1,N4,C1,N4,D1,N4,D1,N8,
    D1,N8,E1,N4,C1,N4,D1,N4,E1,N8,F1,N8,E1,N4,C1,N4,D1,
    N4,E1,N8,F1,N8,E1,N4,C1,N4,C1,N4,D1,N4,G0,N4,E1,N4,
    E1,N4,E1,N8,F1,N4,G1,N4,G1,N4,F1,N4,E1,N4,D1,N4,C1,
    N4,C1,N4,D1,N4,E1,N4,E1,N4,D1,N4,C1,N4,D1,N4,N4,E1,
    END,END
},song22[]={
	D0,N4,E0,N8,D0,N8,C0,N4,A10,N4,G10,N8,E10,N8,G10,N8,A10,N8,C0,N2,A10,N4,A10,N8,C0,N8,G10,N8,A0,N8,E0,N8,G0,N8,D0,N2,E0,N4,D0,N8,G0,N4,E0,N4,G0,N8,E10,N8,G10,N8,A10,N8,C0,N2,A10,N4,A10,N8,C0,N8,A10,N8,A10,N8,D10,N8,E10,N8,G10,N2,D0,N4,D0,N4,G0,N4,A0,N8,G0,N8,F0,N2,G0,N2,A0,N4,G0,N8,E0,N8,D0,N8,E0,N8,C0,N8,A10,N8,D0,N2,E0,N4,G0,N8,E0,N8,G0,N4,E0,N4,G10,N8,E10,N8,G10,N8,A10,N8,C0,N4,A10,N4,A10,N8,C0,N8,D0,N8,A10,N8,C0,N8,E0,N8,D0,N1,END,END
};

void interrupt music( )
    {
        static int note=0,fre,dur=8,flag=0;/*dur 为延迟时间,fre 为频率*/
		static clock_t goal=4;
        fre=song[note];
        if(flag==0){/*第一次读入时 goal 的值*/
			goal=clock()+(clock_t)dur;
			flag=1;
		}
        if(dur)
        {
            if(fre!=0){
            outportb(0x43,0xb6); /*打开计数器*/

            fre=(unsigned)(1193180L/fre);  /*计算频率*/
            outportb(0x42,(char)fre); /*将频率写入计时器*/
            outportb(0x42,(char)(fre>>8));
            control=inportb(0x61); /*从扬声器端口读出控制信息*/
            outportb(0x61,(control)|0x3); /*写入扬声器,使之发声。*/
			}
			if(goal<clock()) { /*实现了延迟*/
				note=note+2;
				dur=song[note+1];
				goal=clock()+(clock_t)dur;
			}

            if(note>=272)note=0;
			handler();
        }

    }
/*Music on*/
int musicon(){
	handler=getvect(0x1c);    /*music*/
	setvect(0x1c,music);

	return 0;
}
/*Music off*/
int musicoff(){
	outportb(0x61,control&0xfe);  /*关闭 PC 扬声器*/
	setvect(0x1c,handler);  /*将 0x1c 中断向量置成系统原有的处理例程*/

	return 0;
}
