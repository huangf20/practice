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
	printf("��д��ĸ��%d��\n",m);
	printf("Сд��ĸ��%d��\n",n);

	return 0;

}
