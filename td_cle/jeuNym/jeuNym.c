#include "graphics.h"
#include <stdio.h>

int joueur=(-1);
int nbr=50;


void draw_board();
void gestion_clic();

int main()
{
	init_graphics(900,600);
	affiche_auto_off();
	
	
	while(nbr>0)
	{
		joueur = joueur * (-1);
		draw_board();
		
		gestion_clic();
		
		
		
	}
	
	
	POINT a1;
	a1.x = 100;
	a1.y = HEIGHT/2;
	fill_screen(noir);
	if(joueur == 1)
	aff_pol("PLAYER 2 WIN",75,a1,blanc);
	else
	aff_pol("PLAYER 1 WIN",75,a1,blanc);
	
	
	
	
	wait_clic();
	return 0;
}

void gestion_clic()
{
	int a = nbr;
	POINT p;
	p.x=0;
	p.y=0;
	while(a==nbr)
	{
		p = wait_clic();
		if((p.y>=50)&&(p.y<=150))
		{
			if((p.x > WIDTH/4-50)&&(p.x < WIDTH/4+50)) nbr = nbr - 1;
			if((p.x > WIDTH*2/4-50)&&(p.x < WIDTH*2/4+50)) nbr = nbr - 2;
			if((p.x > WIDTH*3/4-50)&&(p.x < WIDTH*3/4+50)) nbr = nbr - 3;
		}
	}
}


void draw_board()
 {
	 
	 fill_screen(noir);
	 
	 POINT p1;
	 p1.y=400;
	 POINT p2;
	 p2.y=p1.y-5;
	 POINT p3;
	 p3.y=p2.y-30;
	 
	 int i;
	 for(i=0;i<nbr;i++)
	 {
		 p1.x=50+(15*i);
		 p2.x=p1.x+5;
		 p3.x=p1.x;
		 
		 draw_fill_rectangle(p2,p1,couleur_RGB(240,0,0));
		 draw_fill_rectangle(p3,p2,couleur_RGB(242,171,90));
	 }
	 
	 
	 POINT i1;
	 i1.x=WIDTH/4-50;
	 i1.y=150;
	 POINT i2;
	 i2.x=WIDTH*2/4-50;
	 i2.y=i1.y;
	 POINT i3;
	 i3.x=WIDTH*3/4-50;
	 i3.y=i1.y;
	 
	 affiche_image_perso("JNYM1.bmp",i1,100,100,255,0,0);
	 affiche_image_perso("JNYM2.bmp",i2,100,100,255,0,0);
	 affiche_image_perso("JNYM3.bmp",i3,100,100,255,0,0);
	 
	 POINT a1;
	 a1.x = 20;
	 a1.y = HEIGHT - 10;
	 
	 if(joueur==1)
	 aff_pol("J1",50,a1,blanc);
	 else
	 aff_pol("J2",50,a1,blanc);
	 
	 affiche_all();
 }
