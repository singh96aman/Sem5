#include<stdio.h>
unsigned int EuclidGCD(unsigned int m, unsigned int n){
	unsigned int r;
	int opcount=0;
	while(n!=0){
		opcount++;
		r=m%n;
		m=n;
		n=r;
	}
	printf("Operation count=%d\n",opcount);
	return m;
}
int main(){
	unsigned int m, n;
	printf("Enter the 2 numbers whose GCD has to be calculated");
	scanf("%d",&m);
	scanf("%d",&n);
	printf("GCD of 2 numbers using Euclid's method is %d", EuclidGCD(m,n));
	return 0;
}
