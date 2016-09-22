#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>


int X=900,Y=600;
int nombre_objet=2;
int score=0;
int score_vie=0;
int vie_ini=3;
int vie=3;
float vitesse=3;
int b=0;
int degrade=0;
int num_coul=0;
int coef=1;

int best_score=0;
int best_rebond=0;

int best_score_i=0;
int best_rebond_i=0;


COULEUR coul[1536];

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
		
	}while((e==1)||(f==1));
}

OBJET rebond_raquette(OBJET a,OBJET b,OBJET tab[])
{	
	if((a.py<a.ty+b.ty)&&(a.px-b.px<a.tx+b.tx)&&(a.px-b.px>-(a.tx+b.tx)))
	{
		a.vy=-a.vy;
		
		efface_score();
		score=score+(1*coef);
		score_vie=score_vie+1;
		if(score_vie>best_rebond)best_rebond=score_vie;
		
		if((score_vie%10==0)&&(vie<10))
		{
			efface_score();
			vie=vie+1;
		}
		if(score%20==0)
		{
			vitesse=vitesse-((vitesse/100)*5);
		}
		if(score%2==0)
		{
			objet_aleatoire(tab);
		}
		if(score_vie%2==0)
		{
			degrade=1;
			coef=2;
		}
	}
	return a;
}

void dessine_objet(OBJET tab[])
{
	int i;
	POINT p1;
	POINT p2;
	
	if(degrade==0)
	{
		for(i=0;i<nombre_objet;i++)
		{
			p1.x=tab[i].px-tab[i].tx;
			p1.y=tab[i].py-tab[i].ty;
			
			p2.x=tab[i].px+tab[i].tx;
			p2.y=tab[i].py+tab[i].ty;
			
			draw_fill_rectangle(p1,p2,blanc);
		}
	}
	if(degrade==1)
	{
		for(i=0;i<nombre_objet;i++)
		{
			p1.x=tab[i].px-tab[i].tx;
			p1.y=tab[i].py-tab[i].ty;
			
			p2.x=tab[i].px+tab[i].tx;
			p2.y=tab[i].py+tab[i].ty;
		
			draw_fill_rectangle(p1,p2,coul[num_coul]);
		}
		num_coul=(num_coul+3)%1536;
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
		a.px=a.px+6*p.x;
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
	int lama=5;
	
	for(i=0;i<25;i++)
	{
		p1.x=i;
		p1.y=Y-100+i;
		p2.x=X-i;
		p2.y=Y-i;
		draw_rectangle(p1,p2,couleur_RGB(200-lama*i,0,0));
		
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
	int h=0;
	int k=0;
	
	int i;
	int j;
	int g;
	
	for(i=2;i<nombre_objet;i++)
	{
		
		if(tab[i].py-tab[1].py>0) h=tab[i].py-tab[1].py;
		else h=-(tab[i].py-tab[1].py);
		
		if(tab[i].px-tab[1].px>0) k=tab[i].px-tab[1].px;
		else k=-(tab[i].px-tab[1].px);

		if((k<tab[i].tx+tab[1].tx)&&(h<tab[i].ty+tab[1].ty))
		{
			
			//rebond horizontaux
			for(j=0;j<7;j++)
			{
				for(g=0;g<2*tab[i].ty;g++)
				{
					if((k==tab[i].tx+7-j)&&(h==tab[i].ty-g)) tab[1].vx=-tab[1].vx;
				}
			}
			
			//rebond verticaux
			for(j=0;j<2*tab[i].ty;j++)
			{
				for(g=0;g<7;g++)
				{
					if((k==tab[i].tx-j)&&(h==tab[i].ty+7-g)) tab[1].vy=-tab[1].vy;
				}
			}
			
			//rebond bas gauche
			for(j=0;j<7;j++)
			{
				for(g=0;g<7;g++)
				{
					if((tab[1].px==tab[i].px-tab[i].tx-j)&&(tab[1].py==tab[i].py-tab[i].ty-g))
					{
						if(tab[1].vx>0) tab[1].vx=-tab[1].vx;
						if(tab[1].vy>0) tab[1].vy=-tab[1].vy;
					}
				}
			}
			
			
			//rebond bas droite
			for(j=0;j<7;j++)
			{
				for(g=0;g<7;g++)
				{
					if((tab[1].px==tab[i].px+tab[i].tx+j)&&(tab[1].py==tab[i].py-tab[i].ty-g))
					{
						if(tab[1].vx<0) tab[1].vx=-tab[1].vx;
						if(tab[1].vy>0) tab[1].vy=-tab[1].vy;
					}
				}
			}
			
			
			//rebond haut gauche
			for(j=0;j<7;j++)
			{
				for(g=0;g<7;g++)
				{
					if((tab[1].px==tab[i].px-tab[i].tx-j)&&(tab[1].py==tab[i].py+tab[i].ty+g))
					{
						if(tab[1].vx>0) tab[1].vx=-tab[1].vx;
						if(tab[1].vy<0) tab[1].vy=-tab[1].vy;
					}
				}
			}
			
			//rebond haut droite 
			for(j=0;j<7;j++)
			{
				for(g=0;g<7;g++)
				{
					if((tab[1].px==tab[i].px+tab[i].tx+j)&&(tab[1].py==tab[i].py+tab[i].ty+g))
					{
						if(tab[1].vx<0) tab[1].vx=-tab[1].vx;
						if(tab[1].vy<0) tab[1].vy=-tab[1].vy;
					}
				}
			}
			
			
		}
	}
	
	return tab[1];
}

void efface_all()
{
	POINT p1;
	p1.x=0;p1.y=0;
	POINT p2;
	p2.x=X;p2.y=Y;
	
	draw_fill_rectangle(p1,p2,noir);
	
}

void defaite_2(OBJET tab[])
{
		vie=vie-1;
		score_vie=0;
		degrade=0;
//		printf("nombre de vie = %d \n",vie);
		
//		efface_objet(tab);
		efface_all();
		
		bandeau();
		affiche_score();
		
		re_initialisation(tab);
		dessine_objet(tab);
		
		
		clignotter();
		
		b=0;
		
		coef=1;
}

void rebond(OBJET tab[])
{
	tab[1]=rebond_mur(tab[1]);
	tab[1]=rebond_raquette(tab[1],tab[0],tab);
	tab[1]=rebond_bloc(tab);
}

void deplacement(OBJET tab[])
{
	tab[1]=deplace_balle(tab[1]);
	tab[0]=deplace_raquette(tab[0]);
}

void affichage(OBJET tab[])
{
	POINT lama1;
	lama1.x=0;lama1.y=0;
	POINT lama2;
	lama2.x=X;lama2.y=Y;
	draw_fill_rectangle(lama1,lama2,noir);
	affiche_score();
	bandeau();
	dessine_objet(tab);
	affiche_all();
}

void game_over()
{
	POINT go;
	go.x=100;go.y=400;
	POINT go1;
	go1.x=0;go1.y=0;
	POINT go2;
	go2.x=X;go2.y=Y-100;
	
	draw_fill_rectangle(go1,go2,noir);
	aff_pol("Game Over",125,go,blanc);
	affiche_all();
}

void demarage()
{
	POINT de;
	de.x=200;de.y=350;
	POINT de1;
	de1.x=0;de1.y=0;
	POINT de2;
	de2.x=X;de2.y=Y-100;
	POINT de3;
	de3.x=400;de3.y=400;
	
	draw_fill_rectangle(de1,de2,noir);
	
	aff_pol("click here",100,de,blanc);
	affiche_all();
	wait_clic();
	draw_fill_rectangle(de1,de2,noir);
	
	aff_int(3,150,de3,blanc);
	affiche_all();
	attendre(1000);
	draw_fill_rectangle(de1,de2,noir);
	
	aff_int(2,150,de3,blanc);
	affiche_all();
	attendre(1000);
	draw_fill_rectangle(de1,de2,noir);
	
	aff_int(1,150,de3,blanc);
	affiche_all();
	attendre(1000);
	draw_fill_rectangle(de1,de2,noir);
}

void init_coul()
{
	int j=0;
	int i=0;
//	1536

	for(i=0;i<256;i++)
	{
		coul[j]=couleur_RGB(255,0,i);
		j++;
	}
	
	for(i=0;i<256;i++)
	{
		coul[j]=couleur_RGB(255-i,0,255);
		j++;
	}
	
	for(i=0;i<256;i++)
	{
		coul[j]=couleur_RGB(0,i,255);
		j++;
	}
	
	for(i=0;i<256;i++)
	{
		coul[j]=couleur_RGB(0,255,255-i);
		j++;
	}
	
	for(i=0;i<256;i++)
	{
		coul[j]=couleur_RGB(i,255,0);
		j++;
	}
	
	for(i=0;i<256;i++)
	{
		coul[j]=couleur_RGB(255,255-i,0);
		j++;
	}
	
}

int again(int a)
{
	POINT de;
	de.x=250;de.y=450;
	POINT de1;
	de1.x=0;de1.y=0;
	POINT de2;
	de2.x=X;de2.y=Y-100;
	
	POINT ag1;
	ag1.x=X/4;ag1.y=300;
	POINT ag2;
	ag2.x=(2*X/4)-10;ag2.y=100;
	POINT ag3;
	ag3.x=3*X/4;ag3.y=300;
	POINT ag4;
	ag4.x=(2*X/4)+10;ag4.y=100;
	
	POINT ag5;
	ag5.x=X/4+10;ag5.y=290;
	POINT ag6;
	ag6.x=(2*X/4)-20;ag6.y=110;
	POINT ag7;
	ag7.x=3*X/4-10;ag7.y=290;
	POINT ag8;
	ag8.x=(2*X/4)+20;ag8.y=110;
	
	POINT ag9;
	ag9.x=X/4+20;ag9.y=270;
	POINT ag10;
	ag10.x=(2*X/4)+50;ag10.y=270;
	
	draw_fill_rectangle(de1,de2,noir);
	
	aff_pol("Restart ?",100,de,blanc);
	
	draw_fill_rectangle(ag1,ag2,couleur_RGB(60,60,60));
	draw_fill_rectangle(ag5,ag6,couleur_RGB(165,0,0));
	aff_pol("Yes",100,ag9,blanc);
	
	draw_fill_rectangle(ag3,ag4,couleur_RGB(60,60,60));
	draw_fill_rectangle(ag7,ag8,couleur_RGB(165,0,0));
	aff_pol("No",100,ag10,blanc);
	
	affiche_all();
	
	POINT clic;
	
	POINT pos;
	int boucle=0;
	
	int z=0;
	int e=0;
	
	
	POINT lama1;
	lama1.x=0;lama1.y=0;
	POINT lama2;
	lama2.x=X;lama2.y=Y;
	
	
	do
	{
		clic=wait_clic();
		for(z=X/4;z<(2*X/4)-10;z++)
		{
			for(e=100;e<300;e++)
			{
				pos.x=z;pos.y=e;
				if((clic.x==pos.x)&&(clic.y==pos.y))
				{
					a=1;
					boucle=1;
				}
			}
		}
		
		for(z=(2*X/4)+10;z<3*X/4;z++)
		{
			for(e=100;e<300;e++)
			{
				pos.x=z;pos.y=e;
				if((clic.x==pos.x)&&(clic.y==pos.y))
				{
					a=0;
					boucle=1;
					draw_fill_rectangle(lama1,lama2,noir);
					affiche_all();
				}
			}
		}
		
		
		
	}while(boucle==0);
	
	vie=vie_ini;
	score=0;
	score_vie=0;

	return a;
}

void high_score()
{
	POINT de1;
	de1.x=0;de1.y=0;
	POINT de2;
	de2.x=X;de2.y=Y-100;
	
	draw_fill_rectangle(de1,de2,noir);
	
	
	if(score>best_score) best_score=score;
	
	FILE* fichier = NULL;
	
	fichier=fopen("pong_save.txt","w+");
	fprintf(fichier,"%d %d",best_score,best_rebond);
	fclose(fichier);
	
	
	POINT hs1;
	hs1.x=75;hs1.y=500;
	POINT hs2;
	hs2.x=75;hs2.y=400;
	POINT hs3;
	hs3.x=400;hs3.y=375;
	POINT hs4;
	hs4.x=400;hs4.y=325;
	POINT hs5;
	hs5.x=600;hs5.y=325;
	POINT hs6;
	hs6.x=75;hs6.y=250;
	POINT hs7;
	hs7.x=75;hs7.y=150;
	POINT hs8;
	hs8.x=400;hs8.y=125;
	POINT hs9;
	hs9.x=400;hs9.y=75;
	POINT hs10;
	hs10.x=600;hs10.y=75;
	POINT hs11;
	hs11.x=10;hs11.y=35;
	
	
	
	aff_pol("Best Score :",100,hs1,blanc);
	aff_int(best_score,100,hs2,blanc);
	
	if(best_score>best_score_i)
	{
		aff_pol("NEW BEST SCORE",50,hs3,couleur_RGB(210,205,42));
		aff_pol("Last :",50,hs4,couleur_RGB(210,205,42));
		aff_int(best_score_i,50,hs5,couleur_RGB(210,205,42));
	}
	
	aff_pol("Best Rebond :",100,hs6,blanc);
	aff_int(best_rebond,100,hs7,blanc);
	
	if(best_rebond>best_rebond_i)
	{
		aff_pol("NEW RECORD",50,hs8,couleur_RGB(210,205,42));
		aff_pol("Last :",50,hs9,couleur_RGB(210,205,42));
		aff_int(best_rebond_i,50,hs10,couleur_RGB(210,205,42));
	}
	
	aff_pol("Clic to continue",25,hs11,blanc);
	
	affiche_all();
	wait_clic();

}

void regle()
{
	POINT in1;
	in1.x=10;in1.y=Y;
	POINT in2;
	in2.x=10;in2.y=in1.y-100;
	POINT in3;
	in3.x=10;in3.y=in2.y-75;
	POINT in4;
	in4.x=10;in4.y=in3.y-40;
	POINT in5;
	in5.x=10;in5.y=in4.y-40;
	POINT in6;
	in6.x=10;in6.y=in5.y-40;
	POINT in7;
	in7.x=10;in7.y=in6.y-40;
	POINT in8;
	in8.x=10;in8.y=in7.y-40;
	POINT in9;
	in9.x=10;in9.y=in8.y-40;
	
	aff_pol("Jeu : PONG",100,in1,blanc);
	aff_pol("Information",50,in2,blanc);
	aff_pol("*A la suite de 10 rebond consecutif , la balle change de couleur et",25,in3,blanc);
	aff_pol("les point gagnes sont multiplie par deux",25,in4,blanc);
	aff_pol("*A la suite de 10 rebond consecutif , le joueur obtient une nouvelle",25,in5,blanc);
	aff_pol("vie , cela ne peut pas depasser 10 vie",25,in6,blanc);
	aff_pol("*Tout les 15 points , la vitesse de la balle augment de 5%",25,in7,blanc);
	aff_pol("*Tout les 8 points , un bloc apparait sur l ecran pour gener la balle",25,in8,blanc);
	aff_pol("*Arrive a 0 vie , la partie est termine",25,in9,blanc);
	
	
	
	
	
	
	POINT hs11;
	hs11.x=10;hs11.y=35;
	
	aff_pol("Clic to continue",25,hs11,blanc);
	
	affiche_all();
	wait_clic();
}

int main()
{
	FILE* fichier = NULL;

	init_graphics(X,Y);
	affiche_auto_off();
	
	
	int restart=0;
	OBJET tab[1000];
	
//	tab[0] raquette r;
//	tab[=1] balles b;
//	tab[>1] objet aleatoire oa;

	tab[0]=init_facile(tab[0],X/2,5,0,0,50,5);
	tab[1]=init_facile(tab[1],X/2,Y/2,alea_int(3)+2,alea_int(3)+2,5,5);
	
	init_coul();
	
	regle();
	
	
	do
	{
		fichier=fopen("pong_save.txt","r");

		if (fichier != NULL)
		{
			fscanf(fichier, "%d %d", &best_score_i, &best_rebond_i);
			fclose(fichier);
		}
		best_score=best_score_i;
		best_rebond=best_rebond_i;

		affichage(tab);
	
		demarage();

		while(vie>0)
		{
			while(b==0)
			{
				rebond(tab);
			
				efface_all();
				
				deplacement(tab);
				
				affichage(tab);
				
				b=defaite(tab[1]);
				
				attendre(vitesse);
			}
			defaite_2(tab);
		}
		game_over();
		attendre(5000);
		high_score();
		restart=again(restart);
	}while(restart==1);
	
	return 0;
}

