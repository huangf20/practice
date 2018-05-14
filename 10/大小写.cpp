#include<stdio.h>

int main()
{
	int i=0;
	char a[20],b[20];
	gets(a);
	while(a[i]!='\0')
	{
		b[i]=a[i];
		if (a[i]<='z'&&a[i]>='a')
			b[i]=a[i]-32;
		if(a[i]<='Z'&&a[i]>='A')
			b[i]=a[i]+32;
		printf("%c",b[i]);
		i++;

	}
	printf("\n");
	





	return 0;
}