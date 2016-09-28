#include "graphics.h"
#include <math.h>
#include <stdio.h>
#include <SDL.h>


POINT deplace_seconde(POINT a,POINT b,float c);
POINT deplace_minute(POINT a,POINT b,float c);
POINT deplace_heure(POINT a,POINT b,float c);
void affiche_horloge(POINT a,float c);
void afficher_segment(POINT p,float c);
void chronometre();

int rayon = 200;
int mode = 1;



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
	chrono_start();
	
	
	
	
	affiche_horloge(centre,chrono_val());
	
	while(1)
	{
		
		sec = deplace_seconde(sec,centre,chrono_val());
		min = deplace_minute(min,centre,chrono_val());
		heur = deplace_heure(heur,centre,chrono_val());
		
		draw_line(centre,sec,rouge);
		draw_line(centre,min,bleu);
		draw_line(centre,heur,vert);
		
		
		chronometre();
		
		
		affiche_all();
		



		if(conteur == 216000)
		{
			conteur = 0;
		}
		conteur++;
		affiche_horloge(centre,chrono_val());
		
	}
	
	wait_escape();
	return 0;
}

void chronometre()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	if(event.type == SDL_MOUSEBUTTONDOWN)
	{
		
	}
	
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
	
	a.x=b.x+(sin(d)*(rayon-((rayon*10)/100)));
	a.y=b.y+(cos(d)*(rayon-((rayon*10)/100)));
	
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
	
	a.x=b.x+(sin(d)*(rayon-((rayon*20)/100)));
	a.y=b.y+(cos(d)*(rayon-((rayon*20)/100)));
	
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
	
	a.x=b.x+(sin(d)*(rayon-((rayon*50)/100)));
	a.y=b.y+(cos(d)*(rayon-((rayon*50)/100)));
	
	return a;
}


void affiche_horloge(POINT a,float c)
{
	fill_screen(noir);
	draw_circle(a,rayon,blanc);
	
	
	POINT h1;
	POINT h2;
	int i;
	double d;
	
	for(i=0;i<12;i++)
	{
		d = sin((i*2*3.14)/12)*rayon;
		h1.x = a.x + d;
		
		d = cos((i*2*3.14)/12)*rayon;
		h1.y = a.y + d;
		
		d = sin((i*2*3.14)/12)*(rayon-15);
		h2.x = a.x + d;
		
		d = cos((i*2*3.14)/12)*(rayon-15);
		h2.y = a.y + d;
		
		draw_line(h1,h2,blanc);
	}
	
	for(i=0;i<60;i++)
	{
		d = sin((i*2*3.14)/60)*rayon;
		h1.x = a.x + d;
		
		d = cos((i*2*3.14)/60)*rayon;
		h1.y = a.y + d;
		
		d = sin((i*2*3.14)/60)*(rayon-5);
		h2.x = a.x + d;
		
		d = cos((i*2*3.14)/60)*(rayon-5);
		h2.y = a.y + d;
		
		draw_line(h1,h2,blanc);
	}
	
	int b = c;
	
	POINT p1;
	p1.x=10;
	p1.y=60;
	POINT p2;
	p2.x=p1.x+35;
	p2.y=p1.y;
	POINT p3;
	p3.x=p2.x+45;
	p3.y=p1.y;
	POINT p4;
	p4.x=p3.x+35;
	p4.y=p1.y;
	POINT p5;
	p5.x=p4.x+45;
	p5.y=p1.y;
	POINT p6;
	p6.x=p5.x+35;
	p6.y=p1.y;
	POINT p7;
	p7.x=p6.x+45;
	p7.y=p1.y;
	POINT p8;
	p8.x=p7.x+35;
	p8.y=p1.y;
	
	
	
	
	afficher_segment(p1,((b/3600)/10));
	afficher_segment(p2,((b/3600)%10));
	afficher_segment(p3,(((b%3600)/60)/10));
	afficher_segment(p4,(((b%3600)/60)%10));
	afficher_segment(p5,(((b%60)/10)));
	afficher_segment(p6,(((b%60)%10)));
	
	b = 100*c;
	afficher_segment(p7,((b%100)/10));
	afficher_segment(p8,((b%100)%10));
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
