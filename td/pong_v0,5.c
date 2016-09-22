#include "graphics.h"
#include <stdio.h>

int X=900,Y=600;
int nombre_objet=5;
//OBJET tab[nombre_objet];
int score=0;
int score_vie=0;
int vie=3;
float vitesse=7;

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

typedef struct objet OBJET;

OBJET rebond_mur(OBJET a)
{
	if((a.px<a.tx)||(a.px>(X-a.tx)))
	{
		a.vx=-a.vx;
	}
	if(a.py>(Y-100-a.ty))
	{
		a.vy=-a.vy;
	}
	
	return a;
}
		
OBJET rebond_raquette(OBJET a,OBJET b)
{
	float c;
	float d;
	
	if((a.py<a.ty+b.ty)&&(a.px-b.px<a.tx+b.tx)&&(a.px-b.px>-(a.tx+b.tx)))
	{
		a.vy=-a.vy;
		
		efface_score();
		score=score+1;
		score_vie=score_vie+1;
		affiche_score();
		printf("score = %d \n",score);
		
		if(score_vie%10==0)
		{
			efface_score();
			vie=vie+1;
			printf("nombre de vie = %d \n",vie);
			affiche_score();
		}
		if(score%20==0)
		{
			vitesse=vitesse-(vitesse/10);
		}
	}
	
	
	return a;
}

void dessine_objet(OBJET a)
{
	POINT p1;
	p1.x=a.px-a.tx;
	p1.y=a.py-a.ty;
	
	POINT p2;
	p2.x=a.px+a.tx;
	p2.y=a.py+a.ty;
	
	draw_fill_rectangle(p1,p2,blanc);
}

void efface_objet(OBJET a)
{
	POINT p1;
	p1.x=a.px-a.tx;
	p1.y=a.py-a.ty;
	
	POINT p2;
	p2.x=a.px+a.tx;
	p2.y=a.py+a.ty;
	
	draw_fill_rectangle(p1,p2,noir);
}

OBJET deplace_balle(OBJET a)
{
	a.px=a.px+a.vx;
	a.py=a.py+a.vy;
	
	return a;
}

OBJET deplace_raquette(OBJET a)
{
	POINT p;
	p=get_arrow();
	
	a.px=a.px+5*p.x;
	
	return a;
}



OBJET init_facile(OBJET a,int px,int py,int vx,int vy,int tx,int ty)
{
	a.px=px;
	a.py=py;
	a.vx=vx;
	a.vy=vy;
	a.tx=tx;
	a.ty=ty;
	a.pxi=a.px;
	a.pyi=a.py;
	
	return a;
}

int defaite(OBJET a)
{
	if(a.py<-a.ty)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

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

void affiche_score()
{
	POINT p;
	
	p.x=25;p.y=Y-18;
	aff_pol("score:",50,p,blanc);
	p.x=180;p.y=Y-18;
	aff_int(score,50,p,blanc);
	
	
	p.x=330;p.y=Y-18;
	aff_pol("rebond:",50,p,blanc);
	p.x=530;p.y=Y-18;
	aff_int(score_vie,50,p,blanc);
	
	
	p.x=680;p.y=Y-18;
	aff_pol("vie:",50,p,blanc);
	p.x=780;p.y=Y-18;
	aff_int(vie,50,p,blanc);
	
	
}

void efface_score()
{
	POINT p;
	
	p.x=25;p.y=Y-18;
	aff_pol("score:",50,p,noir);
	p.x=180;p.y=Y-18;
	aff_int(score,50,p,noir);
	
	
	p.x=330;p.y=Y-18;
	aff_pol("rebond:",50,p,noir);
	p.x=530;p.y=Y-18;
	aff_int(score_vie,50,p,noir);
	
	
	p.x=680;p.y=Y-18;
	aff_pol("vie:",50,p,noir);
	p.x=780;p.y=Y-18;
	aff_int(vie,50,p,noir);
	
	
}

clignotter()
{
	int i;
	POINT p;
	
	for(i=0;i<5;i++)
	{
		p.x=680;p.y=Y-18;
		aff_pol("vie:",50,p,rouge);
		p.x=780;p.y=Y-18;
		aff_int(vie,50,p,rouge);
		affiche_all();
		
		attendre(500);
		
		p.x=680;p.y=Y-18;
		aff_pol("vie:",50,p,blanc);
		p.x=780;p.y=Y-18;
		aff_int(vie,50,p,blanc);
		affiche_all();
		
		attendre(500);
	}
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
	
	affiche_auto_off();
	
	tab[0]=init_facile(tab[0],X/2,5,0,0,50,5);
	tab[2]=init_facile(tab[2],X/2,Y/2,alea_int(4)+2,alea_int(4)+2,5,5);
	
	affiche_score();
	bandeau();
	affiche_all();
	sleep(5);
	
	
	int b=0;
	POINT go;
	go.x=100;go.y=400;
	
	while(vie>0)
	{
		
		
		while(b==0)
		{
			bandeau();
			
			
			
			
			tab[2]=rebond_mur(tab[2]);
			tab[2]=rebond_raquette(tab[2],tab[0]);
			
			efface_objet(tab[0]);
			efface_objet(tab[2]);
			
			tab[2]=deplace_balle(tab[2]);
			tab[0]=deplace_raquette(tab[0]);

			dessine_objet(tab[0]);
			dessine_objet(tab[2]);
			
			affiche_all();
			b=defaite(tab[2]);

			attendre(vitesse);

		}
		efface_score();
		vie=vie-1;
		score_vie=0;
		printf("nombre de vie = %d \n",vie);
		affiche_score();
		
		efface_objet(tab[0]);
		efface_objet(tab[2]);
		
		tab[2].px=tab[2].pxi;
		tab[2].py=tab[2].pyi;
		tab[2].vy=-tab[2].vy;
		tab[0].px=tab[0].pxi;
		tab[0].py=tab[0].pyi;
		
		dessine_objet(tab[0]);
		dessine_objet(tab[2]);
		
		b=0;
		
		clignotter();
		
		
	}
	
	aff_pol("Game Over",125,go,blanc);
	affiche_all();
	
	wait_escape();
	return 0;
}

