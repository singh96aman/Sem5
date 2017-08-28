#include<stdio.h>

typedef struct process{
	int pid;
	int at;
	int bt;
	int priority;
}Process;

void FCFS(Process p[100], int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<n-1-i; j++)
		{
			if(p[j].at > p[j+1].at)
			{
				Process temp = p[j];
				p[j] = p[j+1];
				p[j+1]=temp;
			}
		}
	}
	
	int wt[n], tat[n], gantt[n];
	for(int i=0; i<n; i++)
	{
		if(i==0)
		{
			wt[i]=p[i].at;
			gantt[i]=p[i].at;
			printf("\n From %d Process %d to %d\n",gantt[i],p[i].pid,gantt[i]+p[i].bt); 
		}
		else
		{
			wt[i]=wt[i-1]+p[i-1].bt-p[i].at;
			gantt[i]=gantt[i-1]+p[i-1].bt; // add condition whether wt[i-1] < p[i-1].bt
			printf("\n From %d Process %d to %d\n",gantt[i],p[i].pid,gantt[i]+p[i].bt); 
		}
	}
	printf("\n Waiting Time !\n");
	for(int i=0; i<n; i++)
		printf(" %d ",wt[i]);
	
	for(int i=0; i<n; i++)
		tat[i]=wt[i]+p[i].bt;
		
	printf("\n Turnaround Time !\n");
	for(int i=0; i<n; i++)
		printf(" %d ",tat[i]);
		
	float sum_wt=0, sum_tat=0;	
	
	for(int i=0; i<n; i++)
	{
		sum_wt+=wt[i];
		sum_tat+=tat[i];
	}
	printf("\n Average Waiting Time is %f",sum_wt/n);
	printf("\n Average Turn Around Time is %f",sum_tat/n); 
	
}

void Non_Pre(Process p[100], int n)
{
	int min =999, k;
	for(int i=0; i<n; i++)
		if(min>p[i].at)
		{
			min=p[i].at;
			k=i;
		}
	
	Process temp = p[0];
	p[0]=p[k];
	p[k]=temp;	

	for(int i=1; i<n-1; i++)
	{
		for(int j=1; j<n-1; j++)
		{
			if(p[j].priority > p[j+1].priority)
			{
				Process temp = p[j];
				p[j] = p[j+1];
				p[j+1]=temp;
			}
		}
	}

	
	// Executing first process
	/*
	printf("\n %d",p[k].pid);
	for(int i=0; i<n; i++)
	{
		if(i!=k)
			printf("\n %d",p[i].pid);
	}
	*/
	int wt[n], tat[n], gantt[n];
	for(int i=0; i<n; i++)
	{
		if(i==0)
		{
			wt[i]=p[i].at;
			gantt[i]=p[i].at;
			printf("\n From %d Process %d to %d\n",gantt[i],p[i].pid,gantt[i]+p[i].bt); 
		}
		else
		{
			wt[i]=wt[i-1]+p[i-1].bt-p[i].at;
			gantt[i]=gantt[i-1]+p[i-1].bt; // add condition whether wt[i-1] < p[i-1].bt
			printf("\n From %d Process %d to %d\n",gantt[i],p[i].pid,gantt[i]+p[i].bt); 
		}
	}
	printf("\n Waiting Time !\n");
	for(int i=0; i<n; i++)
		printf(" %d ",wt[i]);
	
	for(int i=0; i<n; i++)
		tat[i]=wt[i]+p[i].bt;
		
	printf("\n Turnaround Time !\n");
	for(int i=0; i<n; i++)
		printf(" %d ",tat[i]);
		
	float sum_wt=0, sum_tat=0;	
	
	for(int i=0; i<n; i++)
	{
		sum_wt+=wt[i];
		sum_tat+=tat[i];
	}
	printf("\n Average Waiting Time is %f",sum_wt/n);
	printf("\n Average Turn Around Time is %f",sum_tat/n); 
}


void SRTF(Process p[100], int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<n-1-i; j++)
		{
			if(p[j].at > p[j+1].at)
			{
				Process temp = p[j];
				p[j] = p[j+1];
				p[j+1]=temp;
			}
		}
	}
	int i=0;
	while(1)
	{
		
	}
		
} 

int main()
{
  int n;
  printf("\n Enter the No of Process : ");
  scanf("%d",&n);
  Process p[n];
  printf("\n Enter the Arrival Time : \n");
  for(int i=0; i<n; i++)
  	scanf("%d",&(p[i].at));
  printf("\n Enter the Burst Time : \n");
  for(int i=0; i<n; i++)
  	scanf("%d",&(p[i].bt));
  printf("\n Enter the Priority : \n");
  for(int i=0; i<n; i++)
  	scanf("%d",&(p[i].priority));
  for(int i=0; i<n; i++)
  	p[i].pid=i+1;
  //FCFS(p,n);
  Non_Pre(p,n);
}
