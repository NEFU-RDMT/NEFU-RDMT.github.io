#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"


//读取文件时总是多读取一行的信息（均为随机数）

void Read_From_File(node *phead)
{
    FILE *fp;
    node *p=phead,*pnew=NULL,*ptail=NULL;

    while( p!=NULL && p->next!=NULL )//寻找最后链表最后节点
    {
        p=p->next;
    }
    ptail=p;
    if( (fp=fopen("filel.txt","a+")) == NULL )
    {
        printf("\t文件不存在，请先录入文件!\n");
        exit(1);
    }
    pnew=(node *)malloc( sizeof(node) );
    if(pnew==NULL)
    {
        printf("操作失败!\n");
        exit(1);
    }
    while(fscanf(fp,"%d %s %c %lf %lf %lf %lf %lf %d",&pnew->num,pnew->name,&pnew->sex,&pnew->math_score,&pnew->english_score,&pnew->chinese_score,&pnew->sum_score,&pnew->ave_score,&pnew->rank)!=EOF)
    {
        pnew->next=NULL;
        ptail->next=pnew;
        ptail=pnew;
        pnew=(node *)malloc( sizeof(node) );
        if(pnew==NULL)
        {
            printf("操作失败!\n");
            exit(1);
        }
    }
    //Rank(phead);
    printf("操作成功!\n");
}

