#include <stdio.h>
#define DIS ('1' -1)
char _add(char a, char b)
{
	int n_a = a - DIS;
	int n_b = b - DIS;
	n_a = (n_a+n_b)%10;
	return (n_a+DIS);
}

void add_str(char *input, char *output)
{
	while(*input!='\0')
	{
		*output = _add(*input,*output);
		output++;
		input++;
	}
	*output ='\0';
}
int main()
{
	char t[20];
	char a[20];
	int i;
	for(i = 0;i<20;i++)
	{
		a[i] = '0';
	}
	while(scanf("%s",t)==1) 
	{
			add_str(t,a);
	}
	printf("%s\r\n", a);
	return 0;
}

