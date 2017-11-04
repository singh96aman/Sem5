#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int match(char *arr, char *ref, int len1, int len2)
{
	//printf("%s %s %d %d",arr,ref, len1, len2);
	int flag=0;
	for(int i=0; i<len1; i++)
	{
		if(arr[i]==ref[0])
			for(int j=0; j<len2; j++)
				if(arr[i+j]==ref[j])
					flag=1;
				else 
				{
					flag=0;
					
					break;
				}
		if(flag==1)
			return 1;		
	}
	return 0;
}

int main()
{
	char *arr = (char *) malloc(sizeof(char)*100);
	gets(arr);
	char *ref = (char *) malloc(sizeof(char)*100);
	gets(ref);
	int len1 = strlen(arr);
	int len2 = strlen(ref);
	printf(" '%d' \n",match(arr,ref,len1,len2));
}