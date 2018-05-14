#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,t,b;
   char a[100];      //a数组用储存转后每位的数字，
   char c[]="ABCDEF"; //c用来代表超过9后每位的数字。 
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

