#include "graphics.h"
#include <stdio.h>

#define X 900
#define Y 600

int rebond=0;

struct balle
{
	COULEUR coul;
	int px;
	int py;
	int dx;
	int dy;
	int rayon;
	
};

typedef struct balle BALLE;

void affiche_ecran(BALLE a);
BALLE deplace_balle(BALLE a);
BALLE rebond_balle(BALLE a);

int main()
{
	affiche_auto_off();
	init_graphics(X,Y);
	
	BALLE balle_1;
	balle_1.coul=blanc;
	balle_1.dx=10;
	balle_1.dy=3;
	balle_1.px=100;
	balle_1.py=200;
	balle_1.rayon=20;
	
	
	
	while(rebond<31)
	{
		fill_screen(noir);
		balle_1 = rebond_balle(balle_1);
		balle_1 = deplace_balle(balle_1);
		affiche_ecran(balle_1);
		
		affiche_all();
		attendre(20);
	}
	
	wait_escape();
	return 0;
}

void affiche_ecran(BALLE a)
{
	POINT p;
	POINT p1;
	p.x=a.px;
	p.y=a.py;
	draw_fill_circle(p,a.rayon,a.coul);
	
	p.x=1+rebond;
	p.y=0;
	p1.x=p.x;
	p1.y=Y;
	draw_line(p,p1,blanc);
	
	p.x=150+rebond;
	p.y=0;
	p1.x=p.x;
	p1.y=Y;
	draw_line(p,p1,blanc);
	
}

/*
void efface_balle(BALLE a)
{
	POINT p;
	p.x=a.px;
	p.y=a.py;
	draw_circle(p,a.rayon,noir);
} 
*/

BALLE deplace_balle(BALLE a)
{
	a.px=a.px+a.dx;
	a.py=a.py+a.dy;
	
	return a;
}

BALLE rebond_balle(BALLE a)
{
	if((a.py>Y-a.rayon)||(a.py<a.rayon)) 
	{
		a.dy=-a.dy;
		rebond = rebond +1;
	}
	if((a.px>150+rebond-a.rayon)||(a.px<rebond+a.rayon))
	{
		a.dx=-a.dx;
		rebond = rebond +1;
		a.px=a.px+a.dx;
	} 
	
	return a;
}
