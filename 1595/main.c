#include <stdio.h>
int is_prime(int value)
{
	int i;
	if(value<=2)
		return 1;
	for(i = 2; i<value; i++)
	{
		if((value%i) == 0)
			return 0;
	}
	return 1;
}
int main()
{
	int prime[500];
	int i;
	int * cur = prime;
	int num;
	int a, b;
	for(i = 1; i<1200;i++)
	{
		if(is_prime(i))
		{
			*cur++ = i;
		}
	}
	while(scanf("%d%d", &a, &b)==2)
	{
		num = 0;
		for(i = 0; ; i++)
		{
			if(prime[i]>a)
				break; 
			num++;
		}
		printf("%d %d:", a, b);
		if((num%2)==1)
		{
			if(num/2-b+1<0)
			{
				for(i = 0; i<num; i++)
					printf(" %d",prime[i]);
			}
			else
				for(i = num/2-b+1; i<=num/2+b-1; i++)
					printf(" %d",prime[i]);
		}
		else
		{
			
			if(num/2-b<0)
			{
				for(i = 0; i<num; i++)
					printf(" %d",prime[i]);
			}
			else
				for(i = num/2-b; i<=num/2+b-1; i++)
					printf(" %d",prime[i]);
		}
		printf("\r\n\r\n");
	}
	return 0;
}
