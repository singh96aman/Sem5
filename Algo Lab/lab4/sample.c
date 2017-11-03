#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int Knapsack(unsigned int *w, unsigned int *v, unsigned int n, unsigned int B)
{
	unsigned int i, temp;
	unsigned int maxVal=0, maxSequence=0;
	unsigned int totalWeight, totalValue;
	int opcount=0;
	unsigned int index=0;
	for(i=1; i<pow(2,n); i++)
	{
		opcount++;
		temp=i;
		totalWeight=totalValue=0;
		index=0;
		while(temp){
			if(temp & 0x1){
				totalWeight = totalWeight + w[index];
				totalValue = totalValue + v[index];
			}
			index++;
			temp = temp >>1;
		}
		if(totalWeight <= B && totalValue > maxVal){
			maxVal = totalValue;
			maxSequence = i;
		}
	}
	printf("\n Operation Count = %d \n",opcount);
	return maxSequence;
}

int main()
{
	unsigned int *v, *w, i, n, knaps, B;
	printf("\n Enter The No Of Elements : ");
	scanf("%d",&n);
	v = (unsigned int *) calloc(n, sizeof(unsigned int));
	w = (unsigned int *) calloc(n, sizeof(unsigned int));
	printf("\n Please Enter The weights : ");
	for(i=0; i<n; i++)
		scanf("%d",&w[i]);
	printf("\n Please Enter The Values : ");
	for(i=0; i<n; i++)
		scanf("%d",&v[i]);
	printf("\n Please Enter the Knapsack capacity : ");
	scanf("%d",&B);
	knaps = Knapsack(w,v,n,B);
	printf("\n Knapsack contains the following items \n");
	i=0;
	while(knaps){
		if(knaps & 0X1)
			printf("item %u    value %u\n",(i+1),v[i]);
		i++;
		knaps = knaps >> 1;	
	}
	return 0;
}
