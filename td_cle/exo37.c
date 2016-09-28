#include "graphics.h"
#include <stdio.h>

POINT centre;
POINT centre_precedant;

void efface_affiche()
{
	draw_fill_circle(centre_precedant,30,noir);
	draw_fill_circle(centre,30,bleu);
}

void plus_ou_moins(POINT p)
{
	centre_precedant=centre;
	if(p.y<centre.y) centre.y=centre.y-2;
	if(p.y>centre.y) centre.y=centre.y+2;
}


int main()
{
	init_graphics(400,400);
	
	POINT p;
	int i;
	centre_precedant.x=0;
	centre_precedant.y=0;
	
	centre.x=200;
	centre.y=200;
	
	for(i=0;i<20;i++)
	{
		p=wait_clic();
		efface_affiche();
		plus_ou_moins(p);
	}
	
	wait_escape();
	return 0;
}

