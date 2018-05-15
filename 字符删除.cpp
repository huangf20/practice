#include<stdio.h>
#include<string.h>
void  char_delete(char *str,char c)
{
	int i=0,j=0;
	char s[20];
	while(str[i] != '\0')
	{
		if(str[i] != c)
			s[j++] = str[i];
		i++;
	}
	s[j]='\0';
	strcpy(str,s);
}
int main()
{
    char str[20];
	char c;
	gets(str);
	scanf("%c",c);
	char_delete(str,c);
	printf("%s",str);
	return 0;
}

