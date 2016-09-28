#include "graphics.h"
#include <stdio.h>

POINT tab[20];
int tab2[20];


int main()
{
	init_graphics(500,500);
	
	int temp;
	POINT p;
	
	
	POINT tab[20];
	int tab2[20];
	int i;
	
	for(i=0;i<20;i++)
	{
		tab[i]=wait_clic();
		tab2[i]=20;
		draw_fill_circle(tab[i],tab2[i],rouge);
	}
	
	int d=1;
	while(d>0)
	{
		
		p=wait_clic();
		for(i=0;i<20;i++)
		{
			if(distance(p,tab[i])<tab2[i])
			{
				tab2[i]=tab2[i]+10;
			}
		}
			for(i=0;i<20;i++)
			{
				tab2[i]=tab2[i]-5;
			}
			fill_screen(noir);
		
		for(i=0;i<20;i++)
		{
			draw_fill_circle(tab[i],tab2[i],rouge);
		}
		
		d=0;
		for(i=0;i<20;i++)
		{
			if ((tab2[i])>0) d=d+1;
		}
		
		
	}
	
	
	wait_escape();
	return 0;
}

