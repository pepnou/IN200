#include "graphics.h"
#include <stdio.h>
#include <time.h>

int main()
{
	init_graphics(1920,1080);
	
	POINT p;
	int r;
	int v;
	int b;
	
	while (1)
	{
		p.x=alea_int(1920);
		p.y=alea_int(1080);
		r=alea_int(255);
		v=alea_int(255);
		b=alea_int(255);

		draw_hexagone(p,50,couleur_RGB(r,v,b));

	
	}
	
	
	return 0;
}

