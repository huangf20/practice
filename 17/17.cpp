#include<stdio.h>
#define M 3
#define N 3

int main()
{
	int a[M][N]={{1,2,3,},{4,5,6},{7,8,9}};
	int b[N][M];
	int i,j;
	for(i = 0;i < M;i++)
	{
		for(j = 0;j < N;j++)
		{
			printf(" %d",a[i][j]);
		}
		printf("\n");
		
		
	}
	printf("********\n");
	for(i = 0;i < N;i++)
	{
		for(j = 0;j < M;j++)
			b[i][j] = a[j][i];
		
	}
	for(i = 0;i < N;i++)
	{
		for(j = 0;j < M;j++)
		{
			printf(" %d",b[i][j]);
		}
		
		
		printf("\n");
	}
	
	
	
	
	return 0;
}
