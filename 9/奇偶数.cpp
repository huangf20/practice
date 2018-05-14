#include<stdio.h>
void main()
{
	int i,n,m[100];
	int a,b;
	a=b=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m[i]);
	}
	for(i=0;i<n;i++)
	{
		if(m[i]%2==1)
			a++;
		else b++;
	}

	printf("%d  %d\n",a,b);

}
