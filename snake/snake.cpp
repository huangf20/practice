#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include <stdio.h>

typedef struct
{
	int x;
	int y;
}pos;
pos head,speed,body[1000],food;
int length,score;
int flag=0;//���ӵ�һ����ǩ������Ϸ��ʼ֮��Ż���ʾ����
COLORREF f_color,b_color;//ʳ����ɫ��������ɫ



void initsnake()
{
	flag=1;
	int i;
	score=0;
	initgraph(800,600);
	setbkcolor(WHITE);
	cleardevice();


    setlinecolor(BLACK);
	setlinestyle(PS_DASH|PS_JOIN_MITER,2);
	line(0,200,500,200);
	line(500,200,500,600);
	line(0,200,0,600);
	line(0,600,500,600);


	head.x=400;
	head.y=300;
	speed.x=1;
	speed.y=0;
	food.x=(rand()%480)+10;
	food.y=(rand()%380)+210; 
	for(i=0;i<=7;i++)
	{
		body[i].x=395-i*5;
		body[i].y=300; 
	}
	length=7;
	f_color=RGB(rand()%255,rand()%255,rand()%255);
	b_color=BLACK;
	{
		settextcolor(BLACK);
		settextstyle(40, 0, _T("����"));
		outtextxy(20, 20, _T("snake 1.0"));
		
        settextcolor(RGB(33,187,239));
		settextstyle(25, 0, _T("����"));
		outtextxy(150, 80, _T("By--H.F."));


        settextcolor(BLACK);
		settextstyle(30, 0, _T("΢���ź�"));
		outtextxy(530, 250, _T("��ĵ÷֣�"));
		
        settextcolor(GREEN);
		settextstyle(18, 0, _T("����"));
		outtextxy(520, 400, _T("�����������С�ߵ��ƶ�"));

	}
	




}

void print()
{
	int i; 
	setcolor(f_color);             //��ʳ��
    setfillcolor(f_color);
	fillcircle(food.x,food.y,3  );


	for(i=0;i<length;i++)//������
	{
		setlinecolor(b_color);
		setlinestyle(PS_JOIN_ROUND,7);
		line(body[i].x,body[i].y,body[i+1].x,body[i+1].y);

	}
	setcolor(BLACK);//����ͷ
	setfillcolor(BLACK);
	fillcircle(head.x ,head.y ,3);


	if(flag)
	{
		settextcolor(BLACK);        //��ʾ����
	settextstyle(30, 0, _T("΢���ź�"));
	char s[5];
	sprintf(s, "%d", score);
	outtextxy(650,250, s);
	}
	



	
	
    FlushBatchDraw();

		Sleep(50);

    for(i=0;i<length;i++)//����ǰһ֡����
	{
		setlinecolor(WHITE);
		setlinestyle(PS_JOIN_ROUND,7);
		line(body[i].x,body[i].y,body[i+1].x,body[i+1].y);

	}
	setcolor(WHITE);
	setfillcolor(WHITE);
	fillcircle(head.x ,head.y ,5);

	setcolor(WHITE);             //����ǰһ֡��ʳ��
    setfillcolor(WHITE);
	fillcircle(food.x,food.y,3  );
	
	

}

void snake_move()
{
	int i;
	head.x=head.x+(speed.x)*5;
	head.y=head.y+(speed.y)*5;
	if(speed.x||speed.y )    //�����ƶ�����������ͷ�������ٶȣ���Ȼ���ƶ�
	{
		for(i=length;i>0;i--)
		{
			body[i].x=body[i-1].x;
			body[i].y=body[i-1].y;
		}
		body[0].x=head.x;body[0].y=head.y;
	}
	 
	 
	

}

void turn()
{
	char c;
	
	if(kbhit())
	{
		c=getch();
		if(c=='w'||c==72)
		{
			if(speed.x!=0&&speed.y!=1)
			{
				speed.x=0;
				speed.y=-1; 
			}
			
			
		}
		if(c=='s'||c==80)
		{
			if(speed.x!=0&&speed.y!=-1)
			{
				speed.x=0;
				speed.y=1; 
			}
			
			
		}
		if(c=='a'||c==75)
		{
			if(speed.x!=1&&speed.y!=0)
			{
				speed.x=-1;
				speed.y=0; 

			}
			
			
		}
		if(c=='d'||c==77)
		{
			if(speed.x!=-1&&speed.y!=0)
			{
				speed.x=1;
				speed.y=0; 
			}
			
			
		}
	}


}

void snake_add()
{
	int i;
	if((head.x-food.x)*(head.x-food.x)+(head.y-food.y)*(head.y-food.y)<=36)
	{
		length++;
		score++;
		for(i=length;i>0;i--)
		{
			body[i].x=body[i-1].x;  
			body[i].y=body[i-1].y;
		}
		body[0].x=head.x;
		body[0].y=head.y;

		head.x=food.x;  
		head.y=food.y;
		food.x=(rand()%480)+10;
		food.y=(rand()&380)+210;
		b_color=f_color;
		f_color=RGB(rand()%255,rand()%255,rand()%255);
		


	}
}

void death()
{
	int i,d=0;

	for(i=length;i>1;i--)
	{
		if(head.x==body[i].x&&head.y==body[i].y )
			d= 1;
	}
	if(head.x<=3||head.x>=497||head.y<=203||head.y>=597)
		d=1;
	if(d==1)
	{
		settextcolor(RED);
		settextstyle(25, 0, _T("΢���ź�"));
		outtextxy(510, 520, _T("��Ϸ���� �������ϼ��˳�"));
		outtextxy(510, 550, _T("    ��������������¿�ʼ"));
		speed.x=0;
		speed.y=0;

          char c;
	
	    if(kbhit())
		{
			c=getch();
			if(c==72)
			exit(0);
			else
			initsnake();

		}
		

	}
	
	

}


void welcom()    //��ӭ����
{
	int i;
	initgraph(800,600);
	setbkcolor(WHITE);
	cleardevice();

    settextcolor(BLACK);
	settextstyle(20, 0, _T("����"));
	outtextxy(600, 100, _T("��  С�����ڳ���"));


   


	head.x=200;
	head.y=300;
	speed.x=1;
	speed.y=0;
	food.x=400;
	food.y=300 ;
	for(i=0;i<=45;i++)
	{
		body[i].x=200-i*5;
		body[i].y=300; 
	}
	length=45;
	f_color=RGB(rand()%255,rand()%255,rand()%255);
	b_color=RGB(rand()%255,rand()%255,rand()%255);


	BeginBatchDraw();

	while(head.y>-100 )
	{
		print();
		snake_move();
		if((head.x-food.x)*(head.x-food.x)+(head.y-food.y)*(head.y-food.y)<=36)
		{
			b_color=f_color;
			food.x =-100;
		}
		
		
		if(head.x==325&&head.y==300)
		{
			speed.x=0;
			speed.y=-1; 
		}
		if(head.x==325&&head.y==225)
		{
			speed.x=1;
			speed.y=0; 
		}
		if(head.x==475&&head.y==225)
		{
			speed.x=0;
			speed.y=1; 
		}
		if(head.x==475&&head.y==375)
		{
			speed.x=-1;
			speed.y=0; 
		}
		if(head.x==400&&head.y==375)
		{
			speed.x=0;
			speed.y=-1; 
		}
		
		
		 
		
		

	}
    EndBatchDraw();
	cleardevice();
	
		LOGFONT f;
		gettextstyle(&f);                     // ��ȡ��ǰ��������
		f.lfHeight = 100;                      // ��������߶�Ϊ 100
		_tcscpy(f.lfFaceName, _T("��������"));    // ��������Ϊ
		f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����  
		settextstyle(&f);                     // ����������ʽ
		settextcolor(BLACK);
		outtextxy(250, 200, _T("̰����"));

		settextstyle(16, 0, _T("����"));
		outtextxy(340, 330, _T("���������ʼ��Ϸ"));
		getch();
        outtextxy(360, 530, _T("WAITING......"));
		Sleep(2000);

}
void main()
{
	welcom();
	initsnake();
	BeginBatchDraw();


	while(1)
	{
		
		

		
		snake_move();
		print();
		snake_add();
		turn();
		death();
		
			
		
		
		
	}

	getch();
	EndBatchDraw();
	closegraph();
	
}