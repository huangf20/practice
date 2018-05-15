
#include<stdio.h>
#include<cstdlib>
static int i=0;
void hanio(int n,char x,char y,char z)
{
	
	if (n==0)  return;
	hanio(n-1,x,z,y);
	printf("%15c------→%c\n",x,z);
	i++;
	hanio(n-1,y,x,z);
}
int main()
{
	int n;
	printf("             输入需要移动的盘子的数量\n");
	scanf("%d",&n);
	hanio(n,'a','b','c');
	printf("              一共需要移动%d次盘子\n",i);
	return 0;
    system("pause");

}