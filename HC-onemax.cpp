#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	
	int i,score=0,count=0,newscore=0,number=500;	
//	printf("input bit = ");
//	scanf("%d",&number);
	int data[number]={0};
	srand(time(NULL));
	for(i=0;i<number;i++)
	{
		data[i] = rand()%2;
		if(data[i] == 1)
			score++;
	}
	newscore = score;
	printf("��l�� = ");
	for(i=0;i<number;i++)
	{
		printf("%d ",data[i]);
	}
	printf("\n��lscore = %d\n",score);
	while((newscore!=number))
	{
		int a = rand()%number;		
		count++;
		if(data[a] == 0)
		{
			data[a] = 1;
			newscore++;			
		}
	}
	printf("��ʫ� = ");
	for(i=0;i<number;i++)
	{
		printf("%d ",data[i]);
	}
	printf("\n�ܧ��score = %d\n",newscore);
} 
