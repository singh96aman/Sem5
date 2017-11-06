#include <stdio.h>
#include <stdlib.h>

int n=20;
int arr[]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
int f=3;

void FCFS()
{
	int counter=0, fcounter=0, pagefault=0;
	int frame[f];
	for(int i=0; i<f; i++)
		frame[i]=999;

	for(int i=0; i<n; i++)
	{
		printf("%d ",arr[i]);
		int flag=0;
		for(int j=0; j<f; j++)
			if(frame[j]==arr[i])
				{flag=1; break;}
		if(flag==0)
		{
			frame[fcounter]=arr[i];
			fcounter=(fcounter+1)%f;
			for(int j=0; j<f; j++)
				if(frame[j]==999)
					printf(" - ");
				else
					printf(" %d ",frame[j]);
			printf("\n");
			pagefault++;
		}
		else
			printf(" No Page Fault\n");
	}
	printf("\n No of page Faults : %d\n",pagefault);
}

void optimal()
{
	int counter=0, fcounter=0, pagefault=0;
	int max[]={9999,9999,9999};
	int frame[f];
	for(int i=0; i<f; i++)
		frame[i]=999;

	for(int i=0; i<n; i++)
	{
		printf("%d  ",arr[i]);
		int flag=0;
		for(int j=0; j<f; j++)
			if(frame[j]==arr[i])
				{flag=1; break;}
		if(flag==0)
		{
			if(fcounter!=f)
			{	frame[fcounter]=arr[i];
				fcounter++;
			}
			else
			{
				for(int j=0; j<f; j++)
					{
						max[j]=n;
						for(int k=i+1; k<n; k++)
						{
							if(arr[k]==frame[j])
								{ max[j]=k; break;}
						}
					}
				int m=-1, k;
				for(int j=0; j<f; j++)
				{
					if(m<max[j])
						{ m=max[j]; k=j;}
				}
				//printf(" %d ",m);
				frame[k]=arr[i];
				pagefault++;

			}
			for(int j=0; j<f; j++)
				if(frame[j]==999)
					printf(" - ");
				else
					printf(" %d ",frame[j]);
			printf("\n");
			pagefault++;
		}
		else
			printf(" No Page Fault\n");
	}
	printf("\n No of page Faults : %d\n",pagefault);
}

void LRU()
{
	int counter=0, fcounter=0, pagefault=0;
	int max[]={9999,9999,9999};
	int frame[f];
	for(int i=0; i<f; i++)
		frame[i]=999;

	for(int i=0; i<n; i++)
	{
		printf("%d  ",arr[i]);
		int flag=0;
		for(int j=0; j<f; j++)
			if(frame[j]==arr[i])
				{flag=1; break;}
		if(flag==0)
		{
			if(fcounter!=f)
			{	frame[fcounter]=arr[i];
				fcounter++;
			}
			else
			{
				for(int j=0; j<f; j++)
					{
						max[j]=-1;
						for(int k=i-1; k>=0; k--)
						{
							if(arr[k]==frame[j])
								{ max[j]=k; break;}
						}
					}
				int m=9999, k;
				for(int j=0; j<f; j++)
				{
					if(m>max[j])
						{ m=max[j]; k=j;}
				}
				//printf(" %d ",m);
				frame[k]=arr[i];
				pagefault++;
			}
			for(int j=0; j<f; j++)
				if(frame[j]==999)
					printf(" - ");
				else
					printf(" %d ",frame[j]);
			printf("\n");
			pagefault++;
		}
		else
			printf(" No Page Fault\n");
	}
	printf("\n No of page Faults : %d\n",pagefault);
}


int main()
{
	FCFS();
	optimal();
	LRU();
}