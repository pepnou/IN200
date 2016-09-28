#include "graphics.h"
#include <stdio.h>

int main()
{
	init_graphics(800,800);
	POINT p[10];
	int i;
	for (i=0;i<10;i++)
	{
		p[i] = wait_clic();
		draw_fill_circle(p[i],50,rouge);
	}
	wait_clic();
	for (i=0;i<10;i++)
	{
		draw_fill_circle(p[i],50,bleu);
	}
	
	wait_escape();
	return 0;
}

