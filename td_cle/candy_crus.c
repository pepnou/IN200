#include "graphics.h"
#include <stdio.h>


void draw_quad(int inter);
void gestion_etat(int tab[][]);
void init_test(int tab[][]);

int main()
{
	int etat[12][12];
	
	init_graphics(500,500);
	affiche_auto_off();
	init_test(etat);
	
	
	
	
	while(1)
	{
		fill_screen(couleur_RGB(35,156,27));
		draw_quad(50);
		
		gestion_etat(etat);
		
//		dessine_case();
		
		affiche_all();
	}
	wait_escape();
	return 0;
}

void init_test(int tab[][])
{
	int i;
	for(i=1;i<11;i++)
	{
		tab[i][10]=alea_int(4)+1;
	}
}

void gestion_etat(int tab[][])
{
	int i;
	int j;
	int k;
	
	
	for(k=1;k<11;k++)
	{
		for(i=1;i<11;i++)
		{
			if( tab[k][i-1] == 0)
			{
				for(j=i-1;j<10;j++)
				{
					tab[k][j]=tab[k][j+1];
					tab[k][10]=alea_int(4)+1;
				}
			}
		}
	}
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
