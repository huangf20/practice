#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,t,b;
   char a[100];      //a�����ô���ת��ÿλ�����֣�
   char c[]="ABCDEF"; //c����������9��ÿλ�����֡� 
    scanf("%d",&n);
    
    t=n;
    t=(int)fabs(t); 
    for(i=0;;i++)
    {
     b=t%16;
      if(b>=10)
        a[i]=c[b-10];
        else
         a[i]=b+'0';
        t=(t-b)/16;
        if(t==0)
         break;
     }
     if(n<0)
      printf("-");
     for(;i>=0;i--)
      printf("%c",a[i]);
     printf("\n");
    return 0; 
}

