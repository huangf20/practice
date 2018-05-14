#include<stdio.h>
int ti(int x,int y)
	{
		int i,n=x;
		if (y==0)
			n=1;
		else
		for(i=0;i<y-1;i++)
		{
			n=n*x;
		}
		return n+1;

	}
int main()
{
	

	int i;
	printf("请输入对折次数：");
	scanf("%d",&i);
	printf("可以得到%d根面条\n",ti(2,i));
	return 0;


}


