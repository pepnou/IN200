#include "graphics.h"
#include <stdio.h>

int X=900,Y=600;
int nombre_objet=2;
int score=0;
int score_vie=0;
int vie=3;
float vitesse=7;

struct objet
{
	int px;
	int py;
	int vx;
	int vy;
	int tx;
	int ty;
	int pxi;
	int pyi;
};

typedef struct objet OBJET;

void affiche_score()
{
	POINT p;
	
	p.x=25;p.y=Y-18;
	aff_pol("score:",50,p,blanc);
	p.x=180;p.y=Y-18;
	aff_int(score,50,p,blanc);
	
	
	p.x=330;p.y=Y-18;
	aff_pol("rebond:",50,p,blanc);
	p.x=530;p.y=Y-18;
	aff_int(score_vie,50,p,blanc);
	
	
	p.x=680;p.y=Y-18;
	aff_pol("vie:",50,p,blanc);
	p.x=780;p.y=Y-18;
	aff_int(vie,50,p,blanc);
	
	
}

void efface_score()
{
	POINT p;
	
	p.x=25;p.y=Y-18;
	aff_pol("score:",50,p,noir);
	p.x=180;p.y=Y-18;
	aff_int(score,50,p,noir);
	
	
	p.x=330;p.y=Y-18;
	aff_pol("rebond:",50,p,noir);
	p.x=530;p.y=Y-18;
	aff_int(score_vie,50,p,noir);
	
	
	p.x=680;p.y=Y-18;
	aff_pol("vie:",50,p,noir);
	p.x=780;p.y=Y-18;
	aff_int(vie,50,p,noir);
	
	
}

OBJET rebond_mur(OBJET a)
{
	if((a.px<a.tx)||(a.px>(X-a.tx)))
	{
		a.vx=-a.vx;
	}
	if(a.py>(Y-100-a.ty))
	{
		a.vy=-a.vy;
	}
	return a;
}
		
OBJET init_facile(OBJET a,int px,int py,int vx,int vy,int tx,int ty)
{
	a.px = px;
	a.py = py;
	a.vx = vx;
	a.vy = vy;
	a.tx = tx;
	a.ty = ty;
	a.pxi = a.px;
	a.pyi = a.py;
	
	return a;
}

void objet_aleatoire(OBJET tab[])
{
	int a=0;
	int g=0;
	int c=0;
	int d=0;
	int e=0;
	int f=0;
	
	
	nombre_objet=nombre_objet+1;
	do
	{
		
		tab[nombre_objet-1]=init_facile(tab[nombre_objet-1],alea_int(X),alea_int(250)+200,0,0,alea_int(40)+10,alea_int(40)+10);
		
		if((tab[1].px-tab[nombre_objet-1].px<tab[1].tx+tab[nombre_objet-1].tx)&&(tab[1].px-tab[nombre_objet-1].px>-(tab[1].tx+tab[nombre_objet-1].tx))) a=1;
		else a=0;
		if((tab[1].py-tab[nombre_objet-1].py<tab[1].ty+tab[nombre_objet-1].ty)&&(tab[1].py-tab[nombre_objet-1].py>-(tab[1].ty+tab[nombre_objet-1].ty))) g=1;
		else g=0;
		
		if((tab[1].pxi-tab[nombre_objet-1].px<tab[1].tx+tab[nombre_objet-1].tx)&&(tab[1].pxi-tab[nombre_objet-1].px>-(tab[1].tx+tab[nombre_objet-1].tx))) c=1;
		else c=0;
		if((tab[1].pyi-tab[nombre_objet-1].py<tab[1].ty+tab[nombre_objet-1].ty)&&(tab[1].pyi-tab[nombre_objet-1].py>-(tab[1].ty+tab[nombre_objet-1].ty))) d=1;
		else d=0;
		
		if((a==1)&&(g==1)) e=1;
		else e=0;
		if((c==1)&&(d==1)) f=1;
		else f=0;
		
//		printf("a= %d \n",a);
//		printf("b= %d \n",b);
//		printf("c= %d \n",c);
//		printf("d= %d \n",d);
//		printf("e= %d \n",e);
//		printf("f= %d \n",f);
		
//		wait_clic();
	}while((e==1)||(f==1));
}

OBJET rebond_raquette(OBJET a,OBJET b,OBJET tab[])
{	
	if((a.py<a.ty+b.ty)&&(a.px-b.px<a.tx+b.tx)&&(a.px-b.px>-(a.tx+b.tx)))
	{
		a.vy=-a.vy;
		
		efface_score();
		score=score+1;
		score_vie=score_vie+1;
		affiche_score();
		printf("score = %d \n",score);
		
		if(score_vie%10==0)
		{
			efface_score();
			vie=vie+1;
			printf("nombre de vie = %d \n",vie);
			affiche_score();
		}
		if(score%20==0)
		{
			vitesse=vitesse-((vitesse/100)*20);
		}
		if(score%5==0)
		{
			objet_aleatoire(tab);
			a.py=a.py+5;
		}
	}
	return a;
}

void dessine_objet(OBJET tab[])
{
	int i;
	POINT p1;
	POINT p2;
	
	for(i=0;i<nombre_objet;i++)
	{
		p1.x=tab[i].px-tab[i].tx;
		p1.y=tab[i].py-tab[i].ty;
		
		p2.x=tab[i].px+tab[i].tx;
		p2.y=tab[i].py+tab[i].ty;
		
		draw_fill_rectangle(p1,p2,blanc);
	}
}

void efface_objet(OBJET tab[])
{
	int i;
	POINT p1;
	POINT p2;
	
	for(i=0;i<nombre_objet;i++)
	{
		p1.x=tab[i].px-tab[i].tx;
		p1.y=tab[i].py-tab[i].ty;
		
		p2.x=tab[i].px+tab[i].tx;
		p2.y=tab[i].py+tab[i].ty;
		
		draw_fill_rectangle(p1,p2,noir);
	}
}

OBJET deplace_balle(OBJET a)
{
	a.px=a.px+a.vx;
	a.py=a.py+a.vy;
	
	return a;
}

OBJET deplace_raquette(OBJET a)
{
	POINT p;
	p=get_arrow();
	
	a.px=a.px+5*p.x;
	
	return a;
}

int defaite(OBJET a)
{
	if(a.py<-a.ty)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void bandeau()
{
	POINT p1;
	POINT p2;
	int i;
	int coef=5;
	
	for(i=0;i<25;i++)
	{
		p1.x=i;
		p1.y=Y-100+i;
		p2.x=X-i;
		p2.y=Y-i;
		draw_rectangle(p1,p2,couleur_RGB(200-coef*i,0,0));
		
	}
}

void clignotter()
{
	int i;
	POINT p;
	
	for(i=0;i<5;i++)
	{
		p.x=680;p.y=Y-18;
		aff_pol("vie:",50,p,rouge);
		p.x=780;p.y=Y-18;
		aff_int(vie,50,p,rouge);
		affiche_all();
		
		attendre(500);
		
		p.x=680;p.y=Y-18;
		aff_pol("vie:",50,p,blanc);
		p.x=780;p.y=Y-18;
		aff_int(vie,50,p,blanc);
		affiche_all();
		
		attendre(500);
	}
}

void re_initialisation(OBJET tab[])
{
	int i;
	for(i=0;i<nombre_objet;i++)
	{
		tab[i].px=tab[i].pxi;
		tab[i].py=tab[i].pyi;
		tab[i].vy=-tab[i].vy;
	}
}

OBJET rebond_bloc(OBJET tab[])
{
//	int h=0;
//	int k=0;
	
//	int i;
//	for(i=2;i<nombre_objet;i++)
//	{
//		if((tab[i].py-tab[1].py<tab[i].ty+tab[1].ty)&&(tab[i].py-tab[1].py>-(tab[i].ty+tab[1].ty))&&((tab[i].px-tab[1].px<tab[i].tx+tab[1].tx)&&(tab[i].px-tab[1].px>-(tab[i].tx+tab[1].tx))))
//		{
//			if(tab[i].py-tab[1].py>0) h=tab[i].py-tab[1].py;
//			else h=-(tab[i].py-tab[1].py);
//			if(tab[i].px-tab[1].px>0) h=tab[i].px-tab[1].px;
//			else k=-(tab[i].px-tab[1].px);
			
//			if(tab[1].tx+tab[i].tx-k<tab[1].ty+tab[i].ty-h) tab[i].vx=-tab[i].vx;
//			else tab[i].vy=-tab[i].vy;
			
			
//		}
//	}
	
	return tab[1];
}




int main()
{

	init_graphics(X,Y);
	affiche_auto_off();
	
	
	OBJET tab[1000];
	
//	tab[0] raquette r;
//	tab[>=1] balles b;
//	tab[>=9665] objet aleatoire oa;

	tab[0]=init_facile(tab[0],X/2,5,0,0,50,5);
	tab[1]=init_facile(tab[1],X/2,Y/2,alea_int(3)+2,alea_int(3)+2,5,5);
	
	printf("%d \n",tab[0].px);
	
	affiche_score();
	bandeau();
	dessine_objet(tab);
	affiche_all();
	
	attendre(5000);
	
	int b=0;
	POINT go;
	go.x=100;go.y=400;
	
	while(vie>0)
	{
		
		
		while(b==0)
		{
			bandeau();

			tab[1]=rebond_mur(tab[1]);
			tab[1]=rebond_raquette(tab[1],tab[0],tab);
			tab[1]=rebond_bloc(tab);
			
			efface_objet(tab);
			
			tab[1]=deplace_balle(tab[1]);
			tab[0]=deplace_raquette(tab[0]);

			dessine_objet(tab);
			
			affiche_all();
			b=defaite(tab[1]);

			attendre(vitesse);

		}
		efface_score();
		vie=vie-1;
		score_vie=0;
		printf("nombre de vie = %d \n",vie);
		affiche_score();
		
		efface_objet(tab);
		
		re_initialisation(tab);
		
		dessine_objet(tab);
		
		b=0;
		
		clignotter();
		
		
	}
	
	
	aff_pol("Game Over",125,go,blanc);
	affiche_all();
	
	wait_escape();
	return 0;
}

