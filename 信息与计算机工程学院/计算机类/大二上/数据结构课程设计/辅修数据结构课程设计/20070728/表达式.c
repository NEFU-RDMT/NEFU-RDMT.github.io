#include <stdio.h>
#define StackSize 100
#define QueueSize 100
typedef char DataType;
typedef struct{
	char data[100];
	int front,rear;
}SeqQueue;
void InitQueue(SeqQueue *Q)
{
	Q->front=0; Q->rear=0;
}
int QueueEmpty(SeqQueue *Q)
{
	return Q->rear==Q->front;
}
void EnQueue(SeqQueue *Q,char x)
{
	if((Q->rear+1)%QueueSize==Q->front)
		printf("对列已满！\n");
	else
	{
		Q->data[Q->rear]=x;
		Q->rear=(Q->rear+1)%QueueSize;
	}
}
char DeQueue(SeqQueue *Q)
{
	char x;
	if(Q->rear==Q->front)
		printf("对列为空！");
	else
	{
		x=Q->data[Q->front];
		Q->front=(Q->front+1)%QueueSize;
	}
   return x;
}
typedef struct{
	DataType data[100];
	int top;
}SeqStack;
void InitStack(SeqStack *s)
{
	s->top=-1;
}
void push(SeqStack * s,char x)
{
	if(s->top==StackSize-1)
		printf("栈已满！\n");
	else
	{
		s->top=s->top+1;
		s->data[s->top]=x;
	}
}
DataType pop(SeqStack *s)
{
	if(s->top==-1)
	printf("栈为空！");
	else
		return s->data[s->top--];
}
DataType GetTop(SeqStack *s)
{
	if(s->top==-1)
	{printf("栈为空！\n");return 0;}
	else
		return s->data[s->top];
}
int priority(DataType op)
{
	switch(op)
	{
	case '(':
	case '#':
		return (0);
	case '+':
	case '-':
		return (1);
	case '*':
	case '/':
		return (2);
	}
}
void CTPostExp(SeqQueue *Q)
{
	SeqStack OS;
	char c,t;
	SeqStack *s;
	s=&OS;
    InitStack(s);
	push(s,'#');
	do{
		c=getchar();
		switch(c)
		{
		case ' ':
			break;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
        case '5':
	    case '6':
		case '7':
		case '8':
		case '9':
			EnQueue(Q,c);
			break;
		case '(':
			push(s,c);
			break;
		case ')':
		case '#':
			do{
				t=pop(s);
				if(t!='('&&t!='#')
					EnQueue(Q,t);
			}while(t!='('&&s->top!=-1);
			break;
		case '+':
		case '-':
		case '*':
		case '/':
			while(priority(c)<=priority(GetTop(s)))
			{
				t=pop(s);
				EnQueue(Q,t);
			}
			push(s,c);
			break;
		}
	}while(c!='#');
}
int CPostExp(SeqQueue *Q)
{
	SeqStack vs,*s;
	char ch;
	int x,y;
	s=&vs;
	InitStack(s);
	while(!QueueEmpty(Q))
	{
		ch=DeQueue(Q);
		if(ch>='0'&&ch<='9')
			push(s,ch-'0');
		else{
			y=pop(s);
			x=pop(s);
			switch(ch)
			{
			case '+':
				push(s,x+y);
				break;
			case '-':
				push(s,x-y);
				break;
			case '*':
				push(s,x*y);
				break;
			case '/':
				push(s,x/y);
				break;
			}
		}
	}
	return GetTop(s);
}

void main()
{
	char c;
	int s,i;
	SeqQueue *Q;
	SeqQueue postQ;
	Q=&postQ;
	InitQueue(Q);
	CTPostExp(Q);
	i=Q->front;
	printf("后缀表达式为:\n");
	while(i<Q->rear)
	{
	
		c=Q->data[i];
		printf("%c",c);
		i++;
	}
	s=CPostExp(Q);
	printf("表达式的值为%d\n",s);
}
