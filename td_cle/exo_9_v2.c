#include "graphics.h"
#include <stdio.h>

COULEUR t1[256];
COULEUR t2[512][512];
COULEUR t3[128][128][128];

void remplir_gris()
{
	int i;
	for(i=0;i<256;i++)
	{
		t1[i]=couleur_RGB(i,i,i);
	}
}

void remplir_rouge()
{
	int i;
	for(i=0;i<256;i++)
	{
		t1[i]=couleur_RGB(i,0,0);
	}
}

void remplir_rouge_bleu()
{
	POINT p;
	int j=0;
	int i=0;
	for(i=0;i<512;i++)
	{
		for(j=0;j<512;j++)
		{
			p.x=i;p.y=j;
			t2[i][j]=couleur_RGB(i/2,0,j/2);
			draw_pixel(p,t2[i][j]);
		}
	}
}

void afficher_horizontal()
{
	int i;
	POINT p1;
	POINT p2;
	
	for(i=0;i<256;i++)
	{
		p1.x=2*i;p1.y=0;
		p2.x=p1.x+1;p2.y=HEIGHT;
		draw_rectangle(p1,p2,t1[i]);
	}
}

void afficher_vertical()
{
	int i;
	POINT p1;
	POINT p2;
	
	for(i=0;i<256;i++)
	{
		p1.x=0;p1.y=i*2;
		p2.x=WIDTH;p2.y=p1.y+1;
		draw_rectangle(p1,p2,t1[i]);
	}
}

void afficher_patron()
{
	patron_1();
	patron_2();
	patron_3();
	patron_4();
	patron_5();
	patron_6();
}

void patron_1()
{
	POINT p;
	int j=0;
	int i=0;
	for(i=0;i<256;i++)
	{
		for(j=0;j<256;j++)
		{
			p.x=i/2;p.y=j/2+128;
			t2[i][j]=couleur_RGB(0,i,255-j);
			draw_pixel(p,t2[i][j]);
		}
	}
}

void patron_2()
{
	POINT p;
	int j=0;
	int i=0;
	for(i=0;i<256;i++)
	{
		for(j=0;j<256;j++)
		{
			p.x=i/2+128;p.y=j/2+128;
			t2[i][j]=couleur_RGB(i,255,255-j);
			draw_pixel(p,t2[i][j]);
		}
	}
}

void patron_3()
{
	POINT p;
	int j=0;
	int i=0;
	for(i=0;i<256;i++)
	{
		for(j=0;j<256;j++)
		{
			p.x=i/2+(128*2);p.y=j/2+128;
			t2[i][j]=couleur_RGB(255,255-i,255-j);
			draw_pixel(p,t2[i][j]);
		}
	}
}

void patron_4()
{
	POINT p;
	int j=0;
	int i=0;
	for(i=0;i<256;i++)
	{
		for(j=0;j<256;j++)
		{
			p.x=i/2+(128*3);p.y=j/2+128;
			t2[i][j]=couleur_RGB(255-i,0,255-j);
			draw_pixel(p,t2[i][j]);
		}
	}	
}

void patron_5()
{
	POINT p;
	int j=0;
	int i=0;
	for(i=0;i<256;i++)
	{
		for(j=0;j<256;j++)
		{
			p.x=i/2+(128*2);p.y=j/2+(128*2);
			t2[i][j]=couleur_RGB(255-j,255-i,0);
			draw_pixel(p,t2[i][j]);
		}
	}
}

void patron_6()
{
	POINT p;
	int j=0;
	int i=0;
	for(i=0;i<256;i++)
	{
		for(j=0;j<256;j++)
		{
			p.x=i/2+(128*2);p.y=j/2;
			t2[i][j]=couleur_RGB(j,255-i,255);
			draw_pixel(p,t2[i][j]);
		}
	}
}







int main()
{
	init_graphics(128*4,128*3);
	
	afficher_patron();

	
	wait_escape();
	return 0;
}

