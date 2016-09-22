#include "graphics.h"

int main()
{
init_graphics(600,600);

// Debut du code





//creation du plareau

fill_screen(couleur_RGB(0,148,0));

int a;

POINT p1;
POINT p2;
POINT p3;
POINT p4;
POINT p5;
POINT p6;
POINT p7;
POINT p8;
POINT centre;

for(a=0;a<8;a++)
	{
	p1.x=a*75-1;p1.y=600;
	p2.x=a*75+1;p2.y=0;
	p3.x=a*75-1;p3.y=0;
	p4.x=a*75+1;p4.y=600;
	
	p5.x=600;p5.y=a*75-1;
	p6.x=0;p6.y=a*75+1;
	p7.x=0;p7.y=a*75-1;
	p8.x=600;p8.y=a*75+1;	
	
	draw_fill_rectangle(p1,p2,noir);
	draw_fill_rectangle(p3,p4,noir);
	draw_fill_rectangle(p5,p6,noir);
	draw_fill_rectangle(p7,p8,noir);
	}


//inisialisation du plateau a 8 cases

int player=1;
int victoire=0;

int ligne,colonne;
int etage=0;
int plateau[8+2*7][8+2*7][2];

//etage 0 : etat case , vide , case noir ou case blanche 
//etage 1 : disponibilité


for(ligne=1;ligne<=22;ligne++)
	{
	for(colonne=1;colonne<=22;colonne++)
		{
		plateau[ligne][colonne][0]=0;
		}
	}
plateau[7+4][7+4][0]=1;
plateau[7+5][7+5][0]=1;
plateau[7+4][7+5][0]=2;
plateau[7+5][7+4][0]=2;

POINT clic;


while(victoire==0)
	{

	for(ligne=8;ligne<8+8;ligne++)
		{
		for(colonne=8;colonne<8+8;colonne++)
			{
			printf("plateau[ %d ", ligne-7);
			printf("][ %d ", colonne-7);
			printf("][0]= %d \n", plateau[ligne][colonne][0]);
			
			
			}
		}




	//controle de position du clic et assignation des variables

	int b;
	int c;
	int d;
	
	clic=wait_clic();
	
	printf("\033[H\033[2J");
	
	for(a=1;a<=8;a++)
		{
		b=a*75;

		if (clic.x<=b)
			{

			for(c=1;c<=8;c++)
				{
				d=600-(c*75);
			
				if(clic.y>=d)
					{
					plateau[c+7][a+7][0]=player;
					break;
					}
				}
			break;
			}
		}



	for(ligne=8;ligne<8+8;ligne++)
		{
		for(colonne=8;colonne<8+8;colonne++)
			{
			a=plateau[ligne][colonne][0];
			if (a==1)
				{
				centre.x=(37+((colonne-8)*75));
				centre.y=(600-(37+((colonne-8)*75)));
				draw_fill_circle(centre,30,blanc);

				}
			}
		}






	}


// Fin du code

wait_escape();
exit(0);
}
