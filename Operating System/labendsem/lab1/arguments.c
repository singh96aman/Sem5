#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("\n %d",argc);
	for(int i=0; i<argc; i++)
		printf("%s\n",argv[i]);
}