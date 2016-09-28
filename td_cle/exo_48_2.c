#include "graphics.h"
#include <stdio.h>

int main()
{
	init_graphics(800,800);
	POINT p[10];
	int c[10];
	POINT clic;
	int i;
	int j;
	for (i=0;i<10;i++)
	{
		p[i] = wait_clic();
		draw_fill_circle(p[i],50,rouge);
		c[i]=1;
	}
	
	while((c[0]==1)||(c[1]==1)||(c[2]==1)||(c[3]==1)||(c[4]==1)||(c[5]==1)||(c[6]==1)||(c[7]==1)||(c[8]==1)||(c[9]==1))
	{
		clic=wait_clic();
		for(i=0;i<10;i++)
		{
			if (distance(p[i],clic)<50)
			{
				draw_fill_circle (p[i],50,noir);
				c[i]=0;
			}
		}
	}
		
	wait_escape();
	return 0;
}

