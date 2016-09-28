#include "graphics.h"
#include <math.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL/SDL_ttf.h>


POINT deplace_seconde(POINT a,POINT b,float c);
POINT deplace_minute(POINT a,POINT b,float c);
POINT deplace_heure(POINT a,POINT b,float c);
void affiche_horloge(POINT a,float c);
void afficher_segment(POINT p,float c);
void gestion_bouton();
void dessine_progression(POINT p);
void draw_couronne(POINT centre,float angle,float rayon2,int epaisseur,COULEUR color);
void draw_couronne_2(POINT centre,float angle,float rayon2,int epaisseur,COULEUR color);



float depart_chrono;
float temps_tour = 0;
int rayon = 200;
int mode = -1;
int chrono_on = -1;
int tour = -1;
int co = -1;



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
	
	float temps = 0;
	
	chrono_start();
	
	
	affiche_horloge(centre,temps);
	
	while(1)
	{
		if(chrono_on == (-1))
		{
			temps = 0;
		}
		
		if(chrono_on == (1))
		{
			temps = (3600 * heure() + 60 * minute() + seconde()) - depart_chrono;
		}
		
		
		
		
		sec = deplace_seconde(sec,centre,temps);
		min = deplace_minute(min,centre,temps);
		heur = deplace_heure(heur,centre,temps);
		
		draw_line(centre,sec,rouge);
		draw_line(centre,min,bleu);
		draw_line(centre,heur,vert);
		
		
		gestion_bouton();
		
		
		affiche_all();
		
		
		
		
		affiche_horloge(centre,temps);
//		printf(" %d",mode);
		
	}
	
	wait_escape();
	return 0;
}

void gestion_bouton()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	if(event.type == SDL_MOUSEBUTTONUP)
	{
//		printf(" %d",event.button.x);
//		printf(" %d",event.button.y);
		if((event.button.x>(900-180-25))&&(event.button.x<900-25)&&(event.button.y>50)&&(event.button.y<50+80))
		{
			mode = mode * (-1);
			tour = tour * (-1);
					
			if(mode == (-1))
			{	
				chrono_on = (-1);
			}
			
		}
		if((event.button.x>(25))&&(event.button.x<25+180)&&(event.button.y>50)&&(event.button.y<50+80)&&(mode == 1))
		{
			chrono_on = chrono_on * (-1);
			depart_chrono = 3600 * heure() + 60 * minute() + seconde();
		}
		if((event.button.x>(25))&&(event.button.x<25+180)&&(event.button.y>50+80+25)&&(event.button.y<50+80+25+80)&&(mode == 1))
		{
			temps_tour = (3600 * heure() + 60 * minute() + seconde()) - depart_chrono;
		}
	}
		

}






POINT deplace_seconde(POINT a,POINT b,float c)
{
	
	double d=0;
	
	if(mode == -1)
	{
	d = (seconde()/60)*2*3.14;
	}
	
	
	if(mode == 1)
	{
		d = c;
		d = d / 60;
		d = d * 2 * 3.14;
	}
 
	
	
	a.x=b.x+(sin(d)*(rayon-((rayon*10)/100)));
	a.y=b.y+(cos(d)*(rayon-((rayon*10)/100)));
	
	return a;
}

POINT deplace_minute(POINT a,POINT b,float c)
{
	
	double d=0;
	
	if(mode == -1)
	{
		d = ((minute()+(seconde()/60))/60)*2*3.14;
	}
	
	if(mode == 1)
	{
	d = c;
	d = d / 3600;
	d = d * 2 * 3.14;
	}
	
	
	
	a.x=b.x+(sin(d)*(rayon-((rayon*20)/100)));
	a.y=b.y+(cos(d)*(rayon-((rayon*20)/100)));
	
	return a;
}

POINT deplace_heure(POINT a,POINT b,float c)
{
	
	double d=0;
	
	if(mode == -1)
	{
//		d = ((heure()+((minute()/60)))*2*3.14)/12;
		d = (((heure()*60+minute())*2*3.14)/12)/60;
	}
	
	if(mode == 1)
	{
	d = c;
	d = d / 43200;
	d = d * 2 * 3.14;
	}
		
	
	a.x=b.x+(sin(d)*(rayon-((rayon*50)/100)));
	a.y=b.y+(cos(d)*(rayon-((rayon*50)/100)));
	
	return a;
}


void affiche_horloge(POINT a,float c)
{
	fill_screen(noir);
	dessine_progression(a);
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
	

	POINT i1;
	POINT i2;
	POINT i3;
	
	i1.x = 25;
	i1.y = 550;
	
	i2.x = 25;
	i2.y = i1.y-80-25;
	
	i3.x = 900-180-25;
	i3.y = i1.y;
	
	if(mode == 1)
	{
		affiche_image_perso("chrono_start.bmp",i1,180,80,255,0,0);
		
		affiche_image_perso("chrono_tour.bmp",i2,180,80,255,0,0);
		
		affiche_image_perso("horloge.bmp",i3,180,80,255,0,0);
	}
	if(mode == -1)
	{
		affiche_image_perso("chrono.bmp",i3,180,80,255,0,0);
	}
	
	
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
	
	int b = c;
	
	if(mode == 1)
	{
	afficher_segment(p1,((b/3600)/10));
	afficher_segment(p2,((b/3600)%10));
	afficher_segment(p3,(((b%3600)/60)/10));
	afficher_segment(p4,(((b%3600)/60)%10));
	afficher_segment(p5,(((b%60)/10)));
	afficher_segment(p6,(((b%60)%10)));
	
	b = 100*c;
	
	afficher_segment(p7,((b%100)/10));
	afficher_segment(p8,((b%100)%10));
	
	
	p1.x=585;
	p2.x=p1.x+35;
	p3.x=p2.x+45;
	p4.x=p3.x+35;
	p5.x=p4.x+45;
	p6.x=p5.x+35;
	p7.x=p6.x+45;
	p8.x=p7.x+35;
	
	b = temps_tour;
	
	afficher_segment(p1,((b/3600)/10));
	afficher_segment(p2,((b/3600)%10));
	afficher_segment(p3,(((b%3600)/60)/10));
	afficher_segment(p4,(((b%3600)/60)%10));
	afficher_segment(p5,(((b%60)/10)));
	afficher_segment(p6,(((b%60)%10)));
	
	b = 100*temps_tour;
	
	afficher_segment(p7,((b%100)/10));
	afficher_segment(p8,((b%100)%10));
	
	
	
	
	
	}
	
	if(mode == -1)
	{
		afficher_segment(p1,(heure()/10));
		afficher_segment(p2,(heure()%10));
		afficher_segment(p3,(minute()/10));
		afficher_segment(p4,(minute()%10));
		b = seconde();
		afficher_segment(p5,(b/10));
		afficher_segment(p6,(b%10));
	
		b = seconde()*100;
		afficher_segment(p7,((b%100)/10));
		afficher_segment(p8,((b%100)%10));
		
	}
	
}

void afficher_segment(POINT p,float c)
{
	/*
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
	*/
	
	if(c==0)
	{
		affiche_image_perso("0.bmp",p,50,25,255,0,0);
	}
	
	if(c==1)
	{
		affiche_image_perso("1.bmp",p,50,25,255,0,0);
	}
	
	if(c==2)
	{
		affiche_image_perso("2.bmp",p,50,25,255,0,0);
	}
	
	if(c==3)
	{
		affiche_image_perso("3.bmp",p,50,25,255,0,0);
	}
	
	if(c==4)
	{
		affiche_image_perso("4.bmp",p,50,25,255,0,0);
	}
	
	if(c==5)
	{
		affiche_image_perso("5.bmp",p,50,25,255,0,0);
	}
	
	if(c==6)
	{
		affiche_image_perso("6.bmp",p,50,25,255,0,0);
	}
	
		if(c==7)
	{
		affiche_image_perso("7.bmp",p,50,25,255,0,0);
	}
	
		if(c==8)
	{
		affiche_image_perso("8.bmp",p,50,25,255,0,0);
	}
	
		if(c==9)
	{
		affiche_image_perso("9.bmp",p,50,25,255,0,0);
	}
	
}


void dessine_progression(POINT p)
{
//	POINT p1;
//	POINT p2;
	
	double d=0;
//	float i;
	
	
/*
	for(i=0;i<seconde();i = i+0.01)
	{
		d = (i/60)*2*3.14;
		
		p1.x=p.x+(sin(d)*(rayon+((rayon*5)/100)));
		p1.y=p.y+(cos(d)*(rayon+((rayon*5)/100)));
		p2.x=p.x+(sin(d)*(rayon+((rayon*10)/100)));
		p2.y=p.y+(cos(d)*(rayon+((rayon*10)/100)));
		
		draw_line(p1,p2,rouge);
	}
	
	for(i=0;i<(minute()+(seconde()/60));i = i+0.01)
	{
		d = (i/60)*2*3.14;
		
		p1.x=p.x+(sin(d)*(rayon+((rayon*10)/100)));
		p1.y=p.y+(cos(d)*(rayon+((rayon*10)/100)));
		p2.x=p.x+(sin(d)*(rayon+((rayon*15)/100)));
		p2.y=p.y+(cos(d)*(rayon+((rayon*15)/100)));
		
		draw_line(p1,p2,bleu);
	}
	
	for(i=0;i< heure() + (minute()/60) + (seconde()/3600);i = i + 0.01)
	{
		if(i<12) d = (i*2*3.14)/12;
		if(i>=12) d = ((i-12)*2*3.14)/12;
		
		
		p1.x=p.x+(sin(d)*(rayon+((rayon*15)/100)));
		p1.y=p.y+(cos(d)*(rayon+((rayon*15)/100)));
		p2.x=p.x+(sin(d)*(rayon+((rayon*20)/100)));
		p2.y=p.y+(cos(d)*(rayon+((rayon*20)/100)));
		
		draw_line(p1,p2,vert);
	}

*/
	
	d = (seconde()*2*3.14)/60;
	draw_couronne_2(p,d,rayon+15,10,rouge);
	d = ((minute()+seconde()/60)*2*3.14)/60;
	draw_couronne_2(p,d,rayon+30,10,bleu);
	if(heure() < 12)
	{
		d = ((heure() + (minute()/60) + (seconde()/3600))*2*3.14)/12;
		draw_couronne_2(p,d,rayon + 30,10,vert);
	}
	if(heure() >= 12)
	{
		d = (((heure()-12) + (minute()/60) + (seconde()/3600))*2*3.14)/12;
		draw_couronne_2(p,d,rayon + 45,10,vert);
	}
	
	
	
	
	
}

void draw_couronne(POINT centre,float angle,float rayon2,int epaisseur,COULEUR color)
{
	POINT p1;
	p1.x = centre.x;
	p1.y = centre.y + rayon2;
	
	POINT p2;
	p2.x = centre.x + sin(angle)*rayon2;
	p2.y = centre.y + cos(angle)*rayon2;
	
	POINT p3;
	p3.x = centre.x;
	p3.y = centre.y - rayon2;
	
	POINT p4;
	p4.x = centre.x - rayon2;
	p4.y = centre.y;
	
	draw_fill_circle(centre,rayon2,color);
	draw_fill_circle(centre,rayon2 - epaisseur,noir);
	

//	draw_fill_rectangle(p1,p2,noir);
//	draw_fill_triangle(centre,p1,p2,noir);
//	draw_line(centre,p2,noir);
//	draw_line(centre,p1,noir);
	
	if(centre.x - p2.x < 0)
	{
		
	}
	
	
	
	
	
}

void draw_couronne_2(POINT centre,float angle,float rayon2,int epaisseur,COULEUR color)
{
	int i;
	int j;
	int k;
	POINT p;
	POINT p2;
	
	double d;
	
	for(i=-(rayon2 + epaisseur + 20);i< rayon2 + epaisseur + 20;i++)
	{
		for(j=-(rayon2 + epaisseur + 20);j<rayon2 + epaisseur + 20;j++)
		{
			p.x = centre.x + i;
			p.y = centre.y + j;
			
			for(k=epaisseur;k>=0;k--)
			{
				p2.x = centre.x + sin(angle)*(rayon2+k);
				p2.y = centre.y + cos(angle)*(rayon2+k);
				
				d = ((p.x-centre.x)*(p.x-centre.x)) + ((p.y-centre.y)*(p.y-centre.y));
//				d = distance(p,centre);
//				d = d*d;
				
				if((d == (rayon2 + k)*(rayon2 + k))&&(p.y>=p2.y)&&(p2.x-centre.x > 0)&&(p.x-centre.x >= 0))
				{
					draw_pixel(p,color);
				}
				
				if(p2.x-centre.x < 0)
				{
					if((d == (rayon2 + k)*(rayon2 + k))&&(p.x-centre.x > 0))
					{
						draw_pixel(p,color);
					}
					if((d == (rayon2 + k)*(rayon2 + k))&&(p.y<=p2.y)&&(p.x-centre.x <= 0))
					{
						draw_pixel(p,color);
					}
				}
			}			
		}
	}
		
}
