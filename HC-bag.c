#include <stdio.h>
#include <stdlib.h>
int main()
{
	int weight[24] = {382745,799601,909247,729069,467902,44328,
					  34610,698150,823460,903959,853665,551830,
					  610856,670702,488960,951111,323046,446298,
					  931161, 31385,496951,264724,224916,169684};
	int profit[24] = {825594,1677009,1676628,1523970,943972,97426,
					  69666,1296457,1679693,1902996,1844992,1049289,
					  1252836,1319836,953277,2067538,675367,853655,
					  1826027,65731,901489,577243,466257,369261};
	int data[24] = {0},temp[24] = {0};
	int max_weight = 6404180,max_profit = 13549094,i,count_weight = 6404181,count_profit,count = 0;
	srand(time(NULL));
	while(count_weight>max_weight)//初始 
	{
		count_weight = count_profit = 0;		
		for(i=0;i<24;i++)
		{
			temp[i] = data[i] = rand()%2;
			if(data[i]==1)
			{
				count_weight = count_weight + weight[i];
				count_profit = count_profit + profit[i];
			}
		}
	}
	printf("初始:");	
	for(i=0;i<24;i++)
		printf("%d ",data[i]);
	printf("\n背包初始:%d\n",count_weight);
	printf("利潤初始:%d\n",count_profit);
	//printf("count_weight = %d\n",count_weight);	
	while((count!=100000)&&(count_weight < max_weight)&&(count_profit < max_profit))
	{
		count++;
		int a = rand()%24,b,profit_a = 0,profit_a0 = 0,profit_a1 = 0,profit_b = 0,profit_b0 = 0,profit_b1 = 0,count_weighta = 0,count_weightb = 0;
		b = (a + 1)%24;
		count_weightb = count_weighta = count_weight;
		if((temp[a]==1)&&(temp[b]==1))
		{
			a = rand()%24;
			b = (a + 1)%24;
		}
//		printf("a = %d\n",a);
//		printf("b = %d\n",b);				
		if(data[a] == 0)
		{
			count_weighta = count_weighta + weight[a];
			if(count_weighta > max_weight)//不放入 
				count_weighta = count_weighta - weight[a];
			else//放入 
			{				
				profit_a0 = profit[a];
			}			
		}
		/*else
			profit_a1 = profit[a]; 
		if(profit_a0 > profit_a1)
			profit_a = profit_a0;
		else
			profit_a = profit_a1;*/
		if(data[b] == 0)
		{
			count_weightb = count_weightb + weight[b];
			if(count_weightb > max_weight)//不放入 
				count_weightb = count_weightb - weight[b];
			else//放入
			{
				profit_b0 = profit[b];
			}			
		}
		/*else
			profit_b1 = profit[b];
		if(profit_b0 > profit_b1)
			profit_b = profit_b0;
		else
			profit_b = profit_b1;*/
		if((profit_a0 != 0)||(profit_b0 != 0))
		{
			if(profit_a0 >= profit_b0)
			{
				temp[a] = 1;
				count_profit = count_profit + profit_a0;
				count_weight = count_weighta;
			}
			else
			{
				temp[b] = 1;
				count_profit = count_profit + profit_b0;
				count_weight = count_weightb;
			}
		}		
//		printf("利潤a:%d\n",profit_a0);
//		printf("利潤b:%d\n",profit_b0);	
//		printf("%2d = ",count);		
//		for(i=0;i<24;i++)
//			printf("%d ",temp[i]);
//		printf("\n背包:%d\n",count_weight);
//		printf("利潤:%d\n\n",count_profit);	
	}
	printf("--------------------------------------------------------------\n");	
	printf("最終:");	
	for(i=0;i<24;i++)
		printf("%d ",temp[i]);
	printf("\n背包重量 = %d\n",count_weight);
	printf("利潤 = %d\n",count_profit);
} 
