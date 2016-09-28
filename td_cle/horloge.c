#include "graphics.h"
#include <math.h>
#include <stdio.h>


POINT deplace_seconde(POINT a,POINT b,float c);
POINT deplace_minute(POINT a,POINT b,float c);
POINT deplace_heure(POINT a,POINT b,float c);
void affiche_horloge(POINT a,float c);

int rayon = 200;



int main()
{
	init_graphics(900,600);
	affiche_auto_off();
	
	
	POINT centre;
	centre.x=450;
	centre.y=300;
	
	POINT sec;
	POINT min;
	POINT heur;
	
	
	
	
	float conteur = 0;
	
	
	
	
	
	affiche_horloge(centre);
	
	while(1)
	{
		sec = deplace_seconde(sec,centre,conteur);
		min = deplace_minute(min,centre,conteur);
		heur = deplace_heure(heur,centre,conteur);
		if(conteur == 216000)
		{
			conteur = 0;
		}
		
		draw_line(centre,sec,rouge);
		draw_line(centre,min,bleu);
		draw_line(centre,heur,vert);
		
		conteur++;
		
		affiche_all();
		
//		printf("p.x = %d \n",sec.x);
//		printf("p.y = %d \n",sec.y);
//		printf("conteur = %d \n",conteur);
		
		
		attendre(10);
//		wait_clic();
//		sleep(1);
		
		affiche_horloge(centre,conteur);
		
	}
	
	wait_escape();
	return 0;
}


POINT deplace_seconde(POINT a,POINT b,float c)
{
	double d;
//	d = c % 60;
//	printf("d = %f \n",d);
	d = c;
	d = d / 60;
//	printf("d = %f \n",d);
	d = d * 2 * 3.14;
//	printf("d = %f \n",d);
	
	a.x=b.x+(sin(d)*(rayon-(rayon/100*10)));
	a.y=b.y+(cos(d)*(rayon-5));
	
	return a;
}

POINT deplace_minute(POINT a,POINT b,float c)
{
	double d;
	d = c;
	d = d / 3600;
//	printf("d = %f \n",d);
	d = d * 2 * 3.14;
//	printf("d = %f \n",d);
	
	a.x=b.x+(sin(d)*(rayon-(rayon/100*20)));
	a.y=b.y+(cos(d)*(rayon-(rayon/100*20)));
	
	return a;
}

POINT deplace_heure(POINT a,POINT b,float c)
{
	double d;
	d = c;
	d = d / 216000;
//	printf("d = %f \n",d);
	d = d * 2 * 3.14;
//	printf("d = %f \n",d);
	
	a.x=b.x+(sin(d)*(rayon-(rayon/100*50)));
	a.y=b.y+(cos(d)*(rayon-(rayon/100*50)));
	
	return a;
}


void affiche_horloge(POINT a,float c)
{
	fill_screen(noir);
	draw_circle(a,rayon,blanc);
	
	
	
	
	
	POINT p;
	p.x=;
	p.y=;
	POINT p;
	p.x=;
	p.y=;
	POINT p;
	p.x=;
	p.y=;
	POINT p;
	p.x=;
	p.y=;
	POINT p;
	p.x=;
	p.y=;
	POINT p;
	p.x=;
	p.y=;
	
	
	afficher_segment(p1,((c/3600)/10));
	afficher_segment(p2,((c/3600)%10));
	afficher_segment(p3,(((c%3600)/60)/10));
	afficher_segment(p4,(((c%3600)/60)%10));
	afficher_segment(p5,((c%60)/10));
	afficher_segment(p6,((c%60)%10));
	
}

void afficher_segment(POINT p,float c)
{
	POINT p1;
	p1.x=p.x;
	p1.y=p.y;
	POINT p2;
	p2.x=p.x+25;
	p2.y=p.y;
	POINT p3;
	p3.x=p.x;
	p3.y=p.y-25;
	POINT p4;
	p4.x=p.x+25;
	p4.y=p.y-25;
	POINT p5;
	p5.x=p.x;
	p5.y=p.y-50;
	POINT p6;
	p6.x=p.x+25;
	p6.y=p.y-50;
	
	if(c==0)
	{
		draw_line(p1,p2,blanc);
		draw_line(p2,p4,blanc);
		draw_line(p4,p6,blanc);
		draw_line(p6,p5,blanc);
		draw_line(p5,p3,blanc);
		draw_line(p3,p1,blanc);
	}
	
	if(c==1)
	{
		draw_line(p2,p4,blanc);
		draw_line(p4,p6,blanc);
	}
	
	if(c==2)
	{
		draw_line(p1,p2,blanc);
		draw_line(p2,p4,blanc);
		draw_line(p4,p3,blanc);
		draw_line(p3,p5,blanc);
		draw_line(p5,p6,blanc);
	}
	
	if(c==3)
	{
		draw_line(p1,p2,blanc);
		draw_line(p2,p4,blanc);
		draw_line(p3,p4,blanc);
		draw_line(p4,p6,blanc);
		draw_line(p5,p6,blanc);
	}
	
	if(c==4)
	{
		draw_line(p1,p3,blanc);
		draw_line(p3,p4,blanc);
		draw_line(p4,p6,blanc);
	}
	
	if(c==5)
	{
		draw_line(p2,p1,blanc);
		draw_line(p1,p3,blanc);
		draw_line(p3,p4,blanc);
		draw_line(p4,p6,blanc);
		draw_line(p6,p5,blanc);
	}
	
	if(c==6)
	{
		draw_line(p2,p1,blanc);
		draw_line(p1,p3,blanc);
		draw_line(p3,p5,blanc);
		draw_line(p5,p6,blanc);
		draw_line(p6,p4,blanc);
		draw_line(p4,p3,blanc);
	}
	
		if(c==7)
	{
		draw_line(p1,p2,blanc);
		draw_line(p2,p4,blanc);
		draw_line(p4,p6,blanc);
	}
	
		if(c==8)
	{
		draw_line(p1,p2,blanc);
		draw_line(p2,p4,blanc);
		draw_line(p4,p6,blanc);
		draw_line(p6,p5,blanc);
		draw_line(p5,p3,blanc);
		draw_line(p3,p1,blanc);
		draw_line(p3,p4,blanc);
	}
	
		if(c==9)
	{
		draw_line(p1,p2,blanc);
		draw_line(p2,p4,blanc);
		draw_line(p4,p3,blanc);
		draw_line(p3,p1,blanc);
		draw_line(p4,p6,blanc);
		draw_line(p6,p5,blanc);
	}
	
}
