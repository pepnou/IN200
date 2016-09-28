#include "graphics.h"
#include <stdio.h>

float classement_tableau_decroissant_float(float tab[(int nbr)+1])
{
	int i=0;
	while(i<(nbr-2))
	{
		if(tab[i]<tab[i+1])
		{
			tab[nbr+1]=tab[i];
			tab[i]=tab[i+1];
			tab[i+1]=tab[nbr+1];
			i=0;
		}
		i++;
	}
	return tab[];
}





int main()
{
	
	
	
	
	
	
	
	
	
	
	
	wait_escape();
	return 0;
}

