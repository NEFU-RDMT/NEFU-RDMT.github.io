#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"



void Main_Delete(node *phead)
{
    int running=1;
    int choose;
    int question;
    int num;
    char name[20];
    int rank;

    while(running)
    {
        printf("\t  666.返回上一级  1.按学号删除  2.按姓名删除  3.按排名删除\n");

        printf("\t请选择删除方式:");
        scanf("%d",&choose);

        while( choose!=666 && choose!=1 && choose!=2 && choose!=3 )
        {
            printf("获取的选择不符合格式，请重新输入！\n");
            printf("\t请选择删除方式:");
            scanf("%d",&choose);
        }
        printf("\n");

        switch( choose )
        {

        case 666:
            running=0;
            break;

        case 1:
            printf("请输入学号(1~100)：");
            scanf("%d",&num);
            printf("是否删除学号为%d的学生信息？(1.是  2.否):",num);
            scanf("%d",&question);

            while(question!=1 && question!=2)
            {
                printf("获取的选择不符合格式，请重新输入！\n");
                printf("是否删除学号为%d的学生信息？(1.是  2.否):",num);
                scanf("%d",&question);
            }
            printf("\n");
            if( question ==1 )
            {
                Num_Delete(phead,num);
                Rank(phead);
                break;
            }
            else if(question==2 )
            {
                break;
            }

        case 2:
            printf("请输入姓名：");
            scanf("%s",&name);
            printf("是否删除姓名为%s的学生信息？(1.是  2.否):",name);
            scanf("%d",&question);

            while(question!=1 && question!=2)
            {
                printf("获取的选择不符合格式，请重新输入！\n");
                printf("是否删除姓名为%s的学生信息？(1.是  2.否):",name);
                scanf("%d",&question);
            }

            if( question ==1 )
            {
                Name_Delete(phead,name[20]);
                Rank(phead);
                break;
            }
            else if(question==2 )
            {
                break;
            }

        case 3:
            printf("请输入排名：");
            scanf("%d",&rank);
            printf("是否删除排名为%d的学生信息？(1.是  2.否):",rank);
            scanf("%d",&question);

            while(question!=1 && question!=2)
            {
                printf("获取的选择不符合格式，请重新输入！\n");
                printf("是否删除排名为%d的学生信息？(1.是  2.否):",rank);
                scanf("%d",&question);
            }
            printf("\n");

            if( question ==1 )
            {
                Rank_Delete(phead,rank);
                Rank(phead);
                break;
            }
            else if(question==2 )
            {
                break;
            }
        }
    }
}



//按学号删除学生信息

void Num_Delete(node *phead,int num)
{
    node *plast = phead , *p = phead;
    while(p->num != num && p->next!=NULL)
    {
        p = p->next;
    }
    if(p!=NULL)
    {
        plast->next=p->next;
        free(p);
        p=plast->next;
        printf("删除成功！\n");
    }
    else if(p==NULL)
    {
        printf("没有该学号学生信息！\n");
    }
}

//按姓名删除学生信息

void Name_Delete(node *phead,char name[])
{
    node *plast = phead , *p = phead;
    while( strcmp(p->name,name) != 0 && p->next!=NULL )
    {
        p = p->next;
    }
    if(p!=NULL)
    {
        plast->next=p->next;
        free(p);
        p=plast->next;
        printf("删除成功！\n");
    }
    else if(p==NULL)
    {
        printf("没有该姓名学生信息！\n");
    }
}

//按排名删除学生信息

void Rank_Delete(node *phead,int rank)
{
    node *plast = phead , *p = phead;
    while(p->rank != rank && p->next!=NULL )
    {
        p = p->next;
    }
    if(p!=NULL)
    {
        plast->next=p->next;
        free(p);
        p=plast->next;
        printf("删除成功！\n");
    }
    else if(p==NULL)
    {
        printf("没有该排名学生信息！\n");
    }
}



