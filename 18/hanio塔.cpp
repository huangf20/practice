
#include<stdio.h>
#include<cstdlib>
static int i=0;
void hanio(int n,char x,char y,char z)
{
	
	if (n==0)  return;
	hanio(n-1,x,z,y);
	printf("%15c------��%c\n",x,z);
	i++;
	hanio(n-1,y,x,z);
}
int main()
{
	int n;
	printf("             ������Ҫ�ƶ������ӵ�����\n");
	scanf("%d",&n);
	hanio(n,'a','b','c');
	printf("              һ����Ҫ�ƶ�%d������\n",i);
	return 0;
    system("pause");

}