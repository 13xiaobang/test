#include <stdio.h>
int abc[21][21][21];
int w(int a, int b , int c)
{
	if(a<=0||b<=0||c<=0)
		return 1;
	if(a>20||b>20||c>20)
	{
		abc[20][20][20] = w(20, 20, 20);
		return abc[20][20][20];
	}
	if(abc[a][b][c]!=-100)
                return abc[a][b][c];
	if(a<b&&b<c)
	{
		abc[a][b][c] = (w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c));	
		return abc[a][b][c];
	}
	abc[a][b][c] = (w(a-1,b,c)+w(a-1,b-1,c)+ w(a-1,b,c-1)-w(a-1,b-1,c-1));
	return abc[a][b][c];
}
int main()
{
	int a, b,c;
	int i,j,k;
	for(i=0;i<21;i++)
		for(j=0;j<21;j++)
			for(k = 0;k<21;k++)
				abc[i][j][k] = -100;
	while(1)
	{
		scanf("%d", &a);
		scanf("%d", &b);
		scanf("%d", &c);
		if(a==-1 && b==-1 && c==-1)
			break;
		printf("w(%d, %d, %d) = %d\r\n", a,b,c, w(a,b,c));
	}	
	return 0;
}
