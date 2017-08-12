#include<stdio.h>
#include<stdlib.h>
void stringmatching(char *str1, char *str2, int len1, int len2){
	int i, j, flag=0;
	for(i=0; i<len1; i++){
		if(str1[i]==str2[0]){
			for(j=1; j<len2; j++)
				if(str1[i+j]==str2[j])
				{
					flag=1;
					//printf("\njkgfhd\n");
				}
				else
				{
					flag=0;
					break;
				}
		if(flag==1)
			{printf("Substring found at %d\n",i);
				return;}
		flag=0;
	}
	}
}

int main()
{
	int len1, len2;
	
	printf("Enter the String ");
	char *str1=(char*)malloc(sizeof(char)*100);
	gets(str1);
	printf("Enter the String ");
	char *str2 = (char*) malloc(sizeof(char)*100	);
	gets(str2);
	for(len1=0; str1[len1]!='\0'; len1++);
	for(len2=0; str2[len2]!='\0'; len2++);
	stringmatching(str1,str2,len1,len2);
}