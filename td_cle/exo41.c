#include "graphics.h"
#include <stdio.h>

int main()
{
	init_graphics(900,600);
	POINT p;
	POINT p1;
	POINT p2;
	POINT p3;
	POINT p4;
	int a;
	p1.x=300;p1.y=0;
	p2.x=300;p2.y=600;
	draw_line(p1,p2,blanc);
	p3.x=600;p3.y=0;
	p4.x=600;p4.y=600;
	draw_line(p3,p4,blanc);
	int ble=0;
	int bla=0;
	int rou=0;
	

	POINT r1;
	POINT r2;
	POINT r3;
	POINT r4;
	POINT r5;
	POINT r6;
	r1.x=0;r1.y=0;
	r2.x=299;r2.y=600;
	r3.x=301;r3.y=0;
	r4.x=599;r4.y=600;
	r5.x=601;r5.y=0;
	r6.x=900;r6.y=600;
	
	
	for(a=0;a<20;a++)
	{
		p=wait_clic();
		if(p.x<300)
		{
			if(ble==0)
			{
				draw_fill_rectangle(r1,r2,bleu);
				ble=1;
			}
			else
			{
				draw_fill_rectangle(r1,r2,noir);
				ble=0;
			}
		}
		if((p.x<600)&&(p.x>300))
		{
			if(bla==0)
			{
				draw_fill_rectangle(r3,r4,blanc);
				bla=1;
			}
			else
			{
				draw_fill_rectangle(r3,r4,noir);
				bla=0;
			}
		}
		if(p.x>600)
		{
			if(rou==0)
			{
				draw_fill_rectangle(r5,r6,rouge);
				rou=1;
			}
			else
			{
				draw_fill_rectangle(r5,r6,noir);
				rou=0;
			}
		}
	}
	
	
	
	
	
	
	
	
	
	
	return 0;
}

