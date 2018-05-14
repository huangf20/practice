#include<stdio.h>
int main()
{
	int i,i2;
	int n1,n2,n3,m1,m2,m3;
	for(i=100;i<1000;i++)
	{
		i2=i*i;
		n1=i%10;
		n2=i%100/10;
		n3=i/100;
		m1=i2%10;
		m2=i2%100/10;
		m3=i2%1000/100;
		if(n1==m1&&n2==m2)
		{
			if(n3==m3)
			printf("%d\n",i);
		}
	}
	return 0;
}


