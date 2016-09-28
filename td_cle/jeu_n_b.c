#include "graphics.h"
#include <stdio.h>


int plat[10][10];
int somme_case;

void affiche_plateau()
{
	fill_screen(couleur_RGB(0,170,0));
	draw_quadrillage(60,60,noir);
}

void remplir_plateau()
{
	int i;int j;
	for (i=0;i<10;i++)
	{
		for (j=0;j<10;j++)
		{
			plat[i][j]=alea_int(2);
		}
	}
}

void affiche_pion()
{
	POINT p;
	int i;int j;
	for (i=0;i<10;i++)
	{
		for (j=0;j<10;j++)
		{
			p.x=30+i*60;p.y=30+j*60;
			if(plat[i][j]==0)
			{
				draw_fill_circle(p,30,blanc);
			}
			else
			{
				draw_fill_circle(p,30,noir);
			}
		}
	}	
}

void initialisation_case()
{
	int i;int j;
	for (i=0;i<10;i++)
	{
		for (j=0;j<10;j++)
		{
			plat[i][j]=0;
		}
	}
}

int somme()
{
	int i;int j;
	for (i=0;i<10;i++)
	{
		for (j=0;j<10;j++)
		{
			somme_case=somme_case+plat[i][j];
		}
	}
	return somme_case;
}

int ou_on_clic_en_x(POINT p)
{
	int i;
	for (i=0;i<10;i++)
	{
		if((i+1)*60>p.x) return i;
	}
}
	
int ou_on_clic_en_y(POINT p)
{
	int i;
	for (i=0;i<10;i++)
	{
		if((i+1)*60>p.y) return i;
	}
}

void retourne_case(int i,int j)
{
	plat[i][j]=(plat[i][j]+1)%2;
	
	if((i==0)&&(j!=0)&&(j!=9))
	{
		plat[i+1][j]=(plat[i+1][j]+1)%2;
		plat[i][j+1]=(plat[i][j+1]+1)%2;
		plat[i][j-1]=(plat[i][j-1]+1)%2;
	}
	if((i==9)&&(j!=0)&&(j!=9))
	{
		plat[i-1][j]=(plat[i-1][j]+1)%2;
		plat[i][j+1]=(plat[i][j+1]+1)%2;
		plat[i][j-1]=(plat[i][j-1]+1)%2;
	}
	if((j==0)&&(i!=0)&&(i!=9))
	{
		plat[i+1][j]=(plat[i+1][j]+1)%2;
		plat[i-1][j]=(plat[i-1][j]+1)%2;
		plat[i][j+1]=(plat[i][j+1]+1)%2;
	}
	if((j==9)&&(i!=0)&&(i!=9))
	{
		plat[i+1][j]=(plat[i+1][j]+1)%2;
		plat[i-1][j]=(plat[i-1][j]+1)%2;
		plat[i][j-1]=(plat[i][j-1]+1)%2;
	}
	
	
	if((i==0)&&(j==0))
	{
		plat[i+1][j]=(plat[i+1][j]+1)%2;
		plat[i][j+1]=(plat[i][j+1]+1)%2;
	}
	
	
	if((i==0)&&(j==9))
	{
		plat[i+1][j]=(plat[i+1][j]+1)%2;
		plat[i][j-1]=(plat[i][j-1]+1)%2;
	}
	
	if((i==9)&&(j==0))
	{
		plat[i-1][j]=(plat[i-1][j]+1)%2;
		plat[i][j+1]=(plat[i][j+1]+1)%2;
	}
	
	if((i==9)&&(j==9))
	{
		plat[i-1][j]=(plat[i-1][j]+1)%2;
		plat[i][j-1]=(plat[i][j-1]+1)%2;
	}
	
	
	if((i!=0)&&(i!=9)&&(j!=0)&&(j!=9))
	{
		plat[i+1][j]=(plat[i-1][j]+1)%2;
		plat[i-1][j]=(plat[i-1][j]+1)%2;
		plat[i][j+1]=(plat[i][j+1]+1)%2;
		plat[i][j-1]=(plat[i][j-1]+1)%2;
	}
}








int main()
{
	POINT p;
	init_graphics(600,600);
	affiche_plateau();
	initialisation_case();
	remplir_plateau();
	affiche_pion();
	
	while ((somme!=0)&&(somme!=100))
	{
		p=wait_clic();
		retourne_case(ou_on_clic_en_x(p),ou_on_clic_en_y(p));
		affiche_plateau();
		affiche_pion();
	
	}
	wait_escape();
	return 0;
}

