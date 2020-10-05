#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
		
		void drawline(float x1,float y1,float x2,float y2)
		{
			float x,y,dx,dy,len;
			
	
			dx=abs(x2-x1);
			dy=abs(y2-y1);
	
			if(dx>=dy)
				len=dx;
			else len=dy;

			dx=(x2-x1)/len;
			dy=(y2-y1)/len;
	
			if(dx>0)
				x=x1+0.5;
			else x=x1-0.5;

			if(dy>0)
				y=y1+0.5;
			else	y=y1-0.5;

		
	
			for(int i=0;i<len;i++)
			{
				putpixel(x,y,3);
				x=x+dx;
				y=y+dy;
			}
		
		}
		
int main()
{
	float x,y,l,b;
	int gd=DETECT,gm;
		
	cout<<"\nEnter top left coordinates:";
	cin>>x>>y;
	cout<<"\nEnter length and breadth:";
	cin>>l>>b;
		
	initgraph(&gd,&gm,NULL);
	
	drawline(x,y,x,y+b);
	drawline(x,y,x+l,y);
	drawline(x+l,y,x+l,y+b);
	drawline(x,y+b,x+l,y+b);
	
	drawline(x,y+b/2,x+l/2,y);
	drawline(x+l/2,y,x+l,y+b/2);
	drawline(x+l,y+b/2,x+l/2,y+b);
	drawline(x,y+b/2,x+l/2,y+b);
	
	int x1,y1,x2,y2;
	x1=(x+x+l/2)/2;
	y1=(y+b/2+y)/2;
	x2=(x+l/2+x+l)/2;
	y2=(y+y+b/2)/2;
	drawline(x1,y1,x2,y2);
	
	x2=(x+x+l/2)/2;
	y2=(y+b/2+y+b)/2;
	drawline(x1,y1,x2,y2);
	
	x1=(x+l/2+x+l)/2;
	y1=(y+b/2+y+b)/2;
	drawline(x1,y1,x2,y2);
	
	x2=(x+l/2+x+l)/2;
	y2=(y+y+b/2)/2;
	drawline(x1,y1,x2,y2);

	getch();
	closegraph();
	return 0;
	
	
	

}
