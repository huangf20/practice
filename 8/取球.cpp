#include<stdio.h>
int result[1000]={0,0,1,0,1,0,1,0,1,0};

void win_lose()
{
	int i;
	for(i=10;i<=1000;i++)
	{
		result[i]=0;
		if(result[i-1]==0)
		{
			result[i]=1;
		}
			
		else if(result[i-3]==0)
		{
			result[i]=1;
		}
			
		else if(result[i-7]==0)
		{
			result[i]=1;
		}
		else if(result[i-8]==0)
		{
			result[i]=1;
		}

	}
}

void main()
{
		int i,n;
		int m[1000];
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&m[i]);
		}
		win_lose();
		for(i=0;i<n;i++)
		{
			printf("%d\n",result[m[i]]);
		}
		
       
}