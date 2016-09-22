#include "graphics.h"

int main()
{
int distance;
int stop=0;
int z;
int plateau[100][100][2];
int a=5;
int c=5;


while(stop==0)
	{
	if ((plateau[a+7][c+7][0]!=plateau[a+7][c+7-1][0])&&(plateau[a+7][c+7-1][0]!=0))
		{
		for (distance=2;distance<8;distance++)
			{
			if(plateau[a+7][c+7-distance][0]!=0)
				{
				if(plateau[a+7][c+7-distance][0]==plateau[a+7][c+7][0])
					{
					for(z=1;z<distance;z++)
						{
						plateau[a+7][c+7-z][0]=plateau[a+7][c+7][0];
						}
					}
				else
				stop=1;

				}
			else
			stop=1;
			}
		}
	else
	stop=1;
	}
stop=0;

wait_escape();
exit(0);
}
