#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shifttable(char p[], int table[], int size)
{
	int m=strlen(p);
	for(int i=m-2; i>=0; i--)
	{
		char c=p[i];
		int sh=m-i-1;
		int pos=(int)c-65;
		if(table[pos]>sh)
			table[pos]=sh;
	}
}

int main()
{
	char t[100], p[30];
	gets(t);
	gets(p);
	int m=strlen(p);
	int table[26];
	for(int i=0; i<26; i++)
		table[i]=m;
	shifttable(p,table,26);

	int i=m-1, n=strlen(t), flag=0;
	while(i<n)
	{
		int k=0;
		while(k<m && p[m-1-k]==t[i-k])
			k++;
		if(k==m){
			flag=1;
			printf("\n Found at %d \n",i+2-m);
		}
		if(t[i-k]==' ')
			i+=m;
		else{
			int s = (int)t[i]-65;
			i+=table[s];
		}
	}
	if(flag==0)
		printf("\n No Match found!");
}