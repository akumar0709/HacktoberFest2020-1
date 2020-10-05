#include<iostream>
#include<math.h>
#include<graphics.h>
using namespace std;


void circ(int xc,int yc, int r )
{
int x,y;
float d;
x=0;y=r;
 d=3-2*r;
        do
        {
        putpixel(x+xc,y+yc,5);
        putpixel(y+xc,x+yc,5);
        putpixel(x+xc,-y+yc,5);
        putpixel(-y+xc,x+yc,5);
        putpixel(-x+xc,-y+yc,5);
        putpixel(-y+xc,-x+yc,5);
        putpixel(-x+xc,y+yc,5);
        putpixel(y+xc,-x+yc,5);
        x=x+1;
        if(d<0)
        	d=d+4*x+6;
        else
        {
        	d=d+4*(x-y)+10;
        	y=y-1;
        }delay(10);

     
        }while(x<=y);
}






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
				delay(10);
			}
		
		}



int main()
{
int xc,yc,r,R;
int gd=DETECT,gm;

cout<<"Enter Center of the Circles\n";
cin>>xc>>yc;
cout<<"\nEnter Radius Of Circle \n";
cin>>R;

initgraph(&gd,&gm,NULL);

circ(xc,yc,R);
circ(xc,yc,R/2);


float x=sqrt(3)*R/2;

drawline(xc-x,yc+R/2,xc+x,yc+R/2);

drawline(xc-x,yc+R/2,xc,yc-R);

drawline(xc,yc-R,xc+x,yc+R/2);

delay(6000);
closegraph();
return 0;
}
