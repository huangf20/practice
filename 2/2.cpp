#include<stdio.h>
#define N 1000
int main()
{
	char a[N];
	int m=0;
	int n=0;
	int i=0;
	scanf("%s",a);
	while(a[i]!='\0')
	{
		if (a[i]<='z'&&a[i]>='a')
			m++;
		if(a[i]<='Z'&&a[i]>='A')
			n++;
		i++;

	}
	printf("大写字母有%d个\n",m);
	printf("小写字母有%d个\n",n);

	return 0;

}
