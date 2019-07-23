#include <stdio.h>
#include <malloc.h>
typedef struct
{
    int CarNo[100];
    int CarTime[100];
    int top;
}SeqStack;
typedef struct qnode
{
    int CarNo;
	int CarTime;
	struct qnode * next;
}LQNode;
typedef struct
{
    LQNode * front;
    LQNode * rear;
}LQueue;
void StackInitiate(SeqStack *S)
{
    S->top = 0;
}
void StackPush(SeqStack *S,int x,int y)
{
    S->CarNo[S->top] = x ;
    S->CarTime[S->top] = y ;
    S->top++;
}
void StackPop(SeqStack *S,int *x,int *y)
{
    S->top--;
    *x = S->CarNo[S->top];
    *y = S->CarTime[S->top];
}
void QueueInitiate(LQueue *Q)
{
    Q->rear=Q->front=NULL;
}
void QueueAppend(LQueue *Q,int x,int y)
{
    LQNode *p;
    p=(LQNode *)malloc(sizeof(LQNode));
    p->CarNo= x ;
    p->CarTime = y ;
    p->next = NULL;
    if(Q->rear != NULL) Q->rear->next = p;
    Q->rear=p;
    if(Q->front == NULL) Q->front = p;
}
void QueueDelete(LQueue *Q,int *x,int *y)
{
    LQNode *p;
    *x=Q->front->CarNo;
    *y=Q->front->CarTime;
    p=Q->front;
    Q->front = Q->front->next;
    if(Q->front == NULL) Q->rear = NULL;
    free(p);
}
int main()
{
    LQueue Q;
    SeqStack S1,S2;
    int n,i,num,time,num1,time1,num2,time2,k,j;

    StackInitiate(&S1);
    StackInitiate(&S2);
    QueueInitiate(&Q);
    printf("输入一个n代表停车场内最多可停车数:");
    scanf("%d",&n);
    k=1;
    while(1)
    {
        
        printf("请输入状态(1到达/2离开)\n");
		scanf("%d",&j);
        printf("请输入车牌:\n");
		scanf("%d",&num);
		printf("请输入时间:\n");
        scanf("%d",&time); 
        if(j==1)
        {
            if(S1.top<n) 
            {
                StackPush(&S1,num,time);
                printf("在停车场%d个车位的第%d个车位\n",n,S1.top);
            }
            else 
            {
                QueueAppend(&Q,num,time);
                printf("在候车厂的第%d个位置。\n",k);
                k++;
            }
        }
        else if(j==2)
        {
            while(1)
            {
                StackPop(&S1,&num1,&time1);
                if(num1!=num)
                {
                    StackPush(&S2,num1,time1);
                }
                if(num1==num) 
                {
                    printf("停留%d小时\n",time-time1);
                    while(S2.top!=0)
                    {
                        StackPop(&S2,&num1,&time1);
                        StackPush(&S1,num1,time1);
                    }
                    if(k>1)
                    {
                    QueueDelete(&Q,&num2,&time2);k--;
                    StackPush(&S1,num2,time);
                    }
                    break;
                }
            }
        }
        else printf("输入错误！\n");
   }
    return 0;
}

