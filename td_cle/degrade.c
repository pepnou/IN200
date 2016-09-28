
#include <stdio.h>

int main()
{
	
init_graphics(600,400);
int r=255;
int v=0;
int b=0;
int d=3;



while(1)
	{	
	
	if ((r==255)&&(b!=255)&&(v==0))
		{
		b=b+d;
		}
	
	if ((r!=0)&&(b==255)&&(v==0))
		{
		r=r-d;
		}
	
	if ((r==0)&&(b==255)&&(v!=255))
		{
		v=v+d;
		}
	
	if ((v==255)&&(b!=0)&&(r==0))
		{
		b=b-d;
		}
	
	if ((r!=255)&&(v==255)&&(b==0))
		{
		r=r+d;
		}
	
	if ((r==255)&&(v!=0)&&(b==0))
		{
		v=v-d;
		}
	
	fill_screen(couleur_RGB(r,v,b));

	}

wait_escape();
exit(0);
}

