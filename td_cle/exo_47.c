#include "graphics.h"
#include <stdio.h>

int main()
{
	init_graphics(800,800);
	POINT p[10];
	int i;
	int j;
	for (i=0;i<10;i++)
	{
		p[i] = wait_clic();
		draw_fill_circle(p[i],50,rouge);
	}

	for (i=0;i<10;i++)
	{
		wait_clic();
		draw_fill_circle(p[9-i],50,noir);

		for (j=0;j<9-i;j++)
		{
			draw_fill_circle(p[j],50,rouge);
		}
		
	}
	
	wait_escape();
	return 0;
}

