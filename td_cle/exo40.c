#include "graphics.h"
#include <stdio.h>

int main()
{
	init_graphics(600,600);
	POINT p;
	POINT p1;
	POINT p2;
	int a;
	p1.x=300;p1.y=0;
	p2.x=300;p2.y=600;
	draw_line(p1,p2,blanc);
	POINT r;
	r.x=0;r.y=0;
	
	for(a=0;a<20;a++)
	{
		p=wait_clic();
		if(p.x<300) draw_circle(p,50,rouge);
		
		if((p.x>300)&&(r.x>300)) draw_circle(p,50,bleu);
		r.x=p.x;
	}
	
	return 0;
}

