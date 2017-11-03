#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
	FILE *fp;
	char fline[100];
	printf("\n Enter the file name to be searched : ");
	int i, count=0, occ=0;
	fp = fopen(argv[2],"r");
	while(fgets(fline,100,fp)!=NULL)
	{
		printf("\n %s",fline);
			if(strstr(fline,argv[1])!=NULL)
				occ++;
	}
	printf("\n Occurences : %d",occ);
}