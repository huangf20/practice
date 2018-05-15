#include<stdio.h>
#include<string.h>
#include<stdlib.h >
#define SWAP(x,y,t) ((t) = (x),(x) = (y),(y) = (t))

void perm(char *list, int i, int n)
{
	int j, temp;
	if (i == n) //n表示字符串最后一位的下标
	{
		int j;
		for(j=0;j<strlen(list);j++)
		{
			printf("%c",list[j]);
			if((j+1)%3==0)
				printf(" ");
			
			
		}
	//	printf("\t%s\n", list);
		printf("\n");
	}
		else 
		{
			for (j = i; j <= n; j++)
			{
				SWAP(list[i], list[j], temp);//使用宏定义，传的是数值，如果这的swap用函数实现，传的应该是指针
                                         //交换位置后，输出以list[j]不变，后面的字母改变的所有排列
				perm(list, i + 1, n);
				SWAP(list[i], list[j], temp);
			}
		}
	}

void main()
{
	char list[] = "ABCEFGHIJ";
	perm(list, 0, strlen(list)-1);
	system("pause");
}