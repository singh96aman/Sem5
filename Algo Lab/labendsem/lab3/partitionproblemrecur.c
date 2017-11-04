#include <stdio.h>
#include <stdlib.h>

int partition(int a[], int b[], int c[], int i, int n, int len1, int len2)
{
	int sum1=0, sum2=0;
	if(i==n)
	{
		for(int j=0; j<len1; j++)
			b[j]+=sum1;
		for(int j=0; j<len2; j++)
			c[j]+=sum2;
		if(sum1==sum2)
		{
			printf("\n Partition Found ! \n First Partition : ");
			for(int j=0; j<len1; j++)
				printf("%d ",a[j]);
			printf("\n Second Partition :");
			for(int j=0; j<len2; j++)
				printf("%d ",b[j]);
			return 1;
		}
		return 0;
	}

	int flag1=0, flag2=0;
	b[len1] = a[i];
	flag1 = partition(a,b,c,i+1,n,len1+1,len2);
	c[len2] = a[i];
	flag2 = partition(a,b,c,i+1,n,len1, len2+1);
	return flag1||flag2;
}

int main()
{
	int n=5;
	int a[]={1,2,4,3,8};
	int b[5],c[5];
	partition(a,b,c,0,n,0,0);
}


/*
int partition(int *a, int *b, int *c, int i, int n, int len1, int len2){
	if (i == n){
		int sum1, sum2, j;
		sum1 = sum2 = 0;

		for (j=0; j<len1; j++) sum1+=b[j];
		for (j=0; j<len2; j++) sum2+=c[j];

		if (sum1 == sum2){
			printf("\nPartition Found! \nFirst subset: ");
			for (j=0; j<len1; j++) printf("%d ", b[j]);
			printf("\nSecond subset: ");
			for (j=0; j<len2; j++) printf("%d ", c[j]);
			printf("\n");

			return 1;
		}
		return 0;
	}

	int flag1 = 0, flag2 = 0;
	
	b[len1] = a[i];
	flag1 = partition(a, b, c, i+1, n, len1+1, len2);
	c[len2] = a[i];
	flag2 = partition(a, b, c, i+1, n, len1, len2+1);

	return flag1 || flag2;
}

int main(){
	int n, i, flag = 0;
	long sum = 0;
	printf("Enter number of elements in the set: ");
	scanf("%d", &n);

	int *a = (int*)calloc(n, sizeof(int));
	int *b = (int*)calloc(n, sizeof(int));
	int *c = (int*)calloc(n, sizeof(int));

	printf("Enter the elements: ");
	for (i=0; i<n; i++)
		scanf("%d", &a[i]);

	flag = partition(a, b, c, 0, n, 0, 0);

	if (!flag) printf("\nNo such partition found!\n");
	return 0;
}
*/