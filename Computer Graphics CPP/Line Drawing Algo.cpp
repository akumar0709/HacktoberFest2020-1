#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class pixel
{
	public:
		void drawline(float x1,float x2,float x2,float y2)
		{
			float x,y,dx,dy,len;
			int gd=DETECT,gm;
			initgraph(&gd,&gm,NULL);
	
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

			putpixel(x,y,3);
	
			for(int i=0;i<len;i++)
			{
				x=x+dx;
				y=y+dy;
				putpixel(x,y,3);
				delay(50);
			}
		getch();
		closegraph();
		}

		void drawline(int x1,int x2,int y1,int y2)
		{
			int Pk,dx,dy,x,y,len;
			float slope;
			int gd=DETECT,gm;
			initgraph(&gd,&gm,NULL);
	
			dx=(x2-x1);
			dy=(y2-y1);
	
			if(abs(dx)>=abs(dy))
				len=abs(dx);
			else len=abs(dy);

			slope=dy/dx;
	
			x=x1;
			y=y1;
	
	
			if(slope<1)
			{
				Pk=2*dy-dx;
				putpixel(x,y,3);
				delay(50);
				for(int k=0;k<len;k++);
				{	
					if(Pk>=0)
					{
						putpixel(++x,++y,3);
						delay(50);
						Pk=Pk+2*dy-2*dx;
					}
					else
					{
						putpixel(++x,y,3);
						delay(50);
						Pk=Pk+2*dy;
					}
				
				}
			
			}

			else if(slope>1)
			{
				Pk=2*dx-dy;
				putpixel(x,y,3);
				delay(50);
				for(int k=0;k<len;k++);
				{	
					if(Pk>=0)
					{
						putpixel(++x,++y,3);
						delay(50);
						Pk=Pk+2*dx-2*dy;
					}
					else
					{
						putpixel(x,++y,3);
						delay(50);
						Pk=Pk+2*dx;
					}
				
				}
			}
	
			else
			{
				for(int k=0;k<len;k++)
				{
					putpixel(++x,++y,3);
					delay(50);
				}
			}
			getch();
			closegraph();
		}
};

int main()
{
	pixel P;
	int choice;
	cout<<"\nINT/FLOAT(1/2):";
	cin>>choice;
	switch(choice)
	{
	case 1:
		float x1,y1,x2,y2;
	
		cout<<"\nEnter the initial point:";
		cin>>x1>>y1;
	
		cout<<"\nEnter the final point:";
		cin>>x2>>y2;
		P.drawline(x1,x2,y1,y2);
		break;
	case 2:
		int X1,Y1,X2,Y2;
	
		cout<<"\nEnter the initial point:";
		cin>>X1>>Y1;
	
		cout<<"\nEnter the final point:";
		cin>>X2>>Y2;
		P.drawline(X1,X2,Y1,Y2);
		break;

	default: cout<<"\nWrong choice!";

	}
	
	
	
return 0;
}
