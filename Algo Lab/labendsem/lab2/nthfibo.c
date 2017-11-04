#include <stdio.h>
#include <stdlib.h>

int fibo(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	else
		return fibo(n-1)+fibo(n-2);
}

int main(){
	printf("%d",fibo(4));
}