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


void dessinne_patron_v2()
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
	
	for(i=0;i<256;i++)
	{
		for(j=0;j<256;j++)
		{
			p.x=i/2+128;p.y=j/2+128;
			t2[i][j]=couleur_RGB(i,255,255-j);
			draw_pixel(p,t2[i][j]);
		}
	}
	
	for(i=0;i<256;i++)
	{
		for(j=0;j<256;j++)
		{
			p.x=i/2+(128*2);p.y=j/2+128;
			t2[i][j]=couleur_RGB(255,255-i,255-j);
			draw_pixel(p,t2[i][j]);
		}
	}
	
	for(i=0;i<256;i++)
	{
		for(j=0;j<256;j++)
		{
			p.x=i/2+(128*3);p.y=j/2+128;
			t2[i][j]=couleur_RGB(255-i,0,255-j);
			draw_pixel(p,t2[i][j]);
		}
	}	
	
	for(i=0;i<256;i++)
	{
		for(j=0;j<256;j++)
		{
			p.x=i/2+(128*2);p.y=j/2+(128*2);
			t2[i][j]=couleur_RGB(255-j,255-i,0);
			draw_pixel(p,t2[i][j]);
		}
	}
	
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

int changement_rouge(COULEUR c1,COULEUR c2)
{
	int a;
	int b;
	a=c1/(0x10000);
	b=c2/(0x10000);
	if((a-b)==0) return 0;
	if((a-b)>0) return 1;
	if((a-b)<0) return -1;
}

int changement_vert(COULEUR c1,COULEUR c2)
{
	int a;
	int b;
	a=(c1%(0x10000))/0x100;
	b=(c2%(0x10000))/0x100;
	
	
	if((a-b)==0) return 0;
	if((a-b)>0) return 1;
	if((a-b)<0) return -1;
}

int changement_bleu(COULEUR c1,COULEUR c2)
{
	int a;
	int b;
	a=c1%(0x100);
	b=c2%(0x100);
	if((a-b)==0) return 0;
	if((a-b)>0) return 1;
	if((a-b)<0) return -1;
}

void degrade(POINT p,COULEUR bg,COULEUR bd,COULEUR hg,COULEUR hd)
{
	POINT pi;
	
	int j=0;
	int i=0;
	
	
	int rgd;
	int vgd;
	int bgd;
	
	int rbh;
	int vbh;
	int bbh;
	
	
	rgd=changement_rouge(bg,bd);
	rbh=changement_rouge(bg,bd);
	
	vgd=changement_vert(bg,bd);
	vbh=changement_vert(bg,bd);
	
	bgd=changement_bleu(bg,bd);
	bbh=changement_bleu(bg,bd);
	
	int ri=bg/(0x10000);
	int vi=(bg%(0x10000))/(0x100);
	int bi=bg%(0x100);
	
	
	
	for(i=0;i<256;i++)
	{
		for(j=0;j<256;j++)
		{
			pi.x=p.x+(i/2);pi.y=p.y+(j/2);
			t2[i][j]=couleur_RGB(ri+rgd*i+rbh*j,vi+vgd*i+vbh*j,bi+bgd*i+bbh*j);
			draw_pixel(pi,t2[i][j]);
		}
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


int main()
{
	init_graphics(128*4,128*3);
	POINT p;
	p=wait_clic();
	
	degrade(p,couleur_RGB(0,255,255),couleur_RGB(0,0,0),couleur_RGB(0,0,255),couleur_RGB(0,0,0));

	
	wait_escape();
	return 0;
}

