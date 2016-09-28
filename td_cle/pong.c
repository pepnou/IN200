#include "graphics.h"
#include <stdio.h>

int X=900,Y=600;
int nombre_objet=5;
OBJET tab[nombre_objet];

typedef struct objet OBJET;

struct objet
{
	int px;
	int py;
	int vx;
	int vy;
	int tx;
	int ty;
	int pxi;
	int pyi;
};

int rebond_mur(OBJET a)
{
	if((a.py<a.ty)||(a.py>(Y-a.ty)))
	{
		a.vy=-a.vy;
	}
}
		
int rebond_raquette(OBJET a,OBJET b)
{
	if((a.px<a.tx+b.tx)&&(a.py-b.py<a.ty+b.ty)&&(a.py-b.py<-(a.ty+b.ty)))
	{
		a.vx=-a.vx;
	}
	if((a.px>(X-(a.tx+b.tx)))&&(a.py-b.py<a.ty+b.ty)&&(a.py-b.py<-(a.ty+b.ty)))
	{
		a.vx=-a.vx;
	}
}

void init_plateau(OBJET[])
{
	
}

void init_facile(OBJET a,int px,int py,int vx,int vy,int tx,int ty)
{
	a.px=px;
	a.py=py;
	a.vx=vx;
	a.vy=vy;
	a.tx=tx;
	a.ty=ty;
	a.pxi=a.px;
	a.pyi=a.py;
}


void initialisation_objet(OBJET[])
{
	init_facile(tab[0],5,Y/2,0,0,5,10);
	init_facile(tab[1],X-5,Y/2,0,0,5,10);
	init_facile(tab[2],X/2,Y/2,0,0,5,5);
//	init_facile(tab[3],);
//	init_facile(tab[4],);
}

int main()
{

	
	
	init_graphics(X,Y);
	
//	tab[0] OBJET 1 r1;
//	tab[1] OBJET 2 r2;
//	tab[2] OBJET 3 b;
//	tab[3] OBJET 4 m1;
//	tab[4] OBJET 5 m2;
	
	OBJET tab[nombre_objet];
	
	
	int score1=0;
	int score2=0;
	int scoremax=10;
	
	
	
	
	initialisation_objet(tab[]);
	
	while((score1<scoremax)&&(score2<scoremax))
	{
		init_plateau;
		
		while(1)
		{
			rebond_mur(tab[2]);
			rebond_raquette(tab[2],tab[0]);
			rebond_raquette(tab[2],tab[1]);
		}
	}
	return 0;
}

