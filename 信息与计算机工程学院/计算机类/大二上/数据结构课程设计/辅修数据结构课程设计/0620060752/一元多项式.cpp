#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

typedef struct node
{
	int xishu;
	int zhishu;
	struct node *next;
}node,*lnode;

void title();
int menu();
void input(lnode head);
void output(lnode head);
void sum(lnode head,lnode head2);
void cha(lnode head,lnode head2);
void multiply(lnode head,lnode head2);
main()
{
	lnode head,head2;
	head=(node *)malloc(sizeof(node));
	head->next=NULL;	
	head2=(node *)malloc(sizeof(node));
	head2->next=NULL;
	title();
	for(;;)
	{
		switch(menu())
		{
		case 1:
			input(head);
			break;
		case 2:
			input(head2);
			break;
		case 3:
			sum(head,head2);
			break;
		case 4:
			cha(head,head2);
			break;
		case 5:
			multiply(head,head2);
			break;
		case 6:
			exit(0);
			break;
		case 7:
			output(head2);
			break;
		default:
			printf("�Բ������������������������룡\n");
		}
	}

	return 0;
}
void title()	
{
    printf(" \t\t\tһԪ����ʽ����\t\t\t     \n");
    printf(" \t\t\t  06�����4��\t   ��׼\t"  );	

}

int menu()
{
	int i;
	printf("\n\t\t**************************************************\n");
	printf("\t\t*\t\t1:������һ��һԪ����ʽ:\t\t *\n");
	printf("\t\t*\t\t2:�����ڶ���һԪ����ʽ:\t\t *\n");
	printf("\t\t*\t\t3:ʵ����������ʽ�ļӷ�:\t\t *\n");
	printf("\t\t*\t\t4:ʵ����������ʽ�ļ���:\t\t *\n");
	printf("\t\t*\t\t5:ʵ����������ʽ�ĳ˷�:\t\t *\n");
	printf("\t\t*\t\t6:�˳�����\t\t\t *\n");
	printf("\t\t**************************************************\n");
	printf("\t\t����������ѡ�");
	scanf("%d",&i);
	return i;
}

void input(lnode head)
{
	lnode newnode,p,q;
	int i=1;
	printf("******************************************************************************\n");
	while(1)
	{  		
		newnode=(node *)malloc(sizeof(node));
		newnode->next=NULL;
		printf("�������%d���ϵ����ָ��:",i++);
		scanf("%d%d",&newnode->xishu,&newnode->zhishu);
		if(newnode->xishu==0)	
			break;
		else
		{
	
			if(head->next==NULL)
			{
				head->next=newnode;			
			}		
			else
			{
				p=head->next;
				q=head;
				while(p!=NULL)
				{
				
					if(p->zhishu<newnode->zhishu)
					{
						newnode->next=p;
						q->next=newnode;
						break;
					}
					else if(p->zhishu==newnode->zhishu)
					{
						p->xishu+=newnode->xishu;
						free(newnode);
						break;
					}
					else
					{
						q=p;
						p=p->next;
					}
				}
				if(p==NULL)
					q->next=newnode;	
			}

		}

	}
	printf("\t\t\t������ɣ�\n");
	printf("******************************************************************************\n");
	

}

void output(lnode head)
{
	int i=0;
	lnode current;
	current=head->next;
	if(current==NULL)
		printf("����ʽΪ0��\n");
	else
	{
		while(current!=0)
		{			
			if(i!=0&&current->xishu>0)
				printf("+");
			if(current->zhishu!=0)
				printf("%dX(%d)",current->xishu,current->zhishu);
			else
				printf("%d",current->xishu);
			current=current->next;
			i++;
		}
	}
}

void sum(lnode head,lnode head2)
{
	lnode p1,p2,p,sumhead;
	sumhead=(node *)malloc(sizeof(node));
	sumhead->next=NULL;
	p=sumhead;
	p1=head->next;
	p2=head2->next;	
	while(p1!=NULL||p2!=NULL)
	{
		lnode newnode;
		newnode=(node *)malloc(sizeof(node));
		newnode->next=NULL;
		if(p1!=NULL&&p2!=NULL)
		{
		
			if(p1->zhishu<p2->zhishu)
			{
				newnode->xishu=p2->xishu;
				newnode->zhishu=p2->zhishu;
				p->next=newnode;
				p=p->next;
				p2=p2->next;
			}
			else if(p1->zhishu>p2->zhishu)
			{
				newnode->xishu=p1->xishu;
				newnode->zhishu=p1->zhishu;
				p->next=newnode;
				p=p->next;
				p1=p1->next;
			}
			else
			{
				newnode->xishu=p2->xishu+p1->xishu;
				if(newnode->xishu==0)free(newnode);
				else
				{
					newnode->zhishu=p2->zhishu;
					p->next=newnode;
					p=p->next;
					p1=p1->next;
					p2=p2->next;
				}
				
				
			}		
		}
		else
		{
			if(p1==NULL)
			{
				newnode->xishu=p2->xishu;
				newnode->zhishu=p2->zhishu;
				p->next=newnode;
				p=p->next;
				p2=p2->next;
			}
			if(p2==NULL)
			{
				newnode->xishu=p1->xishu;
				newnode->zhishu=p1->zhishu;
				p->next=newnode;
				p=p->next;
				p1=p1->next;
			}
		}
	}
	printf("******************************************************************************\n");
	printf("����ʽ1��");
	output(head);
	printf("\n����ʽ2��");
	output(head2);
	printf("\n��������ʽ�ĺ�Ϊ��");
	output(sumhead);	
	printf("\n******************************************************************************\n");
}

void cha(lnode head,lnode head2)
{
	lnode p1,p2,p,sumhead;
	sumhead=(node *)malloc(sizeof(node));
	sumhead->next=NULL;
	p=sumhead;
	p1=head->next;
	p2=head2->next;	
	while(p1!=NULL||p2!=NULL)
	{
		lnode newnode;
		newnode=(node *)malloc(sizeof(node));
		newnode->next=NULL;
		if(p1!=NULL&&p2!=NULL)
		{
		
			if(p1->zhishu<p2->zhishu)
			{
				newnode->xishu=-p2->xishu;
				newnode->zhishu=p2->zhishu;
				p->next=newnode;
				p=p->next;
				p2=p2->next;
			}
			else if(p1->zhishu>p2->zhishu)
			{
				newnode->xishu=p1->xishu;
				newnode->zhishu=p1->zhishu;
				p->next=newnode;
				p=p->next;
				p1=p1->next;
			}
			else
			{
				newnode->xishu=-p2->xishu+p1->xishu;
				if(newnode->xishu==0)free(newnode);
				else
				{
					newnode->zhishu=p2->zhishu;
					p->next=newnode;
					p=p->next;
					p1=p1->next;
					p2=p2->next;
				}
				
				
			}		
		}
		else
		{
			if(p1==NULL)
			{
				newnode->xishu=-p2->xishu;
				newnode->zhishu=p2->zhishu;
				p->next=newnode;
				p=p->next;
				p2=p2->next;
			}
			if(p2==NULL)
			{
				newnode->xishu=p1->xishu;
				newnode->zhishu=p1->zhishu;
				p->next=newnode;
				p=p->next;
				p1=p1->next;
			}
		}
	}
	printf("******************************************************************************\n");
	printf("����ʽ1��");
	output(head);
	printf("\n����ʽ2��");
	output(head2);
	printf("\n��������ʽ�Ĳ�Ϊ��");
	output(sumhead);
	printf("\n******************************************************************************\n");
}

void multiply(lnode head,lnode head2)
{
	lnode p1,p2,p,q,sumhead;
	sumhead=(node *)malloc(sizeof(node));
	sumhead->next=NULL;
//	p=sumhead->next;
//	q=sumhead;
	p1=head->next;
	p2=head2->next;
	while(p1!=NULL)
	{
		p2=head2->next;
		while(p2!=NULL)
		{
			lnode newnode;
			newnode=(node *)malloc(sizeof(node));
			newnode->next=NULL;
			newnode->xishu=p1->xishu*p2->xishu;
			newnode->zhishu=p1->zhishu+p2->zhishu;
			if(sumhead->next==NULL)
			{
				sumhead->next=newnode;			
			}		
			else
			{	
				p=sumhead->next;
				q=sumhead;
				while(p!=NULL)
				{
				
					if(p->zhishu<newnode->zhishu)
					{
						newnode->next=p;
						q->next=newnode;
						break;
					}
					else if(p->zhishu==newnode->zhishu)
					{
						p->xishu+=newnode->xishu;
						free(newnode);
						break;
					}
					else
					{
						q=p;
						p=p->next;
					}
				}
				if(p==NULL)
					q->next=newnode;	
			}
			p2=p2->next;

		}
		p1=p1->next;
	}
	printf("******************************************************************************\n");
	printf("����ʽ1��");
	output(head);
	printf("\n����ʽ2��");
	output(head2);
	printf("\n��������ʽ�ĳ˻�Ϊ��");
	output(sumhead);
	printf("\n******************************************************************************\n");
}






