#include<stdio.h>
#include<string.h>

void main()
{
	char a[1000],b[1000],c[1000],d[1000];//�����ĸ����飬a��b�������������������֣�c��d�������мӷ�����
	char figure[1000];                  //figure����������Ž��
	int i,length,add[1000]={0};         //length��ʾ���������������󳤶ȣ�add��Ž�λ��1��0��


	scanf("%s%s",a,b);
	length=strlen(a)>strlen(b)?strlen(a):strlen(b);

	for(i=0;i<length;i++)              //��c��d���г�ʼ����ʹȫ����ԱΪ'0'���������ļӷ�����
	{
		c[i]='0';
		d[i]='0';
	}
	for(i=(strlen(a))-1;i>=0;i--)     //��c��d��a��b�ĳ�Ա˳��ת���������
	{
		c[strlen(a)-1-i]=a[i];
	}
	for(i=(strlen(b))-1;i>=0;i--)
	{
		d[strlen(b)-1-i]=b[i];
	}



	for(i=0;i<length;i++)           //�ӷ�����
	{
		if(i>0)
		{
			figure[i]=((c[i]-'0')+(d[i]-'0')+add[i-1])+'0';//��ǰλ����ֵ����a b��ǰλ����ֵ֮�ͼ��ϵ�λ�Ľ�λ
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

	if(add[length-1]==1)              //������λ�н�λ�������λ��һλ����ֵΪ1
	{
		length++;
		figure[length-1]='1';

	}


	for(i=length-1;i>=0;i--)//������
	{
		printf("%c",figure[i]);
		
			
	}
	printf("\n");
	/*
	printf("\n��λ��\n");
	
	for(i=length-1;i>=0;i--)
	{
		printf("%d",add[i]);
	
	}
	printf("\n");
	*/




}
