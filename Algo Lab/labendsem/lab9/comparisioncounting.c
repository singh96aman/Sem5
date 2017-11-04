#include <stdio.h>

void comparisioncounting(int a[],int s[], int n)
{
	int count[n];
	for(int i=0; i<n; i++)
		count[i]=0;
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(a[j]>a[i])
				count[j]++;
			else
				count[i]++;
	for(int i=0; i<n; i++)
		s[count[i]]=a[i];
}
int main()
{
	int n=5;
	int arr[]={5,2,1,4,3};
	int s[n];
	comparisioncounting(arr,s,n);
	for(int i=0; i<n; i++)
		printf("%d ",s[i]);
}