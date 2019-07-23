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
			printf("您的输入有误，请重新输入！");
		}
	}

	return 0;
}
void title()
{
	printf(" *****************************************************************************\n");
	printf("\t\t\t\t停车场管理系统\t\t\t     \n");
    printf("\t\t\t\t 06计算机4班\t   宋准\t");	
}

int menu()
{
	int i;
	printf("\n\t\t**************************************************\n");
	printf("\t\t*\t\t1:有车辆想进入停车场:\t\t *\n");
	printf("\t\t*\t\t2:有车辆想开出停车场:\t\t *\n");
	printf("\t\t*\t\t3:查看停车场内所有车辆信息\t *\n");
	printf("\t\t*\t\t4:退出程序\t\t\t *\n");
	printf("\t\t**************************************************\n");
	printf("\t\t请输入您的选项：");
	scanf("%d",&i);
	return i;
}

void drivein(SqStackTp *stoping,QueptrTp  *quehead)
{

	LqueueTp *queue;
	printf("请输入驶入车辆的车牌号码：");	
	if((*stoping).top!=9)
	{
		scanf("%s",&(*stoping).data[++(*stoping).top].num);
		printf("\t\t**************************************************\n");
		printf("\t\t车辆已进入停车场内%d号停车位，按任意键返回主目录！\n",(*stoping).top+1);
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
		printf("\t对不起，由于停车场已满，请在便道处排队。\n");
	}

}

void output(SqStackTp stoping,QueptrTp  quehead)
{
	int i;
	LqueueTp *current;
	current=quehead.front;
	if(stoping.top==-1)
		printf("\t\t停车场内没有车辆！\n");
	else{
		printf("\t\t\t\t停车场内车辆信息\n");

	printf("\t\t**************************************************\n");
	for(i=0;i<=stoping.top;i++)
	{
		printf("\t\t* 停车场内%d号位置车辆为：%s  \n",i+1,stoping.data[i].num);
	}
	printf("\t\t**************************************************\n");
	if(quehead.front!=NULL)
	{ 
		i=1;
		printf("\t\t**************************************************\n");
		do
		{
			printf("\t\t* 便道上第%d位置等待的车辆为：%s\n",i++,current->data.num);
			current=current->next;
		}while(current!=NULL);
		printf("\t\t**************************************************\n");		
	}
	}
	printf("\t\t显示完成，按任意键返回主目录。\n");
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
		printf("\t对不起，停车场内并无车辆!");
	else
	{
		printf("请输入要离开车辆的车牌号码：");
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
				printf("车辆%s驶出停车场！",(*stoping).data[(*stoping).top--].num);
				while(bystop.top!=-1)
				{
					strcpy((*stoping).data[++(*stoping).top].num,bystop.data[bystop.top--].num);
				}
				if((*quehead).front!=NULL)
				{
					p=(*quehead).front;
					strcpy((*stoping).data[++(*stoping).top].num,(*quehead).front->data.num);
					printf("车辆%s进入停车场！\n",(*quehead).front->data.num);
					(*quehead).front=(*quehead).front->next;
					free(p);
				}
				break;
			}
		}
		if(!j)
			printf("对不起，停车场内并无该车，请重新确认!\n");
	}
}




