#include "graphics.h"
#include <stdio.h>

int X=900;
int Y=600;


void bandeau()
{
	POINT p1;
	POINT p2;
	int i;
	int coef=5;
	
	for(i=0;i<25;i++)
	{
		p1.x=i;
		p1.y=Y-100+i;
		p2.x=X-i;
		p2.y=Y-i;
		draw_rectangle(p1,p2,couleur_RGB(200-coef*i,0,0));
		
	}
}

void lama(int tab[])
{
	tab[1]=1;
}


int main()
{	
	init_graphics(X,Y);
	
	POINT p;
	p=wait_clic();
	int v=1;
	aff_int(2,50,p,blanc);
	p=wait_clic();
	aff_int(v,50,p,blanc);
	
	wait_escape();
	return 0;
}

