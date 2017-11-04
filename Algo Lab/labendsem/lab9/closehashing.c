#include <stdio.h>
#include <stdlib.h>
#define size 7
struct link
{
	int val;
};

int main()
{
	int n=5;
	int arr[]={45,12,45,3,23};
	struct link a[n];
	for(int i=0; i<n; i++)
		a[i].val=999;
	for(int i=0; i<n; i++)
	{
		int index=arr[i]%size;
		if(a[index].val==999)
			a[index].val=arr[i];
		else
		{
			int c=index;
			index=(index+1)%size;
			while(index!=c)
			{
				if(a[index].val==999)
				{
					a[index].val=arr[i];
					break;
				}else
				index=(index+1)%size;
			}
		}
	}
	for(int i=0; i<n; i++)
	{
		printf("Key : %d  Value : %d\n",i%size,a[i].val);
	}
}