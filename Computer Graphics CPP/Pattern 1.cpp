#include<graphics.h>
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	int x=200,y=200,i;
	setcolor(GREEN);
	line(x,y,x+200,y);
	line(x,y,x,y+200);
	line(x,y+200,x+200,y+200);
	line(x+200,y+200,x+200,y);
	
	line(x+75,y+125,x+75,y+160);
	line(x+200-75,y+125,x+200-75,y+160);
	line(x+75,y+125,x+200-75,y+125);
	line(x+75,y+160,x+200-75,y+160);
	
	setcolor(YELLOW);
	line(x+200-80,y+150,x+200-25,y+150);
	line(x+200-80,y+140,x+200-25,y+140);
	line(x+200-25,y+150,x+200-25,y+140);
	line(x+200-80,y+150,x+200-80,y+140);

	for(i=0;i<500;i+10)
	{
		putpixel(x+200-25,y+140-i,WHITE);
		delay(100);
	}

	setcolor(YELLOW);
	circle(x+50,y+60,25);
	floodfill(x+50,y+60,YELLOW);
	circle(x+200-50,y+60,25);
	floodfill(x+200-50,y+60,YELLOW);

	line(x,y,x+50,y+60);
	line(x+200,y,x+200-50,y+60);

	line(x,y,x+50,y+70);
	line(x+200,y,x+200-50,y+70);

	line(x+50,y+60,x+200-50,y+60);
	line(x+50,y+65,x+200-50,y+65);
	
	setcolor(GREEN);
	line(x,y,x+40,y-40);
	line(x+80,y,x+40,y-40);

	setcolor(GREEN);
	line(x+200,y,x+200-40,y-40);
	line(x+200-80,y,x+200-40,y-40);

	setcolor(GREEN);
	arc(x,y+75,90,270,20);
	arc(x+200,y+75,270,90,20);
	
	getch();
	closegraph();
}
