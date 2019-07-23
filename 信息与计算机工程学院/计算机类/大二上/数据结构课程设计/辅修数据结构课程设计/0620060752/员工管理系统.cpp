#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "conio.h"

typedef struct workers
{
char name[15];//����
char department[18];//��λ
char gender[7];//�Ա�
unsigned int age;//����
unsigned long telephone;//�绰
unsigned long wage;//����
unsigned long num;//ְ����
struct workers *next;
}workers,*lworkers;


void title();
int menu();
void avewage(lworkers head);
void deleteinfo(lworkers head);
void input(lworkers head);
void output(lworkers head);
void sortwage(lworkers head);
void search(lworkers head);
void change(lworkers head);

main()
{
	lworkers head;
	head=(workers *)malloc(sizeof(workers));
	head->next=NULL;	
	title();
	for(;;)
	{
		switch(menu())
		{
		case 1:
	     	input(head);
			break;
		case 2:
			output(head);
			break;
		case 3:
			search(head);
			break;	
		case 4:
			change(head);
			break;
		case 5:
			deleteinfo(head);
			break;
		case 6:
			sortwage(head);
			break;
		case 7:
			avewage(head);
			break;
		case 8:	
			exit(0);
		case 9:
			output(head);
				break;
		default:
			printf("���������������������룡");
		}
	}
	return 0;
}
void title()	
{
    printf(" \t\t\t Ա����Ϣ����ϵͳ\t\t\t     \n");
    printf(" \t\t\t  06�����4��\t   ��׼\t"  );	

}

int menu()
{
	int i;
	printf("\n\t\t**************************************************\n");
	printf("\t\t*\t\t1:����Ա����Ϣ:\t\t\t *\n");
	printf("\t\t*\t\t2:���Ա����Ϣ:\t\t\t *\n");
	printf("\t\t*\t\t3:����Ա����Ϣ:\t\t\t *\n");
	printf("\t\t*\t\t4:����Ա����Ϣ:\t\t\t *\n");
	printf("\t\t*\t\t5:ɾ��Ա����Ϣ:\t\t\t *\n");
	printf("\t\t*\t\t6:����Ա����Ϣ:\t\t\t *\n");
	printf("\t\t*\t\t7:Ա��ƽ������:\t\t\t *\n");
	printf("\t\t*\t\t8:�˳�\t\t\t\t *\n");
	printf("\t\t**************************************************\n");
	printf("\t\t����������ѡ�");
	scanf("%d",&i);
	return i;
}


void input(lworkers head)
{
	lworkers newnode,p,q;
	int i=1;
	printf("******************************************************************************\n");
	while(1)
	{  		
		newnode=(workers *)malloc(sizeof(workers));
		newnode->next=NULL;
		printf("������Ա����Ϣ:",i++);
		printf("\n������");
		scanf("%s",&newnode->name);
		if(!strcmp(newnode->name,"0"))
		{free(newnode);break;}
		else
		{			
			printf("��λ��");
			scanf("%s",&newnode->department);
			printf("�Ա�");
			scanf("%s",&newnode->gender);
			printf("���䣺");
			scanf("%d",&newnode->age);
			printf("�绰��");
			scanf("%ld",&newnode->telephone);
			printf("���ʣ�");
			scanf("%ld",&newnode->wage);
			printf("ְ���ţ�");
			scanf("%ld",&newnode->num);
	
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
				
						if(p->num==newnode->num)
						{
							printf("��ְ�����Ѿ����ڣ�����������ְ���ţ�");
							printf("ְ���ţ�");
							scanf("%ld",&newnode->num);
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

void output(lworkers head)
{
	lworkers current;
	current=head->next;
	if(current==NULL)
		printf("�Բ�����δ����Ա������Ϣ");
	else
	{
		printf("******************************************************************************\n");
		for(current=head->next;current;current=current->next)
		{
			printf("����:%s ",current->name);
			printf("��λ:%s ",current->department);
			printf("�Ա�:%s ",current->gender);
			printf("����:%d ",current->age);
			printf("�绰:%ld ",current->telephone);
			printf("����:%ld ",current->wage);
			printf("����:%ld \n",current->num);
		}
		printf("******************************************************************************\n");
	}
}



void search(lworkers head)
{
	char ch;
	int flg=0;
	lworkers current;
	current=head->next;
	char key[15];
	unsigned long key2; 
	printf("\t\t\t*************************************\n");
	printf("\t\t\t*       1:��Ա������������Ϣ��      *\n");
	printf("\t\t\t*       2:��Ա�����Ų�����Ϣ��      *\n");
	printf("\t\t\t*************************************\n");
	printf("\t\t\t����������ѡ�");getchar();
	scanf("%c",&ch);
	switch(ch)
	{
	case '1':
		printf("������Ҫ����Ա����������");
		scanf("%s",&key);
		if(current==NULL)
			printf("\t\t\tδ¼���κ�Ա����Ϣ\n");
		else
		{
			
			printf("******************************************************************************\n");
			for(current=head->next;current;current=current->next)
				if(strcmp(current->name,key)==0)	
				{
					flg=1;
					printf("����:%s ",current->name);
					printf("��λ:%s ",current->department);
					printf("�Ա�:%s ",current->gender);
					printf("����:%d ",current->age);
					printf("�绰:%ld ",current->telephone);
					printf("����:%ld ",current->wage);
					printf("����:%ld \n",current->num);
				}
				if(!flg)printf("\t\t�Բ���û�и�Ա����Ϣ\n");
			printf("******************************************************************************\n");
		
		}
		break;
	case '2':
		printf("������Ҫ����Ա���Ĺ��ţ�");
		scanf("%ld",&key2);
		if(current==NULL)
			printf("δ¼���κ�Ա����Ϣ\n");
		else
		{
			
			printf("******************************************************************************\n");
			for(current=head->next;current;current=current->next)
				if(current->num==key2)	
				{
					flg=1;
					printf("����:%s ",current->name);
					printf("��λ:%s ",current->department);
					printf("�Ա�:%s ",current->gender);
					printf("����:%d ",current->age);
					printf("�绰:%ld ",current->telephone);
					printf("����:%ld ",current->wage);
					printf("����:%ld \n",current->num);
				}
				if(!flg)printf("\t\t�Բ���û�и�Ա����Ϣ\n");

			printf("******************************************************************************\n");
		
		}

	}
}

void change(lworkers head)
{
	lworkers current;
	current=head->next;
	char key[15],ch;
	int flg=0;
	printf("���������������Ϣ��Ա����������");
	getchar();
	gets(key);
	if(current==NULL)
			printf("δ¼���κ�Ա����Ϣ\n");
		else
		{
			
		
			for(current=head->next;current;current=current->next)
				if(strcmp(current->name,key)==0)	
				{
					flg=1;
					    printf("�������µ�Ա��������");
						scanf("%s",&current->name);				
						printf("�������µ�Ա����λ��");
						scanf("%s",&current->department);					
						printf("�������µ�Ա���Ա�");
						scanf("%s",&current->gender);					
						printf("�������µ�Ա�����䣺");
						scanf("%d",&current->age);
						printf("�������µ�Ա���绰��");
						scanf("%ld",&current->telephone);					
						printf("�������µ�Ա�����ʣ�");
						scanf("%ld",&current->wage);					
						printf("�������µ�Ա��ְ���ţ�");
						scanf("%ld",&current->num);					
					printf("\t\t\t������ɣ��������������Ŀ¼\n");
					
				}
			if(!flg)printf("\t\t�Բ���û�и�Ա����Ϣ\n");
			printf("******************************************************************************\n");
		}
		getch();
}

void deleteinfo(lworkers head)
{
	lworkers current,q;
	current=head->next;
	q=head;
	int flg=0;
	char key[15],ch;
	printf("******************************************************************************\n");
	printf("������Ҫɾ��Ա����������");
	printf("******************************************************************************\n");
		scanf("%s",&key);
		if(current==NULL)
			printf("δ¼���κ�Ա����Ϣ\n");
		else
		{	
			for(current=head->next;current&&q;q=current,current=current->next)
				if(strcmp(current->name,key)==0)	
				{
					flg=1;
					printf("�Ƿ�ȷ��ɾ��Ա����Ϣ��y/n��?");
					getchar();
					scanf("%c",&ch);
					if(ch=='y'||ch=='Y')
					{
						q->next=current->next;						
					}
				}
				if(!flg)printf("\t\t�Բ���û�и�Ա����Ϣ\n");
		}
		printf("******************************************************************************\n");
}

void sortwage(lworkers head)
{
	lworkers p,q;
	int key;
	p=head->next;	
	if(p==NULL)
		printf("δ¼���κ�Ա����Ϣ\n");
	else if(p->next==NULL)	;	
	else
	{		
		for(q=head->next;q;q=q->next)
			for(p=q->next;p;p=p->next)
			{
				if(p->wage<q->wage)
				{
					key=p->wage;
					p->wage=q->wage;
					q->wage=key;
				}
			}
	}
	printf("\t\t\t���ʰ�����������ɣ�\n");
	output(head);
}

void avewage(lworkers head)
{
	int i;
	lworkers current;
	unsigned long wage=0;
	current=head->next;
	if(current==NULL)
			printf("δ¼���κ�Ա����Ϣ\n");
		else
		{
			
			printf("******************************************************************************\n");
			for(current=head->next,i=0;current;current=current->next,i++)
			{
				wage+=current->wage;
			}
			printf("Ա����ƽ������Ϊ��%ld\n",wage/i);
			printf("******************************************************************************\n");
		
		}
	

}
	
	
	
	
	




