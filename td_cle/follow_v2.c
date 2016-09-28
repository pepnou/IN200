#include "graphics.h"
#include <stdio.h>


#define largeur 100
#define hauteur 100
#define cote 7
#define nbr_e 4



void initialisation_tableau(int tab[largeur+2][hauteur+2]);
void dessine_terrain(int tab[largeur+2][hauteur+2]);
void gestion_fleche(int tab[largeur+2][hauteur+2]);
void follow(int tab[largeur+2][hauteur+2]);
int fin(int tab[largeur+2][hauteur+2]);

int valeur_absolue(int a);

int cx_j = largeur / 2;
int cy_j = hauteur / 2;
int e[nbr_e][2];


int main()
{
	init_graphics(largeur*cote,hauteur*cote);
	affiche_auto_off();
	
	int etat[largeur+2][hauteur+2];
	initialisation_tableau(etat);
	
	etat[cx_j][cy_j] = 1;
	
	int continuer = 1;
	
	while(continuer == 1)
	{
		gestion_fleche(etat);
		follow(etat);
		dessine_terrain(etat);
		
		continuer = fin(etat);
		attendre(50);
	}
	
	wait_escape();
	return 0;
}

int fin(int tab[largeur+2][hauteur+2])
{
	int i;
	
	for(i=0;i<nbr_e;i++)
	{
		if((cx_j == e[i][0])&&(cy_j ==e[i][1])) return 0;
	}
	
	return 1;
}

void initialisation_tableau(int tab[largeur+2][hauteur+2])
{
	int i,j;
	POINT p;
	
	for(i=0;i<largeur+2;i++)
	{
		for(j=0;j<hauteur+2;j++)
		{
			tab[i][j] = 0;
		}
	}	
	for(i=0;i<nbr_e;i++)
	{
		printf("clic restant : %d\n",nbr_e-i);
		p = wait_clic();
		
		e[i][0] = p.x/cote + 1;
		e[i][1] = p.y/cote + 1;
		
		tab[e[i][0]][e[i][1]] = 2;
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
	int i,j,a;
	a=1;
	
	for(i=0;i<nbr_e;i++)
	{
		tab[e[i][0]][e[i][1]] = 0;
		if((e[i][0] != cx_j)||(e[i][1] != cy_j))
		{
			if(valeur_absolue(cx_j-e[i][0])>valeur_absolue(cy_j-e[i][1]))
			{
				if(cx_j>e[i][0])
				{
					for(j=0;j<nbr_e;j++)
					{
						if(e[j][0] == e[i][0] +1) a=0;
					}
					if(a == 1) e[i][0]++;
				}
				else
				{
					for(j=0;j<nbr_e;j++)
					{
						if(e[j][0] == e[i][0] -1) a=0;
					}
					if(a == 1) e[i][0]--;
				}
			}
			else
			{
				if(cy_j>e[i][1])
				{
					for(j=0;j<nbr_e;j++)
					{
						if(e[j][1] == e[i][1] +1) a=0;
					}
					if(a == 1) e[i][1]++;
				}
				else
				{
					for(j=0;j<nbr_e;j++)
					{
						if(e[j][1] == e[i][1] -1) a=0;
					}
					if(a == 1) e[i][1]--;
				}
			}
			tab[e[i][0]][e[i][1]] = 2;
		}
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
