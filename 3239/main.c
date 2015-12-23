#include <stdio.h>
static int res[400] = {0};
int LEN, COUNT;
void print()
{
	int i;
	for(i = 0;i<LEN;i++)
	printf("%d ", res[i]);
	printf("\r\n");
}
int is_cross(int loop, int value)
{
	int index;
	int data;
	for(index = 0; index<loop; index++)
	{
		data = res[index];
		if(value ==data)
			return 1;
		if((index - loop) == (value-data ))
			return 1;
		if(!(index - loop - data + value))
			return 1;
	}
	return 0;
}

void eight_queen(int index)
{
	int loop;
	for(loop = 0; loop < LEN; loop++)
	{
		if(!is_cross(index, loop))
		{
			res[index] = loop;
			if(LEN-1 == index)
			{
				COUNT++;
				print();
				res[index] = 0;
				return;
			}
			eight_queen(index+1);
			res[index] = 0;
		}
	}	
}

int main()
{
	COUNT=0;
	scanf("%d", &LEN);
	eight_queen(0);
	printf("COUNT = %d\r\n", COUNT);
}
