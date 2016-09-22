#include "graphics.h"
#include <stdio.h>
#include <math.h>



int main()
{
	init_graphics(900,600);
	
	POINT p;
	p=wait_clic();
	
	draw_polygone(5,100,p,jaune);
	
	
	
	
	
	wait_escape();
	return 0;
}























