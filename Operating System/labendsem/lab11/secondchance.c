// Very Important
#include <stdio.h>
#include <stdlib.h>

int n=20;
int arr[]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
int f=3;

void secondchance()
{
	int counter=3, fcounter=0, pagefault=0;
	int frame[f], ref[f];
	for(int i=0; i<f; i++)
		{frame[i]=999; ref[i]=1;}


	for(int i=0; i<n; i++)
	{
		printf("%d ",arr[i]);
		int flag=0;
		for(int j=0; j<f; j++)
			if(frame[j]==arr[i])
				{flag=1; ref[j]=1; break;}
		if(flag==0 && counter!=0)
		{
			//printf(" %d ",counter);
			for(int j=0; j<f; j++)
			{
				if(frame[j]==999)
				{
					frame[fcounter]=arr[i];
					ref[fcounter]=1;
					fcounter=(fcounter+1)%f;
					counter--;
					break;
				}
			}
			for(int j=0; j<f; j++)
				if(frame[j]==999)
					printf(" - ");
				else
					printf(" %d ",frame[j]);
			printf("\n");
			pagefault++;
		}
		else if(flag==0)
		{
				int j=fcounter;
				while(ref[j]!=0)
				{
					ref[j]=0;
					j=(j+1)%f;	
				}
				frame[j]=arr[i];
				ref[j]=1;
				fcounter=(j+1)%f;
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
	secondchance();
}
