#include<stdio.h>
#include<string.h>
#include<stdlib.h >
#define SWAP(x,y,t) ((t) = (x),(x) = (y),(y) = (t))

void perm(char *list, int i, int n)
{
	int j, temp;
	if (i == n) //n��ʾ�ַ������һλ���±�
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
				SWAP(list[i], list[j], temp);//ʹ�ú궨�壬��������ֵ��������swap�ú���ʵ�֣�����Ӧ����ָ��
                                         //����λ�ú������list[j]���䣬�������ĸ�ı����������
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