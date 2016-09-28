#include "graphics.h"
#include <stdio.h>

#define largeur 20
#define hauteur 25
#define cote 25
#define X largeur*cote
#define Y hauteur*cote
#define duree 0
#define score_max 1500

int score = 0;
int nbr_clic = 0;
int ini = 1;

void draw_quad(int inter);
void gestion_etat(int tab[largeur+2][hauteur+2]);
void init_test(int tab[largeur+2][hauteur+2]);
void dessine_case(int tab[largeur+2][hauteur+2]);
void dessine_plateau(int tab[largeur+2][hauteur+2]);
void gestion_clic(int tab[largeur+2][hauteur+2]);
int test_joueur(int tab[largeur+2][hauteur+2]);
int combo(int tab[largeur+2][hauteur+2],int cx,int cy);
int test_fin(int tab[largeur+2][hauteur+2]);

int main()
{
	int i;
	int j;
	int continuer = 1;
	
	int etat[largeur+2][hauteur+2];
	for(i=1;i<largeur+1;i++)
	{
		for(j=1;j<hauteur+1;j++)
		{
			etat[i][j] = 0;
			
		}
	}
	
	init_graphics(X,Y);
	affiche_auto_off();
	
	
	int possibilite_de_jouer;
	int k;
	
	
	while(continuer == 1)
	{
		dessine_plateau(etat);
		
		possibilite_de_jouer = test_joueur(etat);
		
		if(possibilite_de_jouer == 1) 
		{
			ini = 0;
			gestion_clic(etat);
		}
		
		
		for(j=0;j<(largeur*largeur);j++)
		{
			for(k=2;k<largeur+1;k++)
			{
				if(etat[k][1] == (-1))
				{
					for(i=hauteur;i>0;i--)
					{
						etat[k][i] = etat[k-1][i];
						etat[k-1][i] = (-1);
					}
				}
			}
		}
		
		continuer = test_fin(etat);
	}
	fill_screen(noir);
	
	POINT eg1;
	eg1.x=10;
	eg1.y=HEIGHT - 10;
	
	POINT eg2;
	eg2.x=eg1.x;
	eg2.y=eg1.y - 150;
	
	aff_pol("score : ",50,eg1,blanc);
	eg1.y = eg1.y -60;
	aff_int(score,50,eg1,blanc);
	
	aff_pol("nombre de coups : ",50,eg2,blanc);
	eg2.y = eg2.y - 60;
	aff_int(nbr_clic,50,eg2,blanc);
	
	
	
	
	
	wait_escape();
	return 0;
}

int combo(int tab[largeur+2][hauteur+2],int cx,int cy)
{
	int point = 1;
	int a;
	
	a = tab[cx][cy];
	tab[cx][cy] = 0;
	
	if(tab[cx-1][cy] == a) point = point + combo(tab,cx-1,cy);
	if(tab[cx+1][cy] == a) point = point + combo(tab,cx+1,cy);
	if(tab[cx][cy-1] == a) point = point + combo(tab,cx,cy-1);
	if(tab[cx][cy+1] == a) point = point + combo(tab,cx,cy+1);
	
	
	
	return point;
}

void gestion_clic(int tab[largeur+2][hauteur+2])
{
	POINT p;
	int cx;
	int cy;
	
	p = wait_clic();
	
	cx = p.x / cote +1;
	cy = p.y / cote +1;
	
//	tab[cx][cy] = 42;
	
	int sc;
	if(tab[cx][cy] != (-1))
	{
		sc = combo(tab,cx,cy) ;
	
		score = score + (sc*(sc-1));
		nbr_clic = nbr_clic + 1;
	}
}

int test_joueur(int tab[largeur+2][hauteur+2])
{
	int i;
	int j;
	
	for(i=1;i<largeur+1;i++)
	{
		for(j=1;j<hauteur+1;j++)
		{
			if (tab[i][j] == 0) return 0;
		}
	}
	return 1;
}

int test_fin(int tab[largeur+2][hauteur+2])
{
	int i;
	int j;
	
	for(i=1;i<largeur+1;i++)
	{
		for(j=1;j<hauteur+1;j++)
		{
			if (tab[i][j] != (-1)) return 1;
		}
	}
	return 0;
}


void dessine_plateau(int tab[largeur+2][hauteur+2])
{
	fill_screen(couleur_RGB(0,125,25));
//	fill_screen(couleur_RGB(255,100,255));
	
	draw_quad(cote);
	
	init_test(tab);
	
	dessine_case(tab);
	
	attendre(duree);
	
	gestion_etat(tab);
	
	POINT p;
	p.x = 15;
	p.y = HEIGHT -15;
	aff_int(score,50,p,couleur_RGB(255,127,255));
	
	affiche_all();
}

void init_test(int tab[largeur+2][hauteur+2])
{
	int i;
	if(ini == 1)
	{
		for(i=1;i<largeur+1;i++)
		{
			if(tab[i][hauteur]==0) tab[i][hauteur]= alea_int(4)+1;
//			if(tab[i][hauteur]==0) tab[i][hauteur]= 2;
		}
	}
	if(ini == 0)
	{
		for(i=1;i<largeur+1;i++)
		{
			if(tab[i][hauteur]==0) tab[i][hauteur]= (-1);
		}
	}
	
}

void dessine_case(int tab[largeur+2][hauteur+2])
{
	POINT p;
	
	int i;
	int j;
	
	for(i=1;i<largeur+1;i++)
	{
		for(j=1;j<hauteur+11;j++)
		{
			p.x = cote/2 + (i-1)*cote;
			p.y = cote/2 + (j-1)*cote;
			
			if(tab[i][j] == 1) draw_fill_circle(p,cote/2,couleur_RGB(255,0,0));
			if(tab[i][j] == 2) draw_fill_circle(p,cote/2,couleur_RGB(0,255,0));
			if(tab[i][j] == 3) draw_fill_circle(p,cote/2,couleur_RGB(0,0,255));
			if(tab[i][j] == 4) draw_fill_circle(p,cote/2,couleur_RGB(255,255,0));
			if(tab[i][j] == 42) draw_fill_circle(p,cote/2,couleur_RGB(255,127,255));
			
		}
	}
}

void gestion_etat(int tab[largeur+2][hauteur+2])
{
	int i;
	int k;
	int j;

	for(k=1;k<largeur+1;k++)
	{
		for(i=hauteur;i>1;i--)
		{
			if( tab[k][i-1] == 0)
			{
					tab[k][i-1] = tab[k][i];
					tab[k][i]=0;
					i=0;
			}
		}
	}
	/*
	for(k=2;k<largeur+1;k++)
	{
		for(i=hauteur;i>1;i--)
		{
			if((tab[k][i] == (-1))&&(tab[k][i] != tab[k][i-1])) i = 1;
			if(i == 2)
			{
				for(j=hauteur;j>0;j--)
				{
					tab[k][j] = tab[k-1][j];
					tab[k-1][j] = (-1);
				}
			}
		}
	}
	*/
}


void draw_quad(int inter)
{
	POINT p1;
	POINT p2;
	
	int a;
	int b;
	
	a = WIDTH / inter;
	b = HEIGHT /inter;
	
	int i;
	
	for(i=1;i<=a;i++)
	{
		p1.y=0;
		p1.x=i*inter;
		p2.y=HEIGHT;
		p2.x=p1.x;
		
		draw_line(p1,p2,blanc);
	}
	
	for(i=1;i<=b;i++)
	{
		p1.x=0;
		p1.y=i*inter;
		p2.x=WIDTH;
		p2.y=p1.y;
		
		draw_line(p1,p2,blanc);
	}
}
