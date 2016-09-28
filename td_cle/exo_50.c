#include "graphics.h"
#include <stdio.h>

int main()
{
	init_graphics(800,500);
	int v[22];
	int i;	
	POINT p1;
	POINT p2;	
	int a=0;
	int b=0;
	
	
	for (i=0;i<20;i++) 
	{
		v[i]=alea_int(100);
	}
	v[20]=v[0];
	v[21]=v[0];
	

	for (i=0;i<20;i++) v[i]=alea_int(100);
	
		for (i=0;i<20;i++)
		{
			p1.x=100+(20*i);p1.y=50;
			p2.x=100+(20*i)+19;p2.y=50+(3*v[i]);
			draw_rectangle(p1,p2,bleu);
		}
	
	
	
	
	
	
	
	
	
	
	
	for (i=0;i<20;i++) 
	{
		if(v[20]<v[i])
		{
			v[20]=v[i];
			a=i;
		}
	}
//	write_int(v[20]);
//	write_text("  ");
	
	for (i=0;i<20;i++) 
	{
		if(v[21]>v[i])
		{
			v[21]=v[i];
			b=i;
		}
	}
//	write_int(v[21]);
	
	p1.x=100+(20*a);p1.y=50;
	p2.x=100+(20*a)+19;p2.y=50+(3*v[20]);
	draw_rectangle(p1,p2,vert);
	
	p1.x=100+(20*b);p1.y=50;
	p2.x=100+(20*b)+19;p2.y=50+(3*v[21]);
	draw_rectangle(p1,p2,rouge);
	
	
	wait_escape();
	return 0;
}

