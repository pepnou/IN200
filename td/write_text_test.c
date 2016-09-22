#include <stdio.h>
#include "graphics.h"

int main()
{
	init_graphics(900,600);
	
	POINT p;
	p=wait_clic();
//	write_text_2("a_ecrire",p);
//	p=wait_clic();
//	write_text_2("dfqsudvbsdebfoiwbv",p);
	aff_pol("lama",200,p,rouge);
	
	
	wait_escape();
	return 0;
}

