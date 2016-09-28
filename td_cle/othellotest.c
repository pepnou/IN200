
int i,j,k,l;






for(i=1;i<8+1;i++)
	{
	for(j=1;j<8+1;j++)
		{
		for (k=0;k<=7;k++)
			{
			for(l=0;l<=7;l++)
				{




				if ((plateau[i][j]!=0)&&(plateau[i][j]!=plateau[i+k][j+l])&&(plateau[i][j]!=plateau[i-k][j-l])&&(plateau[i+k][j+l]!=0)&&(plateau[i-k][j-l]!=0)&&((k-l==0)||(k-l==(-l))||(k-l==k))
		




				}
			}
		}
	}







for(i=1;i<8+1;i++)
	{
	for(j=1;j<8+1;j++)
		{

		if ((plateau[i][j]==plateau[i-1][j]+plateau[i+1][j])&&(plateau[i+1][j]==plateau[i-1][j])||(plateau[i][j]==((plateau[i-1][j]+plateau[i+1][j])/4)))
			{
			plateau[i][j]=plateau[i-1][j];
			}


		if ((plateau[i][j]==plateau[i][j-1]+plateau[i][j+1])&&(plateau[i][j-1]==plateau[i][j+1])||(plateau[i][j]==((plateau[i][j-1]+plateau[i][j+1])/4)))
			{
			plateau[i][j]=plateau[i-1][j];
			}
	

		if ((plateau[i][j]==plateau[i-1][j-1]+plateau[i+1][j+1])&&(plateau[i+1][j+1]==plateau[i-1][j-1])||(plateau[i][j]==((plateau[i-1][j-1]+plateau[i+1][j+1])/4)))
			{
			plateau[i][j]=plateau[i-1][j];
			}
	

		if ((plateau[i][j]==plateau[i-1][j+1]+plateau[i+1][j-1])&&(plateau[i+1][j-1]==plateau[i-1][j+1])||(plateau[i][j]==((plateau[i-1][j+1]+plateau[i+1][j-1])/4)))
			{
			plateau[i][j]=plateau[i-1][j];
			}
		}
	}

