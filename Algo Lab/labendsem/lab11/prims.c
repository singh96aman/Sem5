#include <stdio.h>
int a[50][50], t[50][50], n=6, i, j, e=0, k=0, TV[50], ivalue, jvalue, mincost=0, count=0, present=0, cost=0;

void read_cost()
{
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{	if(i<j)
			{
				printf("%d %d",i,j);
				scanf("%d",&(a[i][j]));
				if(a[i][j]!=0)
					e++;
			}
			else if(i>j)
				a[i][j]=a[j][i];
			else
				a[i][j]=0;
		}
}

int check_reach(int v)
{
	for(int p=1; p<=count; p++)
		if(TV[p]==v) return 1;
	return 0;
}

void prims()
{
	while(e && k<n-1)
	{
		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
			{
				if(a[i][j]!=0)
				{
					int x=check_reach(i);
					int y=check_reach(j);
					if((x==1) && (y==0))
					{
						present=1;
						if((a[i][j]<cost) || (cost==0))
						{
							cost=a[i][j];
							ivalue=i;
							jvalue=j;
						}
					}
				}
			}
		if(present==0) break;
		a[ivalue][jvalue]=0;
		a[jvalue][ivalue]=0;
		e--;
		TV[++count]=jvalue;
		t[ivalue][jvalue]=cost;
		k++;
		cost=0; present=0;
	}
}

void display()
{
	if (k==n-1)
	{
		printf("\n Min Spanning tree is : ");
		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
			{
				if(t[i][j]!=0)
					printf("%d %d : %d\n",i,j,t[i][j]);
				mincost=mincost+t[i][j];
			}
			printf("%d\n",mincost);
	}
}

int main()
{
	printf("\n prims");
	TV[++count]=1;
	read_cost();
	prims();
	display();
	return 0;
}