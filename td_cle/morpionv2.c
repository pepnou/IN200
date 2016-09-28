#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
init_graphics(620,620);

// Debut du code

//chaque case possede une variable du type c. pour son etat : non active , activé par le joueur 1 ,activé par le joueur 2


int i;
int c1=0;
int c2=0;
int c3=0;
int c4=0;
int c5=0;
int c6=0;
int c7=0;
int c8=0;
int c9=0;


//variable de detection de victoire par le joueur 1 ou 2 ou egalité

int v1=0;
int v2=0;
int e=0;

//variable du numero de joueur (1 ou 2)

int pl=1;

//point du click

POINT cl;

//point permettant de creer le quadrillage de jeu

POINT p1;
p1.x=200;p1.y=620;
POINT p2;
p2.x=210;p2.y=0;
POINT p3;
p3.x=410;p3.y=620;
POINT p4;
p4.x=420;p4.y=0;
POINT p5;
p5.x=0;p5.y=200;
POINT p6;
p6.x=620;p6.y=210;
POINT p7;
p7.x=0;p7.y=410;
POINT p8;
p8.x=620;p8.y=420;

//quadrillage de jeu

draw_fill_rectangle(p1,p2,orange);
draw_fill_rectangle(p3,p4,orange);
draw_fill_rectangle(p5,p6,orange);
draw_fill_rectangle(p7,p8,orange);

// mileu de chaque case pour le tracage des signe d occupation de la case

POINT p11;
p11.x=100;p11.y=520;
POINT p12;
p12.x=310;p12.y=520;
POINT p13;
p13.x=520;p13.y=520;
POINT p14;
p14.x=100;p14.y=310;
POINT p15;
p15.x=310;p15.y=310;
POINT p16;
p16.x=520;p16.y=310;
POINT p17;
p17.x=100;p17.y=100;
POINT p18;
p18.x=310;p18.y=100;
POINT p19;
p19.x=520;p19.y=100;






//boucle active tant qu un joueur ne forme pas une ligne

while((v1==0)&&(v2==0)&&(e==0))
{

printf("\033[H\033[2J");


if(pl==1)
printf("tour du joueur 1 \n");
else
printf("tour du joueur 2 \n");


//on attend le click , on repere la case , verifie si elle est occupé et lui associe la variable du joueur en train de jouer (1 ou 2) 





cl=wait_clic();




if(cl.x<200)
	{
	if(cl.y>420)
		{
		if(c1==0)
			{
			c1=pl;
			if(pl==1) pl=2;
			else pl=1;
			}
		}
	else 
		{
		if(cl.y<200) 
			{
			if(c7==0)
				{	
				c7=pl;
				if(pl==1)pl=2;
				else pl=1;
				}	
			}
		else
			{
			if(c4==0)
				{
				c4=pl;
				if(pl==1)pl=2;
				else pl=1;
				}
			}
		}
	}
else
	{
	if(cl.x>420)
		{
		if(cl.y>420) 
			{
			if(c3==0)
				{
				c3=pl;
				if(pl==1)pl=2;
				else pl=1;
				}
			}
			else
			{
			if(cl.y<200) 
				{
				if(c9==0)
					{
					c9=pl;
					if(pl==1)pl=2;
					else pl=1;
					}	
				}
				else
				{
				if(c6==0)
					{
					c6=pl;
					if(pl==1)pl=2;
					else pl=1;
					}	
				}
			}
		}
	else
		{
		if(cl.y>420) 
			{
			if(c2==0)
				{
				c2=pl;
				if(pl==1)pl=2;
				else pl=1;
				}
			}
			else 
			{
			if(cl.y<200) 
				{
				if(c8==0)
					{
					c8=pl;
					if(pl==1)pl=2;
					else pl=1;
					}
				}
				else
				{
				if(c5==0)
					{
					c5=pl;
					if(pl==1)pl=2;
					else pl=1;
					}
				}
			}
		}
	}


//on verifie le statut de chaque case pour savoir si l on doit tracer le signe d occupation ,si necessaire , il est ensuite tracé


//partie du joueur 1

if(c1==1)
	{
	draw_fill_circle(p11,80,bleu);
	draw_fill_circle(p11,70,black);
	}
if(c2==1)
	{
	draw_fill_circle(p12,80,bleu);
	draw_fill_circle(p12,70,black);
	}

if(c3==1)
	{
	draw_fill_circle(p13,80,bleu);
	draw_fill_circle(p13,70,black);
	}
if(c4==1)
	{
	draw_fill_circle(p14,80,bleu);
	draw_fill_circle(p14,70,black);
	}
if(c5==1)
	{
	draw_fill_circle(p15,80,bleu);
	draw_fill_circle(p15,70,black);
	}
if(c6==1)
	{
	draw_fill_circle(p16,80,bleu);
	draw_fill_circle(p16,70,black);
	}
if(c7==1)
	{
	draw_fill_circle(p17,80,bleu);
	draw_fill_circle(p17,70,black);
	}
if(c8==1)
	{
	draw_fill_circle(p18,80,bleu);
	draw_fill_circle(p18,70,black);
	}
if(c9==1)
	{
	draw_fill_circle(p19,80,bleu);
	draw_fill_circle(p19,70,black);
	}

//partie du jouer 2

if(c1==2)draw_fill_circle(p11,80,rouge);
if(c2==2)draw_fill_circle(p12,80,rouge);
if(c3==2)draw_fill_circle(p13,80,rouge);
if(c4==2)draw_fill_circle(p14,80,rouge);
if(c5==2)draw_fill_circle(p15,80,rouge);
if(c6==2)draw_fill_circle(p16,80,rouge);
if(c7==2)draw_fill_circle(p17,80,rouge);
if(c8==2)draw_fill_circle(p18,80,rouge);
if(c9==2)draw_fill_circle(p19,80,rouge);


//on verifie si un joueur a gagné


if((c1==c2)&&(c2==c3)&&((c1+c2+c3)==3)||(c4==c5)&&(c5==c6)&&((c4+c5+c6)==3)||(c7==c8)&&(c8==c9)&&((c7+c8+c9)==3)||(c1==c4)&&(c4==c7)&&((c1+c4+c7)==3)||(c2==c5)&&(c5==c8)&&((c2+c5+c8)==3)||(c3==c6)&&(c6==c9)&&((c3+c6+c9)==3)||(c7==c5)&&(c5==c3)&&((c7+c5+c3)==3)||(c1==c5)&&(c5==c9)&&((c1+c5+c9)==3))
v1=1;


if((c1==c2)&&(c2==c3)&&((c1+c2+c3)==6)||(c4==c5)&&(c5==c6)&&((c4+c5+c6)==6)||(c7==c8)&&(c8==c9)&&((c7+c8+c9)==6)||(c1==c4)&&(c4==c7)&&((c1+c4+c7)==6)||(c2==c5)&&(c5==c8)&&((c2+c5+c8)==6)||(c3==c6)&&(c6==c9)&&((c3+c6+c9)==6)||(c7==c5)&&(c5==c3)&&((c7+c5+c3)==6)||(c1==c5)&&(c5==c9)&&((c1+c5+c9)==6))
v2=1;

if((v1==0)&&(v2==0)&&(c1!=0)&&(c2!=0)&&(c3!=0)&&(c4!=0)&&(c5!=0)&&(c6!=0)&&(c7!=0)&&(c8!=0)&&(c9!=0))
e=1;

printf("afficher valeur de e= %d \n", e);

}



if(v1==1)
{
init_graphics(640,480);
//le_joueur_1_a_gagne
}

if(v2==1)
{
init_graphics(640,480);
//le_joueur_2_a_gagne
}

if(e==1)
{
init_graphics(640,480);
//egalité
}









// Fin du code

wait_escape();
exit(0);
}
