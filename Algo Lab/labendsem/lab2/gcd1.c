#include <stdio.h>
#include <stdlib.h>

int EuclidGCD(int m, int n)
{
	int r;
	while(n!=0)
	{
		r=m%n;
		m=n;
		n=r;
	}
	return m;
}

int consecutiveintegerchecking(int m, int n)
{
	//find min
	int min;
	if(m<n)
		min=m;
	else
		min=n;

	while(min!=1)
	{
		if(m%min==0 && n%min==0)
			return min;
		min--;
	}
	return 1;
}

int checkPrimeno(int prime)
{
	for(int i=2; i<prime/2; i++)
	{
		if(prime%i==0)
			return 0;
	}
	return 1;
}

int findPrimeFactor(int factor[10], int n)
{
	int k=0;
	int i=2;
	while(n!=1)
	{
		if(checkPrimeno(i)==1)
		{
			while(n%i==0)
			{
				factor[k++]=i;
				n=n/i;
			}
		}
		i++;
	}
	for(int i=0; i<k; i++)
		printf("%d ",factor[i]);
	return k;
}

int middleschoolmethod(int m, int n)
{
	int factorm[10], factorn[10];
	int lenm=findPrimeFactor(factorm,m);
	int lenn=findPrimeFactor(factorm,n);
	//for(int i=0; i<lenn; i++)
		//printf("\n %d ",factorn[i]);
	int a=0, b=0;
	int answer=1;
	while(a<lenm && b<lenn)
	{
		if(factorm[a]==factorn[b])
			answer*=factorm[a];
		else if(factorm[a]<factorn[b])
			a++;
		else
			b++;
	}
	return answer;
}

int main()
{
	printf("%d\n%d\n%d\n",EuclidGCD(4,8), consecutiveintegerchecking(8,4),middleschoolmethod(8,4));
}
