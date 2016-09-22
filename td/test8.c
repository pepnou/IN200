#include "graphics.h"
#include <stdio.h>
#include <math.h>

int main()
{
	init_graphics(900,600);
	
	POINT p;
	p.x=450;
	
	int a=0;
	int b=0;
	
	while(1)
	{
		b=b+1;
		a=cos(b);
//		p=get_mouse();
		
		p.y=300+(a*100);
		
		draw_pixel(p,rouge);
		
	}
	
	
	return 0;
}

