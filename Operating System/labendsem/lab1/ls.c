#include <stdio.h>
#include <dirent.h>
int main()
{
	char dirname[10];
	DIR *p;
	struct dirent *d;
	printf("\n Enter Directory Name : ");
	scanf("%s",dirname);
	p=opendir(dirname);
	while(d=readdir(p))
		printf("%s\n", d->d_name);
	return 0;
}
