#include <stdio.h>
#include <stdlib.h>

int Knapsack(int W[], int V[], int B, int n)
{
	int max_size = pow(2,n), index=0;
	int maxVal=0, maxWeight=0;
	int totalValue=0, totalWeight=0;
	int maxSequence=0;

	for(int i=1; i<max_size; i++)
	{
		int temp=i;
		totalWeight=0;
		totalValue=0;
		index=0;
		while(temp)
		{
			if(temp & 0x1)
			{
				totalWeight += W[index];
				totalValue += V[index];
			}
			temp = temp >> 1;
			index++;
		}
		if(totalWeight<=B && totalValue>maxVal)
		{	maxVal=totalValue;
			maxSequence=i;	}
	}
	return maxSequence;
}

int main()
{
	int W[]={1,2,4};
	int V[]={2,4,8};
	int B=5;
	int n=3;
	int knaps = Knapsack(W,V,B,n);
	int i=0;
	while(knaps)
	{
		if(knaps & 0x1)
		{
			printf("\n Item %d with value %d",i+1,V[i]);
		}
		knaps = knaps >>1;
		i++;
	}
}