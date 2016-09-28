#include "graphics.h"
#include <stdio.h>

COULEUR draw_quad(POINT p1,POINT p2,POINT p3,POINT p4,COULEUR color)
{
	int i;
	POINT tab[5];
	tab[1]=p1;
	tab[2]=p2;
	tab[3]=p3;
	tab[4]=p4;
	while((tab[1].y<tab[2].y)||(tab[2].y<tab[3].y)||(tab[3].y<tab[4].y))
	{
		for(i=1;i<4;i++)
		{
			if(tab[i].y<tab[i+1].y)
			{
				tab[5]=tab[i];
				tab[i]=tab[i+1];
				tab[i+1]=tab[5];
			}
		}
	}
	draw_line(tab[1],tab[2],color);
	draw_line(tab[3],tab[4],color);
				
	if(tab[1].x<tab[2].x)
	{
		if(tab[3].x<tab[4].x)
		{
			draw_line(tab[1],tab[3],color);
			draw_line(tab[2],tab[4],color);
		}
		else
		{
			draw_line(tab[1],tab[4],color);
			draw_line(tab[2],tab[3],color);
		}
	}
	else
	{
		if(tab[3].x<tab[4].x)
		{
			draw_line(tab[1],tab[4],color);
			draw_line(tab[2],tab[3],color);
		}
		else
		{
			draw_line(tab[1],tab[3],color);
			draw_line(tab[2],tab[4],color);
		}
	}
	
	
	
	
	
	
	
}

int main()
{
	init_graphics(900,600);

POINT p1,p2,p3,p4;
p1=wait_clic();
p2=wait_clic();
p3=wait_clic();
p4=wait_clic();


draw_quad(p1,p2,p3,p4,rouge);
	wait_escape();
	return 0;
}

