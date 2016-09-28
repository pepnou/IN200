#include "graphics.h"
#include <stdio.h>





int main()
{
	init_graphics(500,500);
	
	POINT centre;
	centre.x=250;
	centre.y=250;
	int temp;
	
	
	
	POINT tab[20];
	int tab2[20];
	int loin[20];
	int place[20];
	int i;
	
	for(i=0;i<20;i++)
	{
		tab[i]=wait_clic();
		tab2[i]=alea_int(50);
		draw_fill_circle(tab[i],tab2[i],rouge);
	}
	
	for(i=0;i<20;i++)
	{
		loin[i]=distance(centre,tab[i]);
		place[i]=i;
	}
	
	for(i=0;i<19;i++)
	{
		if(loin[i]<loin[i+1])
		{
			temp=loin[i];
			loin[i]=loin[i+1];
			loin[i+1]=temp;
			
			temp=place[i];
			place[i]=place[i+1];
			place[i+1]=temp;
			
			i=0;
		}
	}
	
		for(i=0;i<20;i++)
	{
		wait_clic();
		draw_fill_circle(tab[place[i]],tab2[place[i]],noir);
	}
	
	
	
	
	
	wait_escape();
	return 0;
}

