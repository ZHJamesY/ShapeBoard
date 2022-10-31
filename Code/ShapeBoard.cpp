#include <winbgim.h>

using namespace std;

void Buttons();
void Move(int &,int &, int,int &c);
void Erase();
void cir(int x,int y);
int main()
{
	int x,y,k,t=1,c;
	c=1+rand()%15;
	initwindow(1000,1000);
	setcolor(14);
	Buttons();
	while(1)
	{
		delay(0.1);
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN,x,y);
			if((y>10&&y<80)&&(x>150&&x<1000)) k=(x-150)/70+1;
			else k=0; 
			switch(k)
			{
				case 1: Erase(); settextstyle(8,HORIZ_DIR,12);
						outtextxy(240,300,"A"); t=1; break;
				case 2: Erase(); settextstyle(8,HORIZ_DIR,12);
						outtextxy(240,300,"B"); t=2; break;
				case 3: Erase(); break;
				case 4: Erase(); setfillstyle(3,c); 
						bar(200,300,400,500); t=4; break;
				case 5: Erase(); setfillstyle(3,c);
						bar(200,350,400,450); t=5; break;
				case 6: Erase(); setcolor(c);
						cir(400,400); t=6; break;
				case 7: Erase(); setcolor(c);
						rectangle(200,400,400,600); t=7; break;
				case 8: Erase(); 
						rectangle(200,400,400,500); t=8; break;
				case 9: c=c%15+1; setcolor(c); settextstyle(8,HORIZ_DIR,2);
						outtextxy(715,30,"Color"); break; 
				case 10: Erase(); setfillstyle(1,c); setcolor(c);
						 fillellipse(400,400,100,100); t=10; break;
				case 0: Move(x,y,t,c);
			}
		}
		clearmouseclick(WM_LBUTTONUP);
	}	
	return 0;
}

void cir(int x,int y)
{
	circle(x,y,150);
}
void Buttons()
{
	setlinestyle(1,0,2);
	settextstyle(8,HORIZ_DIR,4);
	for(int x=150; x<900; x+=70) line(x,10,x,80);
	line(150,10,850,10);
	line(150,80,850,80);
	outtextxy(175,25,"A");
	outtextxy(245,25,"B");
	settextstyle(8,HORIZ_DIR,2);
	outtextxy(295,30,"Erase");
	circle(535,45,25);
	rectangle(580,20,630,70);
	rectangle(650,30,700,60);
	setfillstyle(3,3);
	bar(370,20,420,70);
	bar(440,30,490,60);
	setfillstyle(1,14);
	setcolor(0);
	fillellipse(815,45,25,25);
	setcolor(14);
	settextstyle(8,HORIZ_DIR,2);
	outtextxy(715,30,"Color");
}
void Erase()
{
	setfillstyle(1,0);
	bar(0,81,1000,1000);
}
void Move(int &x,int &y,int t,int &c)
{
	settextstyle(8,HORIZ_DIR,12);
	do
	{
		delay(0.1);
	
		if(ismouseclick(WM_MOUSEMOVE))
		{
			getmouseclick(WM_MOUSEMOVE,x,y);
			Erase();
		
			if(t==1) outtextxy(x,y,"A");
			if(t==2) outtextxy(x,y,"B");
			if(t==4) 
			{
				setfillstyle(3,c); 
				bar(x+100,y-100,x-100,y+100);
			} 
			if(t==5) 
			{	
				setfillstyle(3,c); 
				bar(x+100,y-50,x-100,y+50);
			} 
			if(t==6) 
			{ 
				
				cir(x,y);
			} 
			if(t==7) 
			{ 
			
				rectangle(x-100,y+100,x+100,y-100);
			} 
			if(t==8)
			{
			
				rectangle(x-100,y+50,x+100,y-50);
			}
			if(t==10)
			
			{
				setfillstyle(1,c);
				fillellipse(x,y,100,100);
			}
		}
	}while(!ismouseclick(WM_LBUTTONUP));
	clearmouseclick(WM_LBUTTONUP);
}
