
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

//把学生信息节点加入到链表中

void Add(node *phead)
{

    node *p=phead;
    node *q = NULL;//新节点，用以申请新的动态储存空间
    node *pflag = NULL;//终止循环的条件
    while(1)
    {
        q=(node *)malloc( sizeof(node) );//动态申请空间，存储学生信息;

        pflag = Input(q);
        //printf("%d",q->num);q添加成功了！

        if(pflag == NULL)//终止死循环条件为输入学号为0
        {
            break;
        }
        else
        {
            //printf("运行到这里1\n");没问题

            while( p!=NULL && p->next!=NULL )//寻找已有链表最后一个节点
            {
                printf("运行到这里la\n");
                p=p->next;
            }
            p->next=q;
            q->next=NULL;
            p=q;
        }
    }
    Rank(phead);
}

/*if( q == NULL )
        {
            printf("申请内存空间失败!\n");
            return NULL;
        }*/
