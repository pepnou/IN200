#include "graphics.h"
#include <stdio.h>

int v[20];
int temp;
int place;


void min_v()
{
	temp=v[0];
	int i;
	for(i=0;i<20;i++)
	{
		if(temp>v[i])
		{
			temp=v[i];
			place=i;
		}
	}
	v[place]=v[0];
	v[0]=temp;
}



int main()
{
	init_graphics(800,500);
	
	int i;
	POINT p1;
	POINT p2;	
	
		fill_screen(noir);
		for (i=0;i<20;i++) v[i]=alea_int(100);
	
	for (i=0;i<20;i++)
		{
			p1.x=100+(20*i);p1.y=50;
			p2.x=100+(20*i)+19;p2.y=50+(3*v[i]);
			draw_rectangle(p1,p2,bleu);
		}
	wait_clic();
	fill_screen(noir);	
	min_v();
	for (i=0;i<20;i++)
		{
			p1.x=100+(20*i);p1.y=50;
			p2.x=100+(20*i)+19;p2.y=50+(3*v[i]);
			draw_rectangle(p1,p2,bleu);
		}
		
	p1.x=100;p1.y=50;
	p2.x=100+19;p2.y=50+(3*v[0]);
	draw_rectangle(p1,p2,rouge);
	
	
	wait_escape();
	return 0;
}

