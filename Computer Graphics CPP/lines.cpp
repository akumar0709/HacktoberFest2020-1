#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
int gd=DETECT,gm;
class lines
{
	float x1,y1,x2,y2,dx,dy,len,x,y;
	
	public: void accept()
			{
				cout<<"\nEnter initial point:";
				cin>>x1>>y1;
				cout<<"\nEnter final point:";
				cin>>x2>>y2;
			}
	
			void dotted()
			{
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
		
				for(int i=0;i<=len;i++)
				{	
					
					if(i%2==0)
					{
						putpixel(x,y,3);
						delay(50);
					}
					x=x+dx;
					y=y+dy;
				}
						
			}	
			
			void solid()
			{
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

				
		
				for(int i=0;i<=len;i++)
				{	
					putpixel(x,y,3);
					delay(50);
					x=x+dx;
					y=y+dy;	
				}
			}
			
			void dashed()
			{	
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

				
		
				for(int i=1;i<=len+1;i++)
				{	
					if(i%5!=0)
					{
						putpixel(x,y,3);
						delay(50);
					}
					x=x+dx;
					y=y+dy;
				}
			}
			
			void dotted_dashed()
			{	
				int flag=0,i=0;
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

				while(i<len)
				{
					if(flag<6||flag==8)
					{
						putpixel(x,y,3);
						delay(50);
						flag++;
					}	
					if(flag==11)
					{
						flag=0;
					}
					else
					{
						flag++;
					}
					x=x+dx;
					y=y+dy;	
					i++;
				}
			}
			
		void drawline(float X1,float Y1,float X2,float Y2)
		{
			x1=X1;
			y1=Y1;
			x2=X2;
			y2=Y2;
			
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
		
		}
			void thick()
			{
				float Wx,Wy,W;
				float slope;
				cout<<"\nEnter the width:";
				cin>>W;
				
				dx=(x2-x1);
				dy=(y2-y1);
	
				if(abs(dx)>=abs(dy))
					len=abs(dx);
				else 
					len=abs(dy);

				slope=dy/dx;
				
				if(slope<1)
				{
					Wy=(W-1)*(sqrt(pow((x2-x1),2)+pow((y2-y1),2)));
					Wy=Wy/2;
					Wy=Wy/abs(x2-x1);
					cout<<"WY="<<Wy;
				//	initgraph(&gd,&gm,NULL);
					for(int i=-Wy;i<=0;i++)
					{
						drawline(x1,y1+i,x2,y2+i);
						drawline(x1,y1-i,x2,y2-i);
					}			
				}
				
				else if(slope>1)
				{
					Wx=(W-1)*(sqrt(pow((x2-x1),2)+pow((y2-y1),2)));
					Wx=Wx/2;
					Wx=Wx/abs(y2-y1);	
					
					for(int i=-Wx;i<=0;i++)
					{
						drawline(x1+i,y1,x2+i,y2);
						drawline(x1-i,y1,x2-i,y2);
					}
				}	
			}	
				
};

int main()
{

int choice;
lines L;
cout<<"\n*******************************DIFFERENT LINES********************************";
cout<<"\n\t1.SOLID LINE";
cout<<"\n\t2.DOTTED LINE";
cout<<"\n\t3.DASHED LINE";
cout<<"\n\t4.DOTTED DASHED LINE";
cout<<"\n\t5.THICK LINE";

cout<<"\nEnter your choice:";
cin>>choice;

switch(choice)
{
	case 1: L.accept();
			L.solid();
			break;
	
	case 2: L.accept();
			L.dotted();
			break;
			
	case 3: L.accept();
			L.dashed();
			break;
			
	case 4: L.accept();
			L.dotted_dashed();
			break;
			
	case 5: L.accept();
			L.thick();
			break;
	
	default:cout<<"\nEnter valid choice";
}	
		getch();
		closegraph();
		return 0;
}




