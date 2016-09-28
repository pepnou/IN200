#include "graphics.h"
#include <stdio.h>

int haut_ou_bas;
int gauche_ou_droite;
int OU_CA;

void qui_dit_ou_c_est(POINT p)
{
	if(p.x<200) gauche_ou_droite=0;
	else gauche_ou_droite=1;
	if(p.y<200) haut_ou_bas=0;
	else haut_ou_bas=1;
}

void calcul_OU_CA()
{
	if((haut_ou_bas==0)&&(gauche_ou_droite==0)) OU_CA=0;
	if((haut_ou_bas==0)&&(gauche_ou_droite==1)) OU_CA=1;
	if((haut_ou_bas==1)&&(gauche_ou_droite==0)) OU_CA=2;
	if((haut_ou_bas==1)&&(gauche_ou_droite==1)) OU_CA=3;
}

void dessine_cercle_couleur(POINT p)
{
	if(OU_CA==0) draw_circle(p,50,bleu);
	if(OU_CA==1) draw_circle(p,50,rouge);
	if(OU_CA==2) draw_circle(p,50,vert);
	if(OU_CA==3) draw_circle(p,50,jaune);
}


int main()
{
	init_graphics(400,400);
	
	POINT p;
	int i;
	for(i=0;i<20;i++)
	{
		p=wait_clic();
		qui_dit_ou_c_est(p);
		calcul_OU_CA();
		dessine_cercle_couleur(p);
	}
	
	
	wait_escape();
	return 0;
}

