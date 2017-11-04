#include <stdio.h>
#include <stdlib.h>

// src, dest, inter
// src int dest
// int src dest

void towerofHanoi(int n, char src, char dest, char intermediate)
{
	if(n==1)
	{
		printf("\n Move disk 1 from %c to %c",src,dest);
		return;
	}
	towerofHanoi(n-1, src, intermediate, dest);
	printf("\n Move disk %d from %c to %c",n,src,dest);
	towerofHanoi(n-1, intermediate, dest, src);
}

int main()
{
	int n=4;
	towerofHanoi(n,'A','B','C');
}