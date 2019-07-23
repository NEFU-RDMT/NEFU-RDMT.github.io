#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "conio.h"
#define  stacksize  10

typedef struct carnumber
{
	char num[10];
}carnum;
typedef  struct  sqstack
{
  carnum  data[stacksize];
  int  top;
}SqStackTp;
typedef struct  linked_queue
{
  carnum  data;
  struct  linked_queue  * next;
}LqueueTp;
typedef  struct 
{
  LqueueTp  *front ,  *rear ;
}QueptrTp;



int menu();
void title();
void drivein(SqStackTp *stoping,QueptrTp *quehead);
void output(SqStackTp stoping,QueptrTp  quehead);
void driveout(SqStackTp *stoping,QueptrTp  *quehead);

main()
{
	SqStackTp stoping;
	stoping.top=-1;
	QueptrTp  quehead;
	quehead.front=NULL;
	quehead.rear=NULL;
	title();
	for(;;)
	{
		switch(menu())
		{
		case 1:
			drivein(&stoping,&quehead);
			break;
		case 2:
			driveout(&stoping,&quehead);
			break;
		case 3:
			output(stoping,quehead);
			break;	
		case 4:
			exit(0);
		default:
			printf("���������������������룡");
		}
	}

	return 0;
}
void title()
{
	printf(" *****************************************************************************\n");
	printf("\t\t\t\tͣ��������ϵͳ\t\t\t     \n");
    printf("\t\t\t\t 06�����4��\t   ��׼\t");	
}

int menu()
{
	int i;
	printf("\n\t\t**************************************************\n");
	printf("\t\t*\t\t1:�г��������ͣ����:\t\t *\n");
	printf("\t\t*\t\t2:�г����뿪��ͣ����:\t\t *\n");
	printf("\t\t*\t\t3:�鿴ͣ���������г�����Ϣ\t *\n");
	printf("\t\t*\t\t4:�˳�����\t\t\t *\n");
	printf("\t\t**************************************************\n");
	printf("\t\t����������ѡ�");
	scanf("%d",&i);
	return i;
}

void drivein(SqStackTp *stoping,QueptrTp  *quehead)
{

	LqueueTp *queue;
	printf("������ʻ�복���ĳ��ƺ��룺");	
	if((*stoping).top!=9)
	{
		scanf("%s",&(*stoping).data[++(*stoping).top].num);
		printf("\t\t**************************************************\n");
		printf("\t\t�����ѽ���ͣ������%d��ͣ��λ���������������Ŀ¼��\n",(*stoping).top+1);
		printf("\t\t**************************************************\n");
		getch();

	}
	else
	{
		queue=(LqueueTp *)malloc(sizeof(LqueueTp));
		queue->next=NULL;
		scanf("%s",&queue->data.num);
		if((*quehead).front==NULL&&(*quehead).rear==NULL)
		{
			(*quehead).front=queue;
			(*quehead).rear=queue;
		}
		else
		{
			(*quehead).rear->next=queue;
			(*quehead).rear=queue;
		}
		printf("\t�Բ�������ͣ�������������ڱ�����Ŷӡ�\n");
	}

}

void output(SqStackTp stoping,QueptrTp  quehead)
{
	int i;
	LqueueTp *current;
	current=quehead.front;
	if(stoping.top==-1)
		printf("\t\tͣ������û�г�����\n");
	else{
		printf("\t\t\t\tͣ�����ڳ�����Ϣ\n");

	printf("\t\t**************************************************\n");
	for(i=0;i<=stoping.top;i++)
	{
		printf("\t\t* ͣ������%d��λ�ó���Ϊ��%s  \n",i+1,stoping.data[i].num);
	}
	printf("\t\t**************************************************\n");
	if(quehead.front!=NULL)
	{ 
		i=1;
		printf("\t\t**************************************************\n");
		do
		{
			printf("\t\t* ����ϵ�%dλ�õȴ��ĳ���Ϊ��%s\n",i++,current->data.num);
			current=current->next;
		}while(current!=NULL);
		printf("\t\t**************************************************\n");		
	}
	}
	printf("\t\t��ʾ��ɣ��������������Ŀ¼��\n");
	getch();
}

void driveout(SqStackTp *stoping,QueptrTp  *quehead)
{
	int i,k,j=0;
	SqStackTp bystop;
	LqueueTp *p;
	bystop.top=-1;
	char num[10];	
	if((*stoping).top==-1)
		printf("\t�Բ���ͣ�����ڲ��޳���!");
	else
	{
		printf("������Ҫ�뿪�����ĳ��ƺ��룺");
		scanf("%s",&num);
		for(i=0;i<=(*stoping).top;i++)
		{
			if(!strcmp(num,(*stoping).data[i].num))
			{
				j=1;
				for(k=(*stoping).top;k>i;k--)
				{
					strcpy(bystop.data[++bystop.top].num,(*stoping).data[(*stoping).top--].num);
				}
				printf("����%sʻ��ͣ������",(*stoping).data[(*stoping).top--].num);
				while(bystop.top!=-1)
				{
					strcpy((*stoping).data[++(*stoping).top].num,bystop.data[bystop.top--].num);
				}
				if((*quehead).front!=NULL)
				{
					p=(*quehead).front;
					strcpy((*stoping).data[++(*stoping).top].num,(*quehead).front->data.num);
					printf("����%s����ͣ������\n",(*quehead).front->data.num);
					(*quehead).front=(*quehead).front->next;
					free(p);
				}
				break;
			}
		}
		if(!j)
			printf("�Բ���ͣ�����ڲ��޸ó���������ȷ��!\n");
	}
}




