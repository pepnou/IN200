#include "graphics.h"
#include <stdio.h>

int main()
{
	init_graphics(512,512);
	
	POINT p;
	int i=0;
	int j=0;
	int r;
	int b;
	
	for (i=0;i<513;i++)
	{
		for (j=0;j<513;j++)
		{
			p.x=i;p.y=512-j;
			r=j/2;
			b=i/2;
			draw_pixel(p,couleur_RGB(r,0,b));
		}
	}
	
	
	
	
	wait_escape();
	return 0;
}

