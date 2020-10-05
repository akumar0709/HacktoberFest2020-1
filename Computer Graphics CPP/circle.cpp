#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
	
int main()
{
	int gd=DETECT,gm;
	int x,y,rad,d,xc,yc;
	cout<<"\nEnter the centre of the circle:";
	cin>>xc>>yc;
	cout<<"\nEnter the radius of the circle:";
	cin>>rad;
	x=0;
	y=rad;
	d=3-2*rad;
	
	initgraph(&gd,&gm,NULL);
	
	do
	{
		putpixel(x+xc,y+yc,3);
		putpixel(y+xc,x+yc,3);
		putpixel(y+xc,-x+yc,3);
		putpixel(x+xc,-y+yc,3);
		putpixel(-x+xc,-y+yc,3);
		putpixel(-y+xc,-x+yc,3);
		putpixel(-y+xc,x+yc,3);
		putpixel(-x+xc,y+yc,3);
		delay(50);
		x++;
		if(d<0)
			d=d+4*x+6;
		else
			{
				d=d+4*(x-y)+10;
				y--;
			}
	}while(x<=y);


getch();
closegraph();
return 0;	
	
}
