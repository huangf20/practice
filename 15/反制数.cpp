#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
#include<math.h>  
  
int f(int n) 
{  
    int s =0;  
    char str[20];  
    int l;  
    int i;  
      
    itoa(n,str,10);  //itoaΪ������ת��Ϊ�ַ����ڵĺ���   10Ϊ����
    l = strlen(str);  
    for(i = l-1; i >= 0; i --)
	{
		s += (str[i]-48)*(int)pow(10,i);  
    }  
      
    return s;  
}  
  
int main () 
{  
      
    int a,b;  
      
    scanf("%d %d", &a, &b);  
  
    printf("%d\n",f(f(a)+f(b)));  
      
    return 0;  
}   
