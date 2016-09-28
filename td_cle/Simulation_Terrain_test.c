#include "graphics.h"
#include <stdio.h>

#define largeur 190
#define hauteur 100
#define cote 7
#define duree 0

#define nombre_de_lac 12
#define probabilite_propagation_eau 25
#define probabilite_propagation_plante 10
#define probabilite_depart_plante 50
#define probabilite_propagation_humidite 25
#define probabilite_evaporation 25
#define probabilite_propagation_feu 50
#define probabilite_depart_feu 1  /*Pour 10 Mille*/
#define probabilite_fin_feu 50
#define probabilite_pousse_arbre 15
#define probabilite_cendre_froide 10


/*

Terre : Marron
1
Terre hydratée : marron foncé
2
foret : Vert
3
Pousse d'arbre : vert clair
4
Pousse d'arbre seche : vert-jaune
5
Eau : Bleu
6
Feu intense : Rouge
7
Feu peu intense : orange
8
Cendres chaudes : Gris
9
Cendres froides : Noir
10

*/

void initialisation_tableau(int tab[largeur+2][hauteur+2]);
void ajout_eau(int tab[largeur+2][hauteur+2]);
void propagation_eau(int tab[largeur+2][hauteur+2]);
void dessine_terrain(int tab[largeur+2][hauteur+2]);
void tempete(int tab[largeur+2][hauteur+2]);

void gestion_etat(int tab[largeur+2][hauteur+2]);

int regarder_autour(int tab[largeur+2][hauteur+2],int i,int j,int verif);

int main()
{
	init_graphics(largeur*cote,hauteur*cote);
	affiche_auto_off();

	
	int etat[largeur+2][hauteur+2];
	initialisation_tableau(etat);
	
	ajout_eau(etat);
	propagation_eau(etat);
	
//	dessine_terrain(etat);
//	attendre(1000);
	
	while(1)
	{
		gestion_etat(etat);
		
		tempete(etat);
		
		dessine_terrain(etat);
		attendre(duree);
	}
	
	wait_escape();
	return 0;
}

void tempete(int tab[largeur+2][hauteur+2])
{
	int i,j,x,y;
	int a = 1;
	for(i=1;i<largeur+1;i++)
	{
		for(j=1;j<hauteur+1;j++)
		{
//			printf("tab[i][j]=%d\n",tab[i][j]);
			if((tab[i][j] != 3)&&(tab[i][j] != 6)) a = 0;
		}
	}
	
//	printf("a=%d\n",a);
	
	for(i=1;i<largeur+1;i++)
	{
		for(j=1;j<hauteur+1;j++)
		{
			while(a == 1)
			{
				x=alea_int(largeur)+1;
				y=alea_int(hauteur)+1;
				if(tab[x][y] == 3) 
				{
					tab[x][y] = 7;
					a = 0;
				}
			}
		}
	}
}

void initialisation_tableau(int tab[largeur+2][hauteur+2])
{
	int i,j;
	
	for(i=0;i<largeur+2;i++)
	{
		for(j=0;j<hauteur+2;j++)
		{
			tab[i][j] = 1;
		}
	}
}

void dessine_terrain(int tab[largeur+2][hauteur+2])
{
	POINT p1,p2;
	int i,j;
	
	for(i=1;i<largeur+1;i++)
		{
		for(j=1;j<hauteur+1;j++)
		{
			p1.x=(i-1)*cote;p1.y=(j-1)*cote;
			p2.x=i*cote;p2.y=j*cote;
			
			switch(tab[i][j])
			{
				case 1 : draw_fill_rectangle(p1,p2,couleur_RGB(160,111,0)); break ;
				case 2 : draw_fill_rectangle(p1,p2,couleur_RGB(100,69,0)); break ;
				case 3 : draw_fill_rectangle(p1,p2,couleur_RGB(0,142,0)); break ;
				case 4 : draw_fill_rectangle(p1,p2,couleur_RGB(0,170,0)); break ;
				case 5 : draw_fill_rectangle(p1,p2,couleur_RGB(176,206,0)); break ;
				case 6 : draw_fill_rectangle(p1,p2,couleur_RGB(0,186,255)); break ;
				case 7 : draw_fill_rectangle(p1,p2,couleur_RGB(255,72,0)); break ;
				case 8 : draw_fill_rectangle(p1,p2,couleur_RGB(255,163,0)); break ;
				case 9 : draw_fill_rectangle(p1,p2,couleur_RGB(145,145,145)); break ;
				case 10: draw_fill_rectangle(p1,p2,couleur_RGB(77,77,77)); break ;
			}
		}
	}
	affiche_all();
}

void ajout_eau(int tab[largeur+2][hauteur+2])
{
	int a,b,c;
	
	for(a=0;a<nombre_de_lac;a++)
	{
		b = alea_int(largeur)+1;
		c = alea_int(hauteur)+1;
		
		tab[b][c] = 6;
	}
}

void propagation_eau(int tab[largeur+2][hauteur+2])
{
	int i,j,k,a;
	
//	for(k=0;k<(largeur*hauteur)/104;k++)
	for(k=0;k<11;k++)
	{
		for(i=1;i<largeur+1;i++)
		{
			for(j=1;j<hauteur+1;j++)
			{
				a=alea_int(101);
//				printf("%d\n",a);
				
				switch(regarder_autour(tab,i,j,6))
				{
					case 1 : if(a+2>(100-probabilite_propagation_eau)) tab[i][j] = 6; break;
					case 2 : if(a+3>(100-probabilite_propagation_eau)) tab[i][j] = 6; break;
					case 3 : if(a+4>(100-probabilite_propagation_eau)) tab[i][j] = 6; break;
					case 4 : if(a+5>(100-probabilite_propagation_eau)) tab[i][j] = 6; break;
				}
			}
		}
	}
}

void gestion_etat(int tab[largeur+2][hauteur+2])
{
	int i,j,a;
	
	for(i=1;i<largeur+1;i++)
	{
		for(j=1;j<hauteur+1;j++)
		{
			a=alea_int(101);
			
			switch(tab[i][j])
			{
				
				case 1 :
				if((regarder_autour(tab,i,j,3)>0)||(regarder_autour(tab,i,j,4)>0))
				{
					if((regarder_autour(tab,i,j,2)>0)||(regarder_autour(tab,i,j,6)>0))
					{
						if(a+10>(100-probabilite_propagation_plante))
						{
							tab[i][j] = 4;
						}
					}
					else
					{
						if(a>(100-probabilite_propagation_plante))
						{
							tab[i][j] = 4;
						}
					}
					
				}
				else
				{
					if(regarder_autour(tab,i,j,6)>0)
					{
						if(a>(100-probabilite_propagation_humidite))
						{
							tab[i][j] = 2;
						}
					}
				}
				break;
				
				case 2 :
				if((regarder_autour(tab,i,j,7)>0)||(regarder_autour(tab,i,j,8)>0))
				{
					if((regarder_autour(tab,i,j,2)>0)||(regarder_autour(tab,i,j,6)>0))
					{
						if(a-5>(100-probabilite_evaporation))
						{
							tab[i][j] = 1;
						}
					}
					else
					{
						if(a>(100-probabilite_evaporation))
						{
							tab[i][j] = 1;
						}
					}
				}
				else
				{
					if((regarder_autour(tab,i,j,3)>0)||(regarder_autour(tab,i,j,4)>0))
					{
						if((regarder_autour(tab,i,j,2)>0)||(regarder_autour(tab,i,j,6)>0))
						{
							if(a+10>(100-probabilite_propagation_plante))
							{
								tab[i][j] = 4;
							}
						}
						else
						{
							if(a>(100-probabilite_propagation_plante))
							{
								tab[i][j] = 4;
							}
						}
						
					}
					else
					{
						if((a>(100-probabilite_depart_plante+15))&&(regarder_autour(tab,i,j,7) == 0)&&(regarder_autour(tab,i,j,8) == 0))
							{
								tab[i][j] = 4;
							}
					}
				}
				break;
				
				case 3 :
				if((regarder_autour(tab,i,j,7)>0)||(regarder_autour(tab,i,j,8)>0))
				{
					if((regarder_autour(tab,i,j,2)>0)||(regarder_autour(tab,i,j,6)>0))
					{
						if(a-5>(100-probabilite_propagation_feu))
						{
							tab[i][j] = 7;
						}
					}
					else
					{
						if(a>(100-probabilite_propagation_feu))
						{
							tab[i][j] = 7;
						}
					}
				}
				break;
				
				case 4 :
				if((regarder_autour(tab,i,j,7)>0)||(regarder_autour(tab,i,j,8)>0))
				{
					if((regarder_autour(tab,i,j,2)>0)||(regarder_autour(tab,i,j,6)>0))
					{
						if(a-45>(100-probabilite_propagation_feu))
						{
							tab[i][j] = 8;
						}
					}
					else
					{
						if(a>(100-probabilite_propagation_feu))
						{
							tab[i][j] = 8;
						}
					}
				}
				else
				{
					a=alea_int(101);
					if(a>(100-probabilite_pousse_arbre))
					{
						tab[i][j] = 3;
					}
					else
					{
						a=alea_int(10001);
						if(a>(10000-probabilite_depart_feu))
						{
							tab[i][j] = 8;
						}
					}
				}
				
				break;
				
				case 7 :
				if((regarder_autour(tab,i,j,3) == 0)&&(regarder_autour(tab,i,j,4) == 0))
				{
					if(a>(100-probabilite_fin_feu+30))
					{
						tab[i][j] = 8;
					}
					
				}
				
				break;
				
				case 8 :
				if((regarder_autour(tab,i,j,3) == 0)&&(regarder_autour(tab,i,j,4) == 0))
				{
					if(a>(100-probabilite_fin_feu))
					{
						tab[i][j] = 9;
					}
					
				}
				
				break;
				
				case 9 :
				if((regarder_autour(tab,i,j,7) == 0)&&(regarder_autour(tab,i,j,8) == 0))
				{
					if((regarder_autour(tab,i,j,6) > 0)&&(regarder_autour(tab,i,j,2) > 0))
					{
						if(a>(100-probabilite_cendre_froide-20))
						{
							tab[i][j] = 10;
						}
					}
					else
					{
						if(a>(100-probabilite_cendre_froide))
						{
							tab[i][j] = 10;
						}
					}
				}
				
				break;
				
				case 10 :
				
				
				if((regarder_autour(tab,i,j,3)>0)||(regarder_autour(tab,i,j,4)>0))
				{
					if((regarder_autour(tab,i,j,2)>0)||(regarder_autour(tab,i,j,6)>0))
					{
						if(a>(100-probabilite_propagation_plante+4))
						{
							tab[i][j] = 4;
						}
					}
					else
					{
						if(a>(100-probabilite_propagation_plante+9))
						{
							tab[i][j] = 4;
						}
					}
						
				}
				else
				{
					a=alea_int(101);
					if((a-40>(100-probabilite_depart_plante))&&(regarder_autour(tab,i,j,7) == 0)&&(regarder_autour(tab,i,j,8) == 0)&&(regarder_autour(tab,i,j,9) == 0))
						{
							tab[i][j] = 4;
						}
				}
				
				break;
			}
//			dessine_terrain(tab);
//			attendre(duree);
		}
	}
}



/*
void gestion_terre_humide(int tab[largeur+2][hauteur+2])
{
	int i,j,a;
	
	for(i=1;i<largeur+1;i++)
	{
		for(j=1;j<hauteur+1;j++)
		{
			a=alea_int(101);
				
			if((regarder_autour(tab,i,j,6)>0)&&(tab[i][j] == 1))
			{
					
					
					
					
					
					
			}
		}
	}
}

*/



















int regarder_autour(int tab[largeur+2][hauteur+2],int i,int j,int verif)
{
	int a;
	a=0;
	
	if(tab[i+1][j] == verif ) a=a+1;
	if(tab[i-1][j] == verif ) a=a+1;
	if(tab[i][j+1] == verif ) a=a+1;
	if(tab[i][j-1] == verif ) a=a+1;
	
	return a;
}





