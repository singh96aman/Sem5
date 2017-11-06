// Deadlock Avoidance
#include <stdio.h>
#include <stdlib.h>

int n=5, r=3;
	int max[5][3]={
		{7,5,3},
		{3,2,2},
		{9,0,2},
		{2,2,2},
		{4,3,3}
	};
	int available[5]={3,3,2};
	int need[5][3];
	int allocation[5][3]={
		{0,1,1},
		{2,0,0},
		{3,0,2},
		{2,1,1},
		{0,0,2}
	};


void q1a()
{
	for(int i=0; i<n; i++)
		for(int j=0; j<r; j++)
			need[i][j]=max[i][j]-allocation[i][j];

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<r; j++)
			printf("%d ",need[i][j]);
		printf("\n");
	}

	int complete=0, max_attempt=3;
	int taskcomplete[n];
	for(int i=0; i<n; i++)
		taskcomplete[i]=0;

	while(max_attempt!=0 && complete<n)
	{
		for(int i=0; i<n; i++)
		{
			if(taskcomplete[i]==0)
			{
				int flag=0;
				for(int j=0; j<r; j++)
					if(need[i][j]>available[j])
						{flag=1; break;}
				if(flag==0)
				{
					printf("\n Task %d is completed !\n",i+1);
					for(int j=0; j<r; j++)
						available[j]+=allocation[i][j];
					taskcomplete[i]=1;
					complete++;
				}
			}
		}
		max_attempt--;
	}
}

void q2()
{

	int allocation[5][3]={
		{0,1,0},
		{2,0,0},
		{3,0,3},
		{2,1,1},
		{0,0,2}
	};

	int request[5][3]={
		{0,0,0},
		{2,0,2},
		{0,0,0},
		{1,0,0},
		{0,0,2}
	};

	int available[3]={0,0,0};


	for(int i=0; i<n; i++)
		for(int j=0; j<r; j++)
			need[i][j]=max[i][j]-allocation[i][j];

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<r; j++)
			printf("%d ",need[i][j]);
		printf("\n");
	}

	int complete=0, max_attempt=3;
	int taskcomplete[n];
	for(int i=0; i<n; i++)
		taskcomplete[i]=0;

	while(max_attempt!=0 && complete<n)
	{
		for(int i=0; i<n; i++)
		{
			int free=0;
			for(int j=0; j<r; j++)
				if(request[i][j]!=0 || taskcomplete[i]==1)
					{free=1; break;}
			if(free==0)
			{
				//printf("%d\n",i);
				for(int j=0; j<r; j++)
						available[j]+=allocation[i][j];
					taskcomplete[i]=1;
					complete++;
					printf("\n Task %d is completed !\n",i+1);
			}
			if(taskcomplete[i]==0)
			{
				int flag=0;
				for(int j=0; j<r; j++)
					if(request[i][j]>available[j])
						{flag=1; break;}
				if(flag==0)
				{
					printf("\n Task %d is completed !\n",i+1);
					for(int j=0; j<r; j++)
						available[j]+=allocation[i][j];
					taskcomplete[i]=1;
					complete++;
				}
			}
		}
		max_attempt--;
	}
}

int main()
{
	//q1a();
	q2();	
}