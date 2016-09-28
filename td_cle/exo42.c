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
	while((i<400)||(j<400))
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

void ech2()
{
	int a=0;
	POINT p1;
	POINT p2;
	int i=0;
	int j=0;
	int b=0;
	for(j=0;j<400;j=j+50)
	{
		for(i=0;i<400;i=i+50)
		{
			b=a%2;
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
			a++;
			b=a%2;
		}
		i=0;
		a++;
	}
}








int main()
{
	init_graphics(400,400);
	ech2();

	wait_escape();
}

