#include <stdio.h>
#include <stdlib.h>

void firstfit(int memory[5], int process[5], int n, int p)
{
	int j=0, totalinternalfrag=0;
	int visited[5];
	for(int i=0; i<n; i++)
		visited[i]=0;
	int max_attempt=3;
	while(j<p && max_attempt!=0)
	{
	for(int i=0; i<n; i++)
	{
		if(memory[i]>process[j] && j<p && visited[i]==0)
		{
			printf("%d is in memory %d\n",process[j],memory[i]);
			totalinternalfrag+=memory[i]-process[j];
			j++;
			visited[i]=1;
		}
	}
	max_attempt--;
	}
	if(j<p)
		for(int k=j; k<p; k++)
			printf("\n Not enough memory for %d\n",process[k]);	
	printf("\n Total Internal Fragmentation : %d\n",totalinternalfrag);
}

void bestfit(int memory[5], int process[5], int n, int p)
{
	int j=0, totalinternalfrag=0;
	int visited[5];
	for(int i=0; i<n; i++)
		visited[i]=0;
	int max_attempt=3;
	while(j<p)
	{
			int min=9999, min_j, k=0;
			for(k=0; k<n; k++)
				if((memory[k]-process[j])<min && memory[k]>process[j] && visited[k]==0)
				{
					min=memory[k]-process[j];
					min_j=k;
				}
			printf("%d is in memory %d\n",process[j],memory[min_j]);
			totalinternalfrag+=memory[min_j]-process[j];
			j++;
			visited[min_j]=1;
	}
	printf("\n Total Internal Fragmentation : %d\n",totalinternalfrag);
}

void worstfit(int memory[5], int process[5], int n, int p)
{
	int j=0, totalinternalfrag=0;
	int visited[5];
	for(int i=0; i<n; i++)
		visited[i]=0;
	int max_attempt=3;
	while(j<p)
	{
			int max=-1, min_j, k=0;
			for(k=0; k<n; k++)
				if((memory[k]-process[j])>max && memory[k]>process[j] && visited[k]==0)
				{
					max=memory[k]-process[j];
					min_j=k;
				}
			printf("%d is in memory %d\n",process[j],memory[min_j]);
			totalinternalfrag+=memory[min_j]-process[j];
			j++;
			visited[min_j]=1;
	}
	printf("\n Total Internal Fragmentation : %d\n",totalinternalfrag);
}

int main()
{
	int memory[5]={100,500,200,300,600};
	int process[4]={212,417,112,426};
	int n=5;
	int p=4;
	firstfit(memory,process,n,p);
	printf("\n");
	bestfit(memory,process,n,p);
	printf("\n");
	worstfit(memory,process,n,p);
}