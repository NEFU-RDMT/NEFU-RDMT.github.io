#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"



//查找学生信息

void Main_Search(node *phead)
{
    int running=1;
    int num;        //学生的编号
    char name[20];  //学生的姓名
    int rank;//学生的排名

    int choose;

    while(running)
    {
        printf("\t  666.返回上一级  1.按学号查找  2.按姓名查找  3.按排名查找\n");
        printf("\t请选择查找方式:");
        scanf("%d",&choose);

        while( choose!=666 && choose!=1 && choose!=2 && choose!=3 )
        {
            printf("获取的选择不符合格式，请重新输入！\n");
            printf("\t请选择查找方式:");
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
            Num_Search(phead,num);
            break;

        case 2:
            printf("请输入姓名：");
            scanf("%s",name);
            Name_Search(phead,name[20]);
            break;

        case 3:
            printf("请输入名次：");
            scanf("%s",rank);
            Rank_Search(phead,rank);
            break;
        }
    }
}

//按学号查找

void Num_Search(node *phead,int num)
{
    node *p=phead;
    while( p->num != num && p->next!=NULL )
    {
        p=p->next;
    }
    if(p==NULL)
    {
        printf("没有该学号的学生信息！\n");

    }
    else if(p!=NULL)
    {
        printf("  编号    姓名   性别  数学成绩   英语成绩    语文成绩    平均成绩    总成绩 排名  \n");
        Output(p);
    }
}

//按姓名查找

void Name_Search(node *phead,char name[20])
{
    node *p=phead;

    while(strcmp(p->name,name)!=0 && p->next!=NULL )
    {
        p=p->next;
    }

    if(p==NULL)
    {
        printf("没有该姓名的学生信息！\n");

    }
    else if(p!=NULL)
    {
        printf("  编号    姓名   性别  数学成绩   英语成绩    语文成绩    平均成绩    总成绩 排名  \n");
        Output(p);
    }
}

//按排名查找

void Rank_Search(node *phead,int rank)
{
    node *p=phead;

    while(p->rank != rank && p->next!=NULL )
    {
        p=p->next;
    }
    if(p==NULL)
    {
        printf("没有该排名的学生信息！\n");

    }
    else if(p!=NULL)
    {
        printf("  编号    姓名   性别  数学成绩   英语成绩    语文成绩    平均成绩    总成绩 排名  \n");
        Output(p);
    }
}

