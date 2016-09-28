#include "graphics.h"
#include <stdio.h>

void ech1()
{
	int a=0;
	POINT p1;
	POINT p2;
	int i=0;
	int j=0;
	int b=0;
	while((i<450)&&(j<450))
	{
		p1.x=i;p1.y=j;
		p2.x=i+50;p2.y=j+50;
		if (b==0)
		{
			draw_fill_rectangle(p1,p2,blanc);
		}
		else
		{
			draw_fill_rectangle(p1,p2,noir);
		}
		i=i+50;
		if(i==400)
		{
			j=j+50;
			i=0;
			a++;
		}
		a++;
		b=a%2;
	}
}

int main()
{
	init_graphics(400,400);
	ech1();
	int i=0;
	int j=0;
	POINT p;
	POINT pion;
	pion.x=25;pion.y=25;
	draw_fill_circle(pion,24,rouge);
	
	p=wait_clic();
	while(((pion.y-p.y)<25)&&((pion.y-p.y)>(-25))||((pion.x-p.x)<25)&&((pion.x-p.x)>(-25)))
	{
		ech1();
		if((p.x/25)%2==0)
		{
			pion.x=(p.x+(25-(p.x%25)));
		}
		else
		{
			pion.x=(p.x-(p.x%25));
		}
		if((p.y/25)%2==0)
		{
			pion.y=(p.y+(25-(p.y%25)));
		}
		else
		{
			pion.y=(p.y-(p.y%25));
		}
		draw_fill_circle(pion,24,rouge);
		p=wait_clic();
	}
	



	wait_escape();
}

