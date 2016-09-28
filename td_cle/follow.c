#include "graphics.h"
#include <stdio.h>


#define largeur 100
#define hauteur 100
#define cote 7



void initialisation_tableau(int tab[largeur+2][hauteur+2]);
void dessine_terrain(int tab[largeur+2][hauteur+2]);
void gestion_fleche(int tab[largeur+2][hauteur+2]);
void follow(int tab[largeur+2][hauteur+2]);

int valeur_absolue(int a);

int cx_j = largeur / 2;
int cy_j = hauteur / 2;
int cx_e = 1;
int cy_e = 1;


int main()
{
	init_graphics(largeur*cote,hauteur*cote);
	affiche_auto_off();
	
	int etat[largeur+2][hauteur+2];
	initialisation_tableau(etat);
	
	etat[cx_j][cy_j] = 1;
	etat[cx_e][cy_e] = 2;
	
	while((cx_e != cx_j)||(cy_e != cy_j))
	{
		gestion_fleche(etat);
		follow(etat);
		dessine_terrain(etat);
		
		attendre(50);
	}
	
	wait_escape();
	return 0;
}

void initialisation_tableau(int tab[largeur+2][hauteur+2])
{
	int i,j;
	
	for(i=0;i<largeur+2;i++)
	{
		for(j=0;j<hauteur+2;j++)
		{
			tab[i][j] = 0;
		}
	}
}

void dessine_terrain(int tab[largeur+2][hauteur+2])
{
	POINT p1,p2;
	int i,j;
	
	for(i=1;i<largeur+1;i++)
		{
		for(j=1;j<hauteur+1;j++)
		{
			p1.x=(i-1)*cote;p1.y=(j-1)*cote;
			p2.x=i*cote;p2.y=j*cote;
			
			switch(tab[i][j])
			{
				case 0 : draw_fill_rectangle(p1,p2,couleur_RGB(0,0,0)); break ;
				case 1 : draw_fill_rectangle(p1,p2,couleur_RGB(0,0,255)); break ;
				case 2 : draw_fill_rectangle(p1,p2,couleur_RGB(255,0,0)); break ;
			}
		}
	}
	affiche_all();
}

void follow(int tab[largeur+2][hauteur+2])
{
	tab[cx_e][cy_e] = 0;
	if((cx_e != cx_j)||(cy_e != cy_j))
	{
		if(valeur_absolue(cx_j-cx_e)>valeur_absolue(cy_j-cy_e))
		{
			if(cx_j>cx_e) cx_e++;
			else cx_e--;
		}
		else
		{
			if(cy_j>cy_e) cy_e++;
			else cy_e--;
		}
		tab[cx_e][cy_e] = 2;
	}
}

void gestion_fleche(int tab[largeur+2][hauteur+2])
{
	POINT p;
	p = get_arrow();
	
	tab[cx_j][cy_j] = 0;
	
	cx_j = cx_j + p.x;
	cy_j = cy_j + p.y;
	
	tab[cx_j][cy_j] = 1;	
	
}

int valeur_absolue(int a)
{
	if(a<0) a = a * (-1);	
	return a;
}
