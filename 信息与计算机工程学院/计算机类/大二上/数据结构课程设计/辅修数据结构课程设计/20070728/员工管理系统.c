#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct workers
{
	char num[10];//职工号
    char name[15];//姓名
    char  department[18];//单位
    char gender[5];//性别
    char age[5];//年龄
    char telephone[15];//电话
    char wage[10];//工资
};
typedef struct node
{
	struct workers data;
    struct node *next;
}ListNode;
typedef ListNode *LinkList;
LinkList head;
ListNode *p;
LinkList CreateList()
{
	LinkList head=(ListNode *)malloc(sizeof(ListNode));
    ListNode *p,*rear;
    int flag=0;
    rear=head;
    while(flag==0)
	{
		p=(ListNode *)malloc(sizeof(ListNode));
		printf("请输入职工号:\n ");
		scanf("%s",p->data.num);
        printf("请输入姓名:\n ");
		scanf("%s",p->data.name);
        printf("请输入职工单位:\n ");
		scanf("%s",p->data.department);
		printf("请输入职工性别:\n ");
		scanf("%s",p->data.gender);
		printf("请输入职工年龄:\n ");
		scanf("%s",p->data.age);
		printf("请输入职工电话:\n ");
		scanf("%s",p->data.telephone);
        printf("请输入职工工资:\n ");
		scanf("%s",p->data.age);
        rear->next=p;
        rear=p;
        printf("结束建表吗?(1结束/0继续)");
        scanf("%d",&flag);
	}
	rear->next=NULL;
	return head;
}
void InsertNode(LinkList head,ListNode *p)
{
	ListNode *p1,*p2;
    p1=head;
    p2=p1->next;
    while(p2!=NULL&&(strcmp(p2->data.num,p->data.num)<0))
	{
		p1=p2;
        p2=p2->next;
	}
	p1->next=p;
    p->next=p2;
}
ListNode *ListFind(LinkList head)
{
	ListNode *p;
    char num[10];
    char name[15];
    int xz;
    printf("1. 按编号查询   \n");
    printf("2. 按姓名查询   \n");
    printf("    请选择      \n");
    p=head->next;
    scanf("%d",&xz);
    if(xz==1){
	   printf("请输入要查找员工的编号: ");
       scanf("%s",num);
	   while(p&&(strcmp(p->data.num,num)<0))
       p=p->next;
       if(p==NULL||(strcmp(p->data.num,num)<0))
       p=NULL;
   }
   else if(xz==2)
   {
	   printf("请输入要查找员工的姓名: ");
       scanf("%s",name);
	   while(p&&strcmp(p->data.name,name)!=0)
		   p=p->next;
   }
   return p;
}
void DelNode(LinkList head)
{
	char jx;
    ListNode *p,*q;
    p=ListFind(head);
    if(p==NULL)
	{
		printf("没有查到要删除的员工!\n");
		return;
	}
	printf("要删除该员工信息吗?(y/n):\n");
	scanf("%c",&jx);
    if(jx=='y')
	{
		q=head;
		while(q!=NULL&&q->next!=p)
			q=q->next;
		q->next=p->next;
		free(p);
		printf("该员工信息已删除!\n");
	}
}
void PrintList(LinkList head)
{
	ListNode *p;
	p=head->next;
	printf("职工号    姓名    单位    性别    年龄    电话    工资\n ");
	while(p!=NULL)
	{
		printf("%s\t%s\t%\t%s\t%s\t%s\t%s\n",p->data.num,p->data.name,p->data.department,p->data.gender,p->data.age,p->data.telephone,p->data.wage);
        p=p->next;
	}
}
void Modify(head) 
{ 
	ListNode *p;  
    p=ListFind(head); 
	if(p) 
	{ 
		printf("请输入职工号:\n ");
		scanf("%s",p->data.num);
        printf("请输入姓名:\n ");
		scanf("%s",p->data.name);
        printf("请输入职工单位:\n ");
		scanf("%s",p->data.department);
		printf("请输入职工性别:\n ");
		scanf("%s",p->data.gender);
		printf("请输入职工年龄:\n ");
		scanf("%s",p->data.age);
		printf("请输入职工电话:\n ");
		scanf("%s",p->data.telephone);
        printf("请输入职工工资:\n ");
		scanf("%s",p->data.age);
        printf("资料修改成功!\n"); 
	} 
 } 
void main()
{
	int n;
    for(;;)
	{
		printf("********************************************************************************");
        printf("\t1输入员工信息\t\t\t\t\t2插入员工信息\n");
        printf("\t3查询员工信息\t\t\t\t\t4删除员工信息\n");
        printf("\t5更新员工信息\t\t\t\t\t6输出员工信息\n");
        printf("\t0退出系统\n");
		printf("********************************************************************************");
        printf("请选择: \n");
        scanf("%d",&n);
        switch(n)
		{
		case 1:
        printf("输入员工信息\n");
        head=CreateList();
        break;
		case 2:
	    printf("插入员工信息:\n");
		p=(ListNode *)malloc(sizeof(ListNode));
		printf("请输入职工号:\n ");
		scanf("%s",p->data.num);
        printf("请输入姓名:\n ");
		scanf("%s",p->data.name);
        printf("请输入职工单位:\n ");
		scanf("%s",p->data.department);
		printf("请输入职工性别:\n ");
		scanf("%s",p->data.gender);
		printf("请输入职工年龄:\n ");
		scanf("%s",p->data.age);
		printf("请输入职工电话:\n ");
		scanf("%s",p->data.telephone);
        printf("请输入职工工资:\n ");
		scanf("%s",p->data.age);
		InsertNode(head,p);
		break;
		case 3:
			printf("查询员工信息\n");
		    p=ListFind(head);
		    if(p!=NULL)
			{
				printf("职工号   姓名   单位   性别   年龄   电话   工资\n ");
				printf("%s\t%s\t%\t%s\t%s\t%s\t%s\n",p->data.num,p->data.name,p->data.department,p->data.gender,p->data.age,p->data.telephone,p->data.wage);
			}
			else
				printf("没有查到要查询的员工\n");
			break;
		case 4:
			printf("删除员工信息\n");
            DelNode(head);
		    break;

		case 5:
			Modify(head);
			break;
		case 6:
			printf("输出员工信息\n");
		    PrintList(head);
			break;
		case 0:
			printf("退出系统\n");
		    return;
		}
	}
}


