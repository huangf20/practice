#include<stdio.h>
#include<string.h>
void main()
{
	char ararry[100];
	int i=0;
	gets(ararry);
	while(ararry[i]!='\0')
	{
		printf("%c\n",ararry[i]);
		i++;
		
	}
}

