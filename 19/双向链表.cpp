#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef int DateType;

typedef struct Node
{
	DateType date;
	struct Node *next;
	struct Node *prior;
}DLNode;

void ListInitiate(DLNode  **head )//��ʼ��
{
	if((*head=(DLNode*)malloc(sizeof(DLNode)))==NULL)exit(0);
	(*head)->prior=*head;
	(*head)->next=*head;
}

int ListLength(DLNode *head)//��Ԫ�ظ�������
{
	DLNode *p=head;
	int size=0;
	while(p->next!=head)
	{
		p=p->next;
		size++;
	}
	return size;

}


int  ListInsert(DLNode *head,int i,DateType x)//��������
{
	DLNode *p,*s;
	int j;

	p=head->next;
	j=0;
	while(p!=head&&j<i)
	{
		p=p->next;
		j++;
	}
	if(j!=i)
	{
		printf("����λ�ò�������");
		return 0;
	}
	if((s=(DLNode*)malloc(sizeof(DLNode)))==NULL)exit(0);
	s->date=x;
	s->prior=p->prior;
	p->prior->next=s;
	s->next=p;
	p->prior=s;
	return 1;

}


int ListDelete(DLNode *head,int i,DateType*x)//ɾ������Ԫ��
{
	DLNode*p;
	int j;
	p=head->next;
	j=0;
	while(p->next!=head&&j<i)
	{
		p=p->next;
		j++;
	}
	if(j!=i)
	{
		printf("ɾ��λ�ò�������");
			return 0;
	}

	p->prior->next=p->next;
	p->next->prior=p->prior;
	*x=p->date;
	free(p);
	return 1;
}



int ListGet(DLNode*head,int i,DateType *x)//ȡ���ݺ���
{
	DLNode *p;
	int j;
	p=head;
	j=-1;
	while(p->next!=head&&j<i)
	{
		p=p->next;
		j++;
	}
	if(j!=i)
	{
		printf("ȡԪ��λ�ò�������");
		return 0;
	}
	*x=p->date;
	return 1;
}




void Destroy(DLNode**head)//�ݻٺ���
{
	DLNode*p,*p1;
	int i,n=ListLength(*head);
	p=*head;
	for(i=0;i<n;i++)
	{
		p1=p;
		p=p->next;
		free(p1);
	}
	*head=NULL;
}


int ListSearch(DLNode*head,int i,DateType *x)//������������������i,�޷���0���з���1����λ�ñ�����x��
{
	int g=0;
	DLNode *p;                 
	p=head;//��pָ��ͷָ��
	*x=0;//λ�ø�ֵΪ0
	
	while(p->next!=head)//ѭ����ֹ������pָ������ĩβ����p��date�����i
	{
		g=g+1;
		p=p->next;
		*x=*x+1;
		if(p->date=i)
		{
			printf("���ҳɹ�����������%d��λ��\n",g);
		}
		
	}
	if(p->date!=i)//���ѭ����ֹ��δ���ҵ���i��ȵ�Ԫ�أ�����ʧ�ܷ���0
	{
		printf("�������޴�Ԫ�أ�");
		return 0;
	}
	else return 1;

		


}
int ListChange(DLNode*head,int i,DateType x)//��λ��Ϊi�������޸�Ϊx
{
	DLNode*p;
	int j=0;
	p=head;          //pָ��ͷ���
	while(p->next!=head&&j<i)//ѭ����ֹ������pָ������ĩβ����pָ��λ��Ϊi�Ľ��
	{
		p=p->next ;
        j++;
	}
	if(j!=i)        //���i����������  ����0
	{
		printf("�޸�λ�ò�������");
		return 0;
	}
		
	else p->date=x;  //��ָ��λ�õ�date���޸�Ϊx  ����1
	return 1;
}


void print(DLNode*head)
{
	int i,x;
		printf("��ǰ����Ϊ��\n");

	for(i=0;i<ListLength(head);i++)
	{
		if(ListGet(head,i,&x)==0)
		{
			printf("����\n");
			return;
		}
		else printf("%d    ",x);
	
	}
		printf("\n");

}

void main(void)
{


	DLNode*head;
	int i,x,n,s;

	ListInitiate(&head);
	for(i=0;i<10;i++)
	{
		if(ListInsert(head,i,2*(i+1))==0)
		{
			printf("����\n");
			return;
		}
	}


	print(head);

	

	
	printf("\n");
	printf("������Ҫ�޸ĵ�����λ�ú�Ҫ�޸ĳɵ�����:\n");
	scanf("%d%d",&n,&s);
	if(ListChange(head,n,s)==0)
		printf("����\n");
	else printf("�޸ĳɹ���\n",s);
	print(head);
	ListDelete(head,4,&s);
	ListChange(head,5,5);
	print(head);

	








	Destroy(&head);








}