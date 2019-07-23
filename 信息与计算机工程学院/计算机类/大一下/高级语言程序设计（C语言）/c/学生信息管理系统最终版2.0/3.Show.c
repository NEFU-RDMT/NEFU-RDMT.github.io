#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"



//显示学生信息
void Main_Show(node *phead)
{
    int running=1;
    int choose;
    int num;
    char name[20];
    int rank;

    while(running)
    {
        printf("\t  666.返回上一级  1.按学号显示  2.按姓名显示  3.按排名显示  4.全部显示\n");
        printf("\t请选择显示方式:");
        scanf("%d",&choose);

        while( choose!=666 && choose!=1 && choose!=2 && choose!=3 && choose!=4 )
        {
            printf("获取的选择不符合格式，请重新输入！\n");
            printf("\t请选择显示方式:");
            scanf("%d",&choose);
        }
        printf("\n");

        switch( choose )
        {

        case 666:
            running=0;
            break;

        case 1:
            printf("请输入需要显示的学生学号(1~100)：");
            scanf("%d",&num);
            Num_Show(phead,num);
            Rank(phead);
            break;

        case 2:
            printf("请输入需要显示的学生姓名：");
            scanf("%s",name);
            Name_Show(phead,name[20]);
            Rank(phead);
            break;

        case 3:
            printf("请输入需要显示的学生排名：");
            scanf("%d",&rank);
            Rank_Show(phead,rank);
            Rank(phead);
            break;

        case 4:
            printf("即将打印全部学生信息：\n");
            All_Show(phead);
            Rank(phead);
            break;
        }

    }
}


void Num_Show(node *phead,int num)
{
    node *p=phead;
    //printf("运行到这里1\n");//没问题
    while( p->num!=num && p->next!=NULL )
    {
        p=p->next;
    }
    //printf("运行到这里2\n");//出现bug
    if(p==NULL)
    {
        printf("没有该学号的学生信息！\n");
    }
    else if( p != NULL )
    {
        printf("  编号    姓名   性别  数学成绩   英语成绩    语文成绩    平均成绩    总成绩 排名  \n");
        Output(p);
    }
}
void Name_Show(node *phead,char name[20])
{
    node *p=phead;

    while( strcmp(p->name,name) !=0 && p->next!=NULL )
    {
        p=p->next;
    }

    if( p == NULL )
    {
        printf("没有该姓名的学生信息！\n");
    }
    else if( p != NULL )
    {
        printf("  编号    姓名   性别  数学成绩   英语成绩    语文成绩    平均成绩    总成绩 排名  \n");
        Output(p);
    }
}
void Rank_Show(node *phead,int rank)
{
    node *p=phead;
    while( p->rank != rank && p->next!=NULL )
    {
        p=p->next;
    }
    if( p == NULL )
    {
        printf("没有该排名的学生信息！\n");
    }
    else if( p != NULL )
    {
        printf("  编号    姓名   性别  数学成绩   英语成绩    语文成绩    平均成绩    总成绩 排名  \n");
        Output(p);
    }
}

//打印全部信息

void All_Show(node *phead)
{
    node *p = phead;

    printf("  编号    姓名   性别  数学成绩   英语成绩    语文成绩    平均成绩    总成绩 排名  \n");
    while( p->next!=NULL )
    {
        Output(p);
        p = p->next;//让指针指向下一个节点
    }
}
