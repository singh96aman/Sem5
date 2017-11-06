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
	int total_time=0;

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

	for(int i=0; i<n; i++)
		total_time+=p[i].bt;

	int curtime=0, visited=0, complete[n];
	for(int i=0; i<n; i++)
		complete[i]=0;

	while(total_time!=0)
	{
		int min=999;
		for(int i=0; i<n; i++)
			if(p[i].at<curtime && complete[i]==0)
				if(p[i].bt<min && p[i].bt>=0)
					{	min=p[i].bt;
						visited=i;}

		printf(" %d %d %d\n",curtime,visited+1,p[visited].bt);
		p[visited].bt--;
		curtime++;
		total_time--;	

		if(p[visited].bt==0)
			complete[visited]=1;
	}
		
} 

void RoundRobin(Process p[100], int n)
{
	int total_time=0, quanta=10;

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

	for(int i=0; i<n; i++)
		total_time+=p[i].bt;

	int curtime=0, visited=0, complete[n];
	for(int i=0; i<n; i++)
		complete[i]=0;

	int q[100];
	int f=-1, r=-1;
	q[++r]=visited;

	for(int i=0; i<n; i++)
		{
			//printf(" Hello ");
			if(p[i].at<(curtime+10) && complete[i]==0 && i!=visited)
				{
					r=(r+1)%n;
					q[r]=i;
					//printf(" %d ",r);
				}
		}

	while(total_time>0)
	{
		f=(f+1)%n;
		visited=q[f];
		printf("%d %d %d",visited,curtime,curtime+10);

		p[visited].bt-=10;
		curtime+=10;
		total_time-=10;

		if(p[visited].bt<=0)
			complete[visited]=1;


		if(complete[visited]==0)
		{
			r=(r+1)%n;
			q[r]=visited;
		}
		//for(int i=0; i<n; i++)
		//	printf(" %d ",q[i]);
		printf("\n");
	}
}

int main()
{
  int n=4;
  Process p[n];
  p[0].pid=1;
  p[0].at=0;
  p[0].bt=60;
  p[0].priority=3;
  p[1].pid=2;
  p[1].at=3;
  p[1].bt=30;
  p[1].priority=2;
  p[2].pid=3;
  p[2].at=4;
  p[2].bt=40;
  p[2].priority=1;
  p[3].pid=4;
  p[3].at=9;
  p[3].bt=10;
  p[3].priority=4;
  //FCFS(p,n);
  //Non_Pre(p,n);
  //SRTF(p,n);
  RoundRobin(p,n);
}
