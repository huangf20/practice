#include<stdio.h>
#include<string.h>

void main()
{
	char a[1000],b[1000],c[1000],d[1000];//定义四个数组，a、b用来存放输入的两个数字，c、d用来进行加法操作
	char figure[1000];                  //figure数组用来存放结果
	int i,length,add[1000]={0};         //length表示输入两个数组的最大长度，add存放进位（1或0）


	scanf("%s%s",a,b);
	length=strlen(a)>strlen(b)?strlen(a):strlen(b);

	for(i=0;i<length;i++)              //对c，d进行初始化，使全部成员为'0'，方便后面的加法计算
	{
		c[i]='0';
		d[i]='0';
	}
	for(i=(strlen(a))-1;i>=0;i--)     //令c、d与a、b的成员顺序反转，方便计算
	{
		c[strlen(a)-1-i]=a[i];
	}
	for(i=(strlen(b))-1;i>=0;i--)
	{
		d[strlen(b)-1-i]=b[i];
	}



	for(i=0;i<length;i++)           //加法计算
	{
		if(i>0)
		{
			figure[i]=((c[i]-'0')+(d[i]-'0')+add[i-1])+'0';//当前位的数值等于a b当前位的数值之和加上低位的进位
			add[i]=(figure[i]-'0')/10;
			figure[i]=(figure[i]-'0')%10+'0';
		}
		if(i==0)
		{
			figure[i]=((c[i]-'0')+(d[i]-'0'))+'0';
			add[i]=(figure[i]-'0')/10;
			figure[i]=(figure[i]-'0')%10+'0';


		}
		
		
		
	}

	if(add[length-1]==1)              //如果最高位有进位，则向高位进一位，数值为1
	{
		length++;
		figure[length-1]='1';

	}


	for(i=length-1;i>=0;i--)//输出结果
	{
		printf("%c",figure[i]);
		
			
	}
	printf("\n");
	/*
	printf("\n进位：\n");
	
	for(i=length-1;i>=0;i--)
	{
		printf("%d",add[i]);
	
	}
	printf("\n");
	*/




}
