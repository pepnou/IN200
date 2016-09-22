#include "graphics.h"
#include <stdio.h>

#define largeur 20
#define hauteur 20
#define cote 25

void draw_quad(COULEUR color);
void init_tableau(int tab[largeur][hauteur][3]);
void draw_serpent(int tab[largeur][hauteur][3]);
int deplace_tete_serpent(POINT dep,int tab[largeur][hauteur][3]);
POINT gestion_fleche();
void fin_tour(int tab[largeur][hauteur][3]);

int longueur = 3;


int main()
{
	init_graphics(largeur*cote,hauteur*cote);
	affiche_auto_off();
	
	int etat[largeur][hauteur][3];
	init_tableau(etat);
	
	POINT dep;
	dep.x=1;
	dep.y=0;
	
	int continuer = 1;
	
	while (continuer == 1)
	{
		printf("dep.x = %d\n",dep.x);
		printf("dep.y = %d\n",dep.y);
//		dep = gestion_fleche();
		printf("(1) \n");
		continuer = deplace_tete_serpent(dep,etat);
		printf("(2) \n");
		fin_tour(etat);
		printf("(3) \n");
		draw_serpent(etat);
		printf("(4) \n");
		draw_quad(blanc);
		printf("(5) \n");
		attendre(1000);
	}
	
	
	wait_escape();
	return 0;
}









void fin_tour(int tab[largeur][hauteur][3])
{
	int i,j;
	
	for(i=0;i<largeur;i++)
	{
		for(j=0;j<hauteur;j++)
		{
			if(tab[i][j][1]>0) tab[i][j][1] = tab[i][j][1] - 1;
		}
	}
}

POINT gestion_fleche()
{
	POINT dep;
		
	SDL_Event event;
	SDL_PollEvent(&event);
	if(event.type == SDLK_UP)
	{
		dep.x = 0;
		dep.y = 1;
	}
	if(event.type == SDLK_DOWN)
	{
		dep.x = 0;
		dep.y = -1;
	}
	if(event.type == SDLK_RIGHT)
	{
		dep.x = 1;
		dep.y = 0;
	}
	if(event.type == SDLK_LEFT)
	{
		dep.x = -1;
		dep.y = 0;
	}
	
	return dep;
}

int deplace_tete_serpent(POINT p,int tab[largeur][hauteur][3])
{
	int i,j,cx,cy;
//	cx=largeur/2;
//	cy=hauteur/2;
	
	for(i=0;i<largeur;i++)
	{
		for(j=0;j<hauteur;j++)
		{
			if(tab[i][j][1] == 1)
			{
				cx = i;
				cy = j;
			}
		}
	}
	
	printf("p.x = %d\n",p.x);
	printf("p.y = %d\n",p.y);
	
	if(((cx==largeur-1)&&(p.x==1)) || ((cx==0)&&(p.x==-1)) || ((cy==hauteur-1)&&(p.y==1)) || ((cy==0)&&(p.y==-1)) || (tab[cx+p.x][cy+p.y][0]==1)) return 0;
	else
	{
		printf("lama \n");
		
		tab[cx][cy][1] = 0;
		tab[cx+p.x][cy+p.y][1] = 1;
		tab[cx+p.x][cy+p.y][0] = longueur;
		return 1;
	}
	
	
	
}

void draw_serpent(int tab[largeur][hauteur][3])
{
	POINT p1,p2;
	
	
	
	int i,j;
	
	for(i=0;i<largeur;i++)
	{
		for(j=0;j<hauteur;j++)
		{
			if(tab[i][j][0] > 0)
			{
				p1.x=i*cote;p1.y=j*cote;
				p2.x=(i+1)*cote;p2.y=(j+1)*cote;
				draw_fill_rectangle(p1,p2,couleur_RGB(255,187,0));
			}
		}
	}
	
	affiche_all();
}

void init_tableau(int tab[largeur][hauteur][3])
{
	int i,j,k;
	
	for(i=0;i<largeur;i++)
	{
		for(j=0;j<hauteur;j++)
		{
			for(k=0;k<3;k++)
			{
				tab[i][j][k]=0;
			}
		}
	}
	
	tab[largeur/2][hauteur/2][1]=1;
}

void draw_quad(COULEUR color)
{
	POINT p1;
	POINT p2;
	
	int i;
	
	for(i=cote;i<largeur*cote+hauteur*cote;i=i+cote)
	{
		p1.x=0;p1.y=i;
		p2.x=largeur*cote;p2.y=i;
		draw_line(p1,p2,color);
		
		p1.x=i;p1.y=0;
		p2.x=i;p2.y=hauteur*cote;
		draw_line(p1,p2,color);
	}
	
	p1.x=0;p1.y=0;
	p2.x=largeur*cote-1;p2.y=hauteur*cote-1;
	draw_rectangle(p1,p2,color);
}

