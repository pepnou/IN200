#include "graphics.h"
#include <stdio.h>

#define largeur 50
#define hauteur 50
#define cote 7

void draw_quad(COULEUR color);
void init_tableau(int tab[largeur][hauteur][3]);
void draw_serpent(int tab[largeur][hauteur][3]);
int deplace_tete_serpent(POINT p,int tab[largeur][hauteur][3]);
POINT gestion_fleche(POINT dep);
void fin_tour(int tab[largeur][hauteur][3]);
void afficher_tableau(int tab[largeur][hauteur][3]);
void ajout_fruit(int tab[largeur][hauteur][3]);

int longueur = 10;


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
	wait_clic();
	while (continuer == 1)
	{
		
		ajout_fruit(etat);
		printf("dep.x = %d\n",dep.x);
		printf("dep.y = %d\n",dep.y);
		
		dep = gestion_fleche(dep);
		
		printf("(1) \n");
		
		continuer = deplace_tete_serpent(dep,etat);
		
		printf("(2) \n");
		
//		afficher_tableau(etat);
		
		fin_tour(etat);
		
		printf("(3) \n");
		
		draw_serpent(etat);
		
		printf("(4) \n");
		
//		draw_quad(couleur_RGB(155,0,0));
		
		printf("(5) \n");
		
		attendre(50);
	}
	longueur = longueur - 10;
	write_int(longueur);
	wait_escape();
	return 0;
}





void ajout_fruit(int tab[largeur][hauteur][3])
{
	int a;
	int b;
	int c;
	
//	a = seconde();
//	if(a%5 == 0)
//	{
		b=alea_int(largeur);
		c=alea_int(hauteur);
		
		tab[b][c][2]=1;
//	}
}

void afficher_tableau(int tab[largeur][hauteur][3])
{
	int i;
	int j;
	
	printf("premier etage \n");
	
	for(i=0;i<largeur;i++)
	{
		for(j=0;j<hauteur;j++)
		{
			printf(" %d\n",tab[i][j][0]);
		}
	}
	
	printf("deuxieme etage \n");
	
	for(i=0;i<largeur;i++)
	{
		for(j=0;j<hauteur;j++)
		{
			printf(" %d\n",tab[i][j][1]);
		}
	}
	
	printf("troisieme etage \n");
	
	for(i=0;i<largeur;i++)
	{
		for(j=0;j<hauteur;j++)
		{
			printf(" %d\n",tab[i][j][2]);
		}
	}
}

void fin_tour(int tab[largeur][hauteur][3])
{
	int i,j;
	
	for(i=0;i<largeur;i++)
	{
		for(j=0;j<hauteur;j++)
		{
			if(tab[i][j][0] > 0) tab[i][j][0] = tab[i][j][0] - 1;
		}
	}
}

POINT gestion_fleche(POINT dep)
{
		
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_KEYDOWN)
		{
			switch(event.key.keysym.sym)
			{
				case SDLK_UP :
					if(dep.y != -1)
					{
						dep.x = 0;
						dep.y = 1;
					}
					break;
				case SDLK_DOWN :
					if(dep.y != 1)
					{
						dep.x = 0;
						dep.y = -1;
					}
					break;
				case SDLK_RIGHT :
					if(dep.x != -1)
					{
						dep.x = 1;
						dep.y = 0;
					}
					break;
				case SDLK_LEFT :
					if(dep.x != 1)
					{
						dep.x = -1;
						dep.y = 0;
					}
					break;
			}
		}
	}
	return dep;
}

int deplace_tete_serpent(POINT p,int tab[largeur][hauteur][3])
{
	int cx,cy;
	int i = 0;
	int j = 0;
	cx = 7;
	cy = 8;
	
//	cx=largeur/2;
//	cy=hauteur/2;
	
	for(i=0;i<largeur;i++)
	{
		for(j=0;j<hauteur;j++)
		{
			if(tab[i][j][1] == 1)
			{
//				printf("i = %d\n",i);
//				printf("j = %d\n",j);
				cx = i;
				cy = j;
			}
		}
	}
	
	printf("p.x = %d\n",p.x);
	printf("p.y = %d\n",p.y);
	printf("cx = %d\n",cx);
	printf("cy = %d\n",cy);
	
	
	if(((cx==largeur-1)&&(p.x==1)) || ((cx==0)&&(p.x==-1)) || ((cy==hauteur-1)&&(p.y==1)) || ((cy==0)&&(p.y==-1)) || (tab[cx+p.x][cy+p.y][0]>0)) return 0;
	else
	{
//		printf("test \n");
		
		tab[cx][cy][1] = 0;
		tab[cx+p.x][cy+p.y][1] = 1;
		tab[cx+p.x][cy+p.y][0] = longueur;
		
		printf("p.x = %d\n",p.x);
		printf("p.y = %d\n",p.y);
		printf("cx = %d\n",cx);
		printf("cy = %d\n",cy);
		printf("tab[cx][cy][1] = %d\n",tab[cx][cy][1]);
		printf("tab[cx+p.x][cy+p.y][1] = %d\n",tab[cx+p.x][cy+p.y][1]);
		printf("tab[cx+p.x][cy+p.y][0] = %d\n",tab[cx+p.x][cy+p.y][0]);
		
		if(tab[cx+p.x][cy+p.y][2] == 1)
		{
			longueur++;
			tab[cx+p.x][cy+p.y][2] = 0;
		}
	
		return 1;
	}
	
	
	
}

void draw_serpent(int tab[largeur][hauteur][3])
{
	fill_screen(noir);
	
	POINT p1,p2,p3;
	
	
	
	int i,j;
	
	for(i=0;i<largeur;i++)
	{
		for(j=0;j<hauteur;j++)
		{
			if(tab[i][j][2] == 1)
			{
				p3.x=i*cote+cote/2;p3.y=j*cote+cote/2;
				draw_fill_circle(p3,cote/2,couleur_RGB(147,0,119));
			}
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
	
	affiche_all();
}

