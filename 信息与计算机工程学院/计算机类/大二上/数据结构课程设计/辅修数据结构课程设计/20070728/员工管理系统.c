#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct workers
{
	char num[10];//ְ����
    char name[15];//����
    char  department[18];//��λ
    char gender[5];//�Ա�
    char age[5];//����
    char telephone[15];//�绰
    char wage[10];//����
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
		printf("������ְ����:\n ");
		scanf("%s",p->data.num);
        printf("����������:\n ");
		scanf("%s",p->data.name);
        printf("������ְ����λ:\n ");
		scanf("%s",p->data.department);
		printf("������ְ���Ա�:\n ");
		scanf("%s",p->data.gender);
		printf("������ְ������:\n ");
		scanf("%s",p->data.age);
		printf("������ְ���绰:\n ");
		scanf("%s",p->data.telephone);
        printf("������ְ������:\n ");
		scanf("%s",p->data.age);
        rear->next=p;
        rear=p;
        printf("����������?(1����/0����)");
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
    printf("1. ����Ų�ѯ   \n");
    printf("2. ��������ѯ   \n");
    printf("    ��ѡ��      \n");
    p=head->next;
    scanf("%d",&xz);
    if(xz==1){
	   printf("������Ҫ����Ա���ı��: ");
       scanf("%s",num);
	   while(p&&(strcmp(p->data.num,num)<0))
       p=p->next;
       if(p==NULL||(strcmp(p->data.num,num)<0))
       p=NULL;
   }
   else if(xz==2)
   {
	   printf("������Ҫ����Ա��������: ");
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
		printf("û�в鵽Ҫɾ����Ա��!\n");
		return;
	}
	printf("Ҫɾ����Ա����Ϣ��?(y/n):\n");
	scanf("%c",&jx);
    if(jx=='y')
	{
		q=head;
		while(q!=NULL&&q->next!=p)
			q=q->next;
		q->next=p->next;
		free(p);
		printf("��Ա����Ϣ��ɾ��!\n");
	}
}
void PrintList(LinkList head)
{
	ListNode *p;
	p=head->next;
	printf("ְ����    ����    ��λ    �Ա�    ����    �绰    ����\n ");
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
		printf("������ְ����:\n ");
		scanf("%s",p->data.num);
        printf("����������:\n ");
		scanf("%s",p->data.name);
        printf("������ְ����λ:\n ");
		scanf("%s",p->data.department);
		printf("������ְ���Ա�:\n ");
		scanf("%s",p->data.gender);
		printf("������ְ������:\n ");
		scanf("%s",p->data.age);
		printf("������ְ���绰:\n ");
		scanf("%s",p->data.telephone);
        printf("������ְ������:\n ");
		scanf("%s",p->data.age);
        printf("�����޸ĳɹ�!\n"); 
	} 
 } 
void main()
{
	int n;
    for(;;)
	{
		printf("********************************************************************************");
        printf("\t1����Ա����Ϣ\t\t\t\t\t2����Ա����Ϣ\n");
        printf("\t3��ѯԱ����Ϣ\t\t\t\t\t4ɾ��Ա����Ϣ\n");
        printf("\t5����Ա����Ϣ\t\t\t\t\t6���Ա����Ϣ\n");
        printf("\t0�˳�ϵͳ\n");
		printf("********************************************************************************");
        printf("��ѡ��: \n");
        scanf("%d",&n);
        switch(n)
		{
		case 1:
        printf("����Ա����Ϣ\n");
        head=CreateList();
        break;
		case 2:
	    printf("����Ա����Ϣ:\n");
		p=(ListNode *)malloc(sizeof(ListNode));
		printf("������ְ����:\n ");
		scanf("%s",p->data.num);
        printf("����������:\n ");
		scanf("%s",p->data.name);
        printf("������ְ����λ:\n ");
		scanf("%s",p->data.department);
		printf("������ְ���Ա�:\n ");
		scanf("%s",p->data.gender);
		printf("������ְ������:\n ");
		scanf("%s",p->data.age);
		printf("������ְ���绰:\n ");
		scanf("%s",p->data.telephone);
        printf("������ְ������:\n ");
		scanf("%s",p->data.age);
		InsertNode(head,p);
		break;
		case 3:
			printf("��ѯԱ����Ϣ\n");
		    p=ListFind(head);
		    if(p!=NULL)
			{
				printf("ְ����   ����   ��λ   �Ա�   ����   �绰   ����\n ");
				printf("%s\t%s\t%\t%s\t%s\t%s\t%s\n",p->data.num,p->data.name,p->data.department,p->data.gender,p->data.age,p->data.telephone,p->data.wage);
			}
			else
				printf("û�в鵽Ҫ��ѯ��Ա��\n");
			break;
		case 4:
			printf("ɾ��Ա����Ϣ\n");
            DelNode(head);
		    break;

		case 5:
			Modify(head);
			break;
		case 6:
			printf("���Ա����Ϣ\n");
		    PrintList(head);
			break;
		case 0:
			printf("�˳�ϵͳ\n");
		    return;
		}
	}
}


