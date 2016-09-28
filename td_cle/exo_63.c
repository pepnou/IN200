#include "graphics.h"
#include <stdio.h>

int temp;
int v[20];
int i;
int j;
POINT p1;
POINT p2;

void affiche_tab()
{
	for (j=0;j<20;j++)
	{
		p1.x=100+(20*j);p1.y=50;
		p2.x=100+(20*j)+19;p2.y=50+(3*v[j]);
		draw_rectangle(p1,p2,bleu);	
	}
}

int main()
{
	init_graphics(800,500);
	
	for (i=0;i<20;i++) v[i]=alea_int(100);
	affiche_tab();

	wait_clic();
	
	i=0;
	for(i=0;i<19;i++)
	{
		if(v[i]<v[i+1])
		{
			temp=v[i];
			v[i]=v[i+1];
			v[i+1]=temp;
			i=0;
		}
		fill_screen(noir);	
		affiche_tab();
		sleep(0.75);
		
		
	}
	wait_escape();
	return 0;
}

