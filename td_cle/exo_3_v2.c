#include "graphics.h"
#include <stdio.h>

int nbr_balle=10;
POINT pa[1000];
POINT pn[1000];
int dx[1000];
int dy[1000];
COULEUR coul[1000];
int taille[1000];

int largeur=900;
int hauteur=600;



void efface_affiche()
{
	int i;
	for(i=0;i<nbr_balle;i++)
	{
		draw_circle(pa[i],taille[i],noir);
		draw_circle(pn[i],taille[i],coul[i]);
		pa[i].x=pn[i].x;pa[i].y=pn[i].y;
	}
}


void deplace_balle()
{
	int i;
	for(i=0;i<nbr_balle;i++)
	{
		pn[i].x=pn[i].x+dx[i];
		pn[i].y=pn[i].y+dy[i];
	}
}

void rebond()
{
	int i;
	for(i=0;i<nbr_balle;i++)
	{
		if((pn[i].x<taille[i])||(pn[i].x>largeur-taille[i])) dx[i]=-dx[i];
		if((pn[i].y<taille[i])||(pn[i].y>hauteur-taille[i])) dy[i]=-dy[i];
	}
}

void rebond_balle()
{
	int i;
	int j;
	for(i=0;i<nbr_balle;i++)
		{
			for(j=i+1;j<nbr_balle;j++)
			{
				if (distance(pn[i],pn[j])<(taille[i]+taille[j]))
				{
					dx[i]=-dx[i];
					dy[i]=-dy[i];
					dx[j]=-dx[j];
					dy[j]=-dy[j];
				}
			}
		}
}



int main()
{
	
	int neg[2];
	neg[0]=-1;
	neg[1]=1;
	
	init_graphics(largeur,hauteur);
	
	int i;
	
	for(i=0;i<nbr_balle;i++)
	{
		pa[i].x=-9000;
		pa[i].y=-9000;
		
		pn[i]=wait_clic();
		dx[i]=(alea_int(2)+1)*neg[alea_int(2)];
		dy[i]=(alea_int(2)+1)*neg[alea_int(2)];
		coul[i]=couleur_RGB(alea_int(255),alea_int(255),alea_int(255));
		taille[i]=alea_int(41)+10;
	}


	while(1)
	{
		rebond();
		rebond_balle();
		deplace_balle();
		efface_affiche();
	}
	
	
	
	wait_escape();
	return 0;
}

