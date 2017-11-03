#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	fp = fopen(argv[2],"r");
	char *filename;
	char fline[50];
	int count=0, line=0 ; 
	while(fgets(fline,100,fp)!=NULL)
	{
		line++;
		for(int i=0; fline[i]!='\0'; i++)
			count++;
	}
	printf("\n No of Lines %d No of words %d",line, count);
}