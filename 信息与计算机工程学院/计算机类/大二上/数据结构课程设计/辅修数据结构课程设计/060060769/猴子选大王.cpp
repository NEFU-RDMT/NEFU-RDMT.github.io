#include <iostream>
#include <stdlib.h>

typedef struct node
{
 int data;
 struct node *next;
}lnode,*linkedlist;


void linkedlistcreat(linkedlist head,int number)
{
	int i;
	linkedlist p=head;
	head->data=number;
	for(i=1;i<=number;i++)
	{
		linkedlist s=(lnode*)malloc(sizeof(lnode));
		s->data=i;
		s->next=NULL;
		p->next=s;
		p=s;
	}
	p->next=head->next;
}


int getking(linkedlist head,int m)
{
	int count=head->data;
	int t=1;
	linkedlist p1,p2;
	p1=head->next;
	while(count!=1)
	{
		for(t=1;t<=m-2;t++)
		{
			p1=p1->next;
		}

           p2=p1->next;
		   p1->next=p2->next;printf("%d\n",p2->data);
		   free(p2);
		   p1=p1->next;
           count--;
	}
	return p1->data;
}



int main()
{
int result,number,m;
lnode headnode; linkedlist head=&headnode;
headnode.data=0;
headnode.next=NULL; 

printf("请输入猴子的总数和要删除第几个猴子的数：");
scanf("%d%d",&number,&m);

linkedlistcreat(head,number);
result=getking(head,m);
printf("%d",result);
system("pause");
return 0;
}


		   

