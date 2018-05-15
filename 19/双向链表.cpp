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

void ListInitiate(DLNode  **head )//初始化
{
	if((*head=(DLNode*)malloc(sizeof(DLNode)))==NULL)exit(0);
	(*head)->prior=*head;
	(*head)->next=*head;
}

int ListLength(DLNode *head)//求元素个数函数
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


int  ListInsert(DLNode *head,int i,DateType x)//插入数据
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
		printf("插入位置参数出错！");
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


int ListDelete(DLNode *head,int i,DateType*x)//删除数据元素
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
		printf("删除位置参数出错！");
			return 0;
	}

	p->prior->next=p->next;
	p->next->prior=p->prior;
	*x=p->date;
	free(p);
	return 1;
}



int ListGet(DLNode*head,int i,DateType *x)//取数据函数
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
		printf("取元素位置参数出错！");
		return 0;
	}
	*x=p->date;
	return 1;
}




void Destroy(DLNode**head)//摧毁函数
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


int ListSearch(DLNode*head,int i,DateType *x)//查找链表中有无数据i,无返回0，有返回1并将位置保存在x中
{
	int g=0;
	DLNode *p;                 
	p=head;//将p指向头指针
	*x=0;//位置赋值为0
	
	while(p->next!=head)//循环终止条件：p指向链表末尾或者p的date域等于i
	{
		g=g+1;
		p=p->next;
		*x=*x+1;
		if(p->date=i)
		{
			printf("查找成功！该数据在%d个位置\n",g);
		}
		
	}
	if(p->date!=i)//如果循环终止还未能找到与i相等的元素，查找失败返回0
	{
		printf("链表中无此元素！");
		return 0;
	}
	else return 1;

		


}
int ListChange(DLNode*head,int i,DateType x)//把位置为i的数据修改为x
{
	DLNode*p;
	int j=0;
	p=head;          //p指向头结点
	while(p->next!=head&&j<i)//循环终止条件：p指向链表末尾或者p指向位置为i的结点
	{
		p=p->next ;
        j++;
	}
	if(j!=i)        //如果i大于链表长度  返回0
	{
		printf("修改位置参数出错！");
		return 0;
	}
		
	else p->date=x;  //把指定位置的date域修改为x  返回1
	return 1;
}


void print(DLNode*head)
{
	int i,x;
		printf("当前数据为：\n");

	for(i=0;i<ListLength(head);i++)
	{
		if(ListGet(head,i,&x)==0)
		{
			printf("错误！\n");
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
			printf("错误！\n");
			return;
		}
	}


	print(head);

	

	
	printf("\n");
	printf("请输入要修改的数据位置和要修改成的数据:\n");
	scanf("%d%d",&n,&s);
	if(ListChange(head,n,s)==0)
		printf("错误！\n");
	else printf("修改成功！\n",s);
	print(head);
	ListDelete(head,4,&s);
	ListChange(head,5,5);
	print(head);

	








	Destroy(&head);








}