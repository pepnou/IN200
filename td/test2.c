#include <stdio.h>
#include "graphics.h"
#include <math.h>


int main()
{
init_graphics(900,600);

POINT p;

while (1)
{
p=wait_clic();

draw_fill_hexagone(p,50,blanc);
}


wait_escape();
	return 0;
}

