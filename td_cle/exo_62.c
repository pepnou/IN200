#include "graphics.h"
#include <stdio.h>

int tab[20];
int temp;

void alea_tab()
{
	int i;
	for(i=0;i<20;i++)
	{
		tab[i]=alea_int(100);
	}
}





int main()
{
	alea_tab();
	
	
	
	
	return 0;
}

