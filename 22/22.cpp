#include<stdio.h>
int main()
{
 int a[10];
 int i,j,k;
 int t;
 printf("Input 10 integer:\n");
 for(i = 0;i < 10;i++)
  scanf("%d",&a[i]);
 for(i = 0;i < 10;i++)
  for(j = 0;j < 10-i-1;j++)
   if(a[j] > a[j+1])
   {
    t = a[j];
    a[j] = a[j+1];
    a[j+1] = t;
   }
 printf("k=");
 scanf("%d",&k);
 printf("%d\n",a[10-k]);


 return 0;
}
