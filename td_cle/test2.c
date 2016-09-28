#include <stdio.h>
#include "graphics.h"
#include <math.h>


int main()
{
init_graphics(900,600);

draw_quadrillage(100,100,rouge);
POINT p;
p=wait_clic();
draw_hexagone(p,50,bleu);

wait_escape();
	return 0;
}

