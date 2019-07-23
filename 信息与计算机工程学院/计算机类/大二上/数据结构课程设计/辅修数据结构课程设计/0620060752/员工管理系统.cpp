#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "conio.h"

typedef struct workers
{
char name[15];//姓名
char department[18];//单位
char gender[7];//性别
unsigned int age;//年龄
unsigned long telephone;//电话
unsigned long wage;//工资
unsigned long num;//职工号
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
			printf("您的输入有误，请重新输入！");
		}
	}
	return 0;
}
void title()	
{
    printf(" \t\t\t 员工信息管理系统\t\t\t     \n");
    printf(" \t\t\t  06计算机4班\t   宋准\t"  );	

}

int menu()
{
	int i;
	printf("\n\t\t**************************************************\n");
	printf("\t\t*\t\t1:输入员工信息:\t\t\t *\n");
	printf("\t\t*\t\t2:输出员工信息:\t\t\t *\n");
	printf("\t\t*\t\t3:查找员工信息:\t\t\t *\n");
	printf("\t\t*\t\t4:更改员工信息:\t\t\t *\n");
	printf("\t\t*\t\t5:删除员工信息:\t\t\t *\n");
	printf("\t\t*\t\t6:排序员工信息:\t\t\t *\n");
	printf("\t\t*\t\t7:员工平均工资:\t\t\t *\n");
	printf("\t\t*\t\t8:退出\t\t\t\t *\n");
	printf("\t\t**************************************************\n");
	printf("\t\t请输入您的选项：");
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
		printf("请输入员工信息:",i++);
		printf("\n姓名：");
		scanf("%s",&newnode->name);
		if(!strcmp(newnode->name,"0"))
		{free(newnode);break;}
		else
		{			
			printf("单位：");
			scanf("%s",&newnode->department);
			printf("性别：");
			scanf("%s",&newnode->gender);
			printf("年龄：");
			scanf("%d",&newnode->age);
			printf("电话：");
			scanf("%ld",&newnode->telephone);
			printf("工资：");
			scanf("%ld",&newnode->wage);
			printf("职工号：");
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
							printf("该职工号已经存在，请重新输入职工号：");
							printf("职工号：");
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
	printf("\t\t\t创建完成！\n");
	printf("******************************************************************************\n");
}

void output(lworkers head)
{
	lworkers current;
	current=head->next;
	if(current==NULL)
		printf("对不起，您未输入员工的信息");
	else
	{
		printf("******************************************************************************\n");
		for(current=head->next;current;current=current->next)
		{
			printf("姓名:%s ",current->name);
			printf("单位:%s ",current->department);
			printf("性别:%s ",current->gender);
			printf("年龄:%d ",current->age);
			printf("电话:%ld ",current->telephone);
			printf("工资:%ld ",current->wage);
			printf("工号:%ld \n",current->num);
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
	printf("\t\t\t*       1:按员工姓名查找信息：      *\n");
	printf("\t\t\t*       2:按员工工号查找信息：      *\n");
	printf("\t\t\t*************************************\n");
	printf("\t\t\t请输入您的选项：");getchar();
	scanf("%c",&ch);
	switch(ch)
	{
	case '1':
		printf("请输入要查找员工的姓名：");
		scanf("%s",&key);
		if(current==NULL)
			printf("\t\t\t未录入任何员工信息\n");
		else
		{
			
			printf("******************************************************************************\n");
			for(current=head->next;current;current=current->next)
				if(strcmp(current->name,key)==0)	
				{
					flg=1;
					printf("姓名:%s ",current->name);
					printf("单位:%s ",current->department);
					printf("性别:%s ",current->gender);
					printf("年龄:%d ",current->age);
					printf("电话:%ld ",current->telephone);
					printf("工资:%ld ",current->wage);
					printf("工号:%ld \n",current->num);
				}
				if(!flg)printf("\t\t对不起，没有该员工信息\n");
			printf("******************************************************************************\n");
		
		}
		break;
	case '2':
		printf("请输入要查找员工的工号：");
		scanf("%ld",&key2);
		if(current==NULL)
			printf("未录入任何员工信息\n");
		else
		{
			
			printf("******************************************************************************\n");
			for(current=head->next;current;current=current->next)
				if(current->num==key2)	
				{
					flg=1;
					printf("姓名:%s ",current->name);
					printf("单位:%s ",current->department);
					printf("性别:%s ",current->gender);
					printf("年龄:%d ",current->age);
					printf("电话:%ld ",current->telephone);
					printf("工资:%ld ",current->wage);
					printf("工号:%ld \n",current->num);
				}
				if(!flg)printf("\t\t对不起，没有该员工信息\n");

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
	printf("请输入您想更改信息的员工的姓名：");
	getchar();
	gets(key);
	if(current==NULL)
			printf("未录入任何员工信息\n");
		else
		{
			
		
			for(current=head->next;current;current=current->next)
				if(strcmp(current->name,key)==0)	
				{
					flg=1;
					    printf("请输入新的员工姓名：");
						scanf("%s",&current->name);				
						printf("请输入新的员工单位：");
						scanf("%s",&current->department);					
						printf("请输入新的员工性别：");
						scanf("%s",&current->gender);					
						printf("请输入新的员工年龄：");
						scanf("%d",&current->age);
						printf("请输入新的员工电话：");
						scanf("%ld",&current->telephone);					
						printf("请输入新的员工工资：");
						scanf("%ld",&current->wage);					
						printf("请输入新的员工职工号：");
						scanf("%ld",&current->num);					
					printf("\t\t\t更新完成！按任意键返回主目录\n");
					
				}
			if(!flg)printf("\t\t对不起，没有该员工信息\n");
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
	printf("请输入要删除员工的姓名：");
	printf("******************************************************************************\n");
		scanf("%s",&key);
		if(current==NULL)
			printf("未录入任何员工信息\n");
		else
		{	
			for(current=head->next;current&&q;q=current,current=current->next)
				if(strcmp(current->name,key)==0)	
				{
					flg=1;
					printf("是否确定删除员工信息（y/n）?");
					getchar();
					scanf("%c",&ch);
					if(ch=='y'||ch=='Y')
					{
						q->next=current->next;						
					}
				}
				if(!flg)printf("\t\t对不起，没有该员工信息\n");
		}
		printf("******************************************************************************\n");
}

void sortwage(lworkers head)
{
	lworkers p,q;
	int key;
	p=head->next;	
	if(p==NULL)
		printf("未录入任何员工信息\n");
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
	printf("\t\t\t工资按升序排序完成！\n");
	output(head);
}

void avewage(lworkers head)
{
	int i;
	lworkers current;
	unsigned long wage=0;
	current=head->next;
	if(current==NULL)
			printf("未录入任何员工信息\n");
		else
		{
			
			printf("******************************************************************************\n");
			for(current=head->next,i=0;current;current=current->next,i++)
			{
				wage+=current->wage;
			}
			printf("员工的平均工资为：%ld\n",wage/i);
			printf("******************************************************************************\n");
		
		}
	

}
	
	
	
	
	




