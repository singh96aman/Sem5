#include <stdio.h>
#include <stdlib.h>

int n=8;
int arr[]={98,183,37,122,14,124,65,67};
int src=53;

void FCFS()
{
	int THM=0;
	for(int i=0; i<n; i++)
	{
		//printf("%d %d\n",arr[i],src);
		THM+=abs(arr[i]-src);
		src=arr[i];
	}
	printf("\n FCFS THM : %d\n",THM);
	src=53;
}

void SSTF()
{
	int THM=0;
	int visited[n];
	for(int i=0; i<n; i++)
		visited[i]=0;

	for(int i=0; i<n; i++)
	{
		int min=9999, k=0;
		for(int j=0; j<n; j++)
			if(abs(src-arr[j])<min && visited[j]==0)
			{
				min=abs(src-arr[j]);
				k=j;
			}
		THM+=abs(arr[k]-src);
		src=arr[k];
		visited[k]=1;
	}
	printf("\n SSTF THM : %d\n",THM);
	src=53;
}

void SCAN()
{
	int THM=0;
	int *temp=arr;
	for(int i=0; i<n-1; i++)
		for(int j=0; j<n-i-1; j++)
			if(temp[j]>temp[j+1])
			{
				int t=temp[j];
				temp[j]=temp[j+1];
				temp[j+1]=t;
			}
	//for(int i=0; i<n; i++)
	//	printf("%d ",temp[i]);

	for(int i=0; i<n; i++)
	{
		if(temp[i]>src)
		{
			int j=i-1;
			while(j>=0)
			{
				//printf("%d %d\n",temp[j],src);
				THM+=abs(temp[j]-src);
				src=temp[j];
				j--;
			}
			THM+=arr[0]+arr[i];
			src=arr[i];
			i++;
			while(i!=n)
			{
				//printf("%d %d\n",temp[i],src);
				THM+=abs(temp[i]-src);
				src=temp[i];
				i++;
			}
			break;
		}
	}
	printf("\n SCAN THM : %d\n",THM);
}

void CSCAN()
{
	int enddisk=199;
	src=53;
	int THM=0;
	int *temp=arr;
	for(int i=0; i<n-1; i++)
		for(int j=0; j<n-i-1; j++)
			if(temp[j]>temp[j+1])
			{
				int t=temp[j];
				temp[j]=temp[j+1];
				temp[j+1]=t;
			}
	for(int i=0; i<n; i++)
	{
		if(temp[i]>src)
		{
			int j=i;
			while(j!=n)
			{
				//printf("%d %d\n",temp[j],src);
				THM+=abs(temp[j]-src);
				src=temp[j];
				j++;
			}
			THM+=abs(enddisk-src);
			j=1;
			THM+=temp[0];
			src=temp[0];
			while(j<i)
			{
				//printf("%d %d\n",temp[j],src);
				THM+=abs(temp[j]-src);
				src=temp[j];
				j++;
			}
			break;
		}
	}
	printf("\n CSCAN THM : %d\n",THM);
}

void LOOK()
{
	src=53;
	int THM=0;
	int *temp=arr;
	for(int i=0; i<n-1; i++)
		for(int j=0; j<n-i-1; j++)
			if(temp[j]>temp[j+1])
			{
				int t=temp[j];
				temp[j]=temp[j+1];
				temp[j+1]=t;
			}

	for(int i=0; i<n; i++)
	{
		if(temp[i]>src)
		{
			int j=i-1;
			while(j>=0)
			{
				//printf("%d %d\n",temp[j],src);
				THM+=abs(temp[j]-src);
				src=temp[j];
				j--;
			}
			while(i!=n)
			{
				//printf("%d %d\n",temp[i],src);
				THM+=abs(temp[i]-src);
				src=temp[i];
				i++;
			}
			break;
		}
	}
	printf("\n LOOK THM : %d\n",THM);
}

void CLOOK()
{
	int enddisk=199;
	src=53;
	int THM=0;
	int *temp=arr;
	for(int i=0; i<n-1; i++)
		for(int j=0; j<n-i-1; j++)
			if(temp[j]>temp[j+1])
			{
				int t=temp[j];
				temp[j]=temp[j+1];
				temp[j+1]=t;
			}
	for(int i=0; i<n; i++)
	{
		if(temp[i]>src)
		{
			int j=i;
			while(j!=n)
			{
				//printf("%d %d\n",temp[j],src);
				THM+=abs(temp[j]-src);
				src=temp[j];
				j++;
			}
			src=temp[0];
			j=1;
			while(j<i)
			{
				//printf("%d %d\n",temp[j],src);
				THM+=abs(temp[j]-src);
				src=temp[j];
				j++;
			}
			break;
		}
	}
	printf("\n CLOOK THM : %d\n",THM);
}


int main()
{
	FCFS();
	SSTF();
	SCAN();
	CSCAN();
	LOOK();
	CLOOK();
}