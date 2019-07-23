#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"



void Main_Modify(node *phead)
{
    int running=1;
    int choose;

    int num;
    char name[20];
    int rank;

    while(running)
    {
        printf("\t  666.返回上一级  1.按学号修改  2.按姓名修改  3.按排名修改\n");
        printf("\t请选择修改方式:");
        scanf("%d",&choose);

        while( choose!=666 && choose!=1 && choose!=2 && choose!=3  )
        {
            printf("获取的选择不符合格式，请重新输入！\n");
            printf("\t请选择修改方式:");
            scanf("%d",&choose);
        }
        printf("\n");

        switch(choose)
        {

        case 666:
            running=0;
            break;

        case 1:
            //printf("运行到这里！\n");
            printf("请输入需要修改的学生学号(1~100)：");
            scanf("%d",&num);
            while( num<1 || num>100 )
            {
                printf("输入学号格式有误,请重新输入!\n");
                scanf("%d",&num);
            }
            //printf("运行到这里！\n");
            Num_Modify(phead,num);
            Rank(phead);
            break;

        case 2:
            printf("请输入需要修改的学生姓名：");
            scanf("%s",name);
            Name_Modify(phead,name[20]);
            Rank(phead);
            break;

        case 3:
            printf("请输入需要修改的学生排名：");
            scanf("%d",&rank);
            while(rank)
            {
                printf("输入学号格式有误,请重新输入!\n");
                scanf("%d",&rank);
            }
            Rank_Modify(phead,rank);
            Rank(phead);
            break;

        }
    }
}

void Num_Modify(node *phead,int num)
{

    node *p=phead;
    int choose2;
//printf("运行到这里！\n");
    while( p->num != num && p->next!=NULL )//遍历链表查找是否存在学号为num的学生节点
    {
        p=p->next;
    }
    //printf("运行到这里！\n");
    if(p==NULL)//已移动到链表最后
    {
        printf("不存在该学号学生信息！\n");

    }
    else if(p!=NULL)
    {
        printf("1.学号2.姓名3.性别4.数学成绩5.英语成绩6.语文成绩\n");

        printf("请选择需要修改信息:");
        scanf("%d",&choose2);

        while( choose2!=1 && choose2!=2 && choose2!=3 &&
                choose2!=4 && choose2!=5 && choose2!=6 )
        {
            printf("获取的选择不符合格式，请重新输入！\n");
            printf("请选择需要修改信息:");
            scanf("%d",choose2);
        }
        printf("\n");

        switch(choose2)
        {

        case 1:
            printf("现存该位置的学生学号为:%d\n",p->num);
            printf("请输入需要修改成的学生学号(整型)：");
            scanf("%d",&p->num);
            printf("\n修改完毕!\n");
            break;

        case 2:
            printf("现存该位置的学生姓名为:%s\n",p->name);
            printf("请输入需要修改成的学生姓名(小于20字符)：");
            scanf("%s", p->name);
            printf("\n修改完毕！\n");
            break;

        case 3:
            printf("现存该位置的学生性别为:%c\n",p->sex);
            printf("请输入需要修改成的学生性别(m/f)：");
            scanf("% c", &p->sex);
            printf("\n修改完毕！\n");
            break;

        case 4:
            printf("现存该位置的学生数学成绩为:%lf\n",p->math_score);
            printf("请输入需要修改成的数学成绩(double型)：");
            scanf("%lf",&p->math_score);
            //学生的总成绩
            p->sum_score = p->math_score + p->english_score + p->chinese_score ;
            //学生的平均成绩
            p->ave_score = ( p->math_score + p->english_score + p->chinese_score )/3;
            printf("\n修改完毕！\n");
            break;

        case 5:
            printf("现存该位置的学生英语成绩为:%lf\n",p->english_score);
            printf("请输入需要修改成的英语成绩(double型)：");
            scanf("%lf", &p->english_score);
            //学生的总成绩
            p->sum_score = p->math_score + p->english_score + p->chinese_score ;
            //学生的平均成绩
            p->ave_score = ( p->math_score + p->english_score + p->chinese_score )/3;
            printf("\n修改完毕！\n");
            break;

        case 6:
            printf("现存该位置的学生语文成绩为:%lf\n",p->chinese_score);
            printf("请输入需要修改成的语文成绩(double型)：");
            scanf("%lf",&p->chinese_score);
            //学生的总成绩
            p->sum_score = p->math_score + p->english_score + p->chinese_score ;
            //学生的平均成绩
            p->ave_score = ( p->math_score + p->english_score + p->chinese_score )/3;
            printf("\n修改完毕！\n");
            break;

        }
    }
}

void Name_Modify(node *phead,char name[20])
{
    node *p=phead;
    int choose2;

    while(strcpy(p->name,name)!=0 && p->next!=NULL )//遍历链表查找是否存在姓名为name的学生节点
    {
        p=p->next;
    }
    if(p==NULL)
    {
        printf("不存在该学号学生信息！\n");

    }
    else if(p!=NULL)
    {
        printf("1.学号2.姓名3.性别4.数学成绩5.英语成绩6.语文成绩\n");
        printf("请选择需要修改信息的编号:");
        scanf("%d",&choose2);

        while( choose2!=1 && choose2!=2 && choose2!=3&&
              choose2!=4 && choose2!=5 && choose2!=6 )
        {
            printf("获取的选择不符合格式，请重新输入！\n");
            printf("请选择需要修改信息的编号:");
            scanf("%d",&choose2);
        }
        printf("\n");

        switch(choose2)
        {

        case 1:

            printf("现存该位置的学生学号为:%d\n",p->num);
            printf("请输入需要修改成的学生学号(整型)：");
            scanf("%d",&p->num);
            printf("\n修改完毕!\n");
            break;

        case 2:
            printf("现存该位置的学生姓名为:%s\n",p->name);
            printf("请输入需要修改成的学生姓名(小于20字符)：");
            scanf("%s", p->name);
            printf("\n修改完毕！\n");
            break;

        case 3:
            printf("现存该位置的学生性别为:%c\n",p->sex);
            printf("请输入需要修改成的学生性别(m/f)：");
            scanf("% c", &p->sex);
            printf("\n修改完毕！\n");
            break;

        case 4:
            printf("现存该位置的学生数学成绩为:%lf\n",p->math_score);
            printf("请输入需要修改成的数学成绩(double型)：");
            scanf("%lf",&p->math_score);
            //学生的总成绩
            p->sum_score = p->math_score + p->english_score + p->chinese_score ;
            //学生的平均成绩
            p->ave_score = ( p->math_score + p->english_score + p->chinese_score )/3;
            printf("\n修改完毕！\n");
            break;

        case 5:
            printf("现存该位置的学生英语成绩为:%lf\n",p->english_score);
            printf("请输入需要修改成的英语成绩(double型)：");
            scanf("%lf", &p->english_score);
            //学生的总成绩
            p->sum_score = p->math_score + p->english_score + p->chinese_score ;
            //学生的平均成绩
            p->ave_score = ( p->math_score + p->english_score + p->chinese_score )/3;
            printf("\n修改完毕！\n");
            break;

        case 6:
            printf("现存该位置的学生语文成绩为:%lf\n",p->chinese_score);
            printf("请输入需要修改成的语文成绩(double型)：");
            scanf("%lf",&p->chinese_score);
            //学生的总成绩
            p->sum_score = p->math_score + p->english_score + p->chinese_score ;
            //学生的平均成绩
            p->ave_score = ( p->math_score + p->english_score + p->chinese_score )/3;
            printf("\n修改完毕！\n");
            break;

        }
    }
}

void Rank_Modify(node *phead,int rank)
{
    node *p=phead;
    int choose2;

    while(p->rank!=rank && p->next!=NULL )//遍历链表查找是否存在名次为rank的学生节点
    {
        p=p->next;
    }
    if(p==NULL)
    {
        printf("不存在该学号学生信息！\n");

    }
    else if(p!=NULL)
    {
        printf("1.学号2.姓名3.性别4.数学成绩5.英语成绩6.语文成绩\n");
        printf("请选择需要修改信息的编号:");
        scanf("%d",&choose2);

        while(  choose2!=1 && choose2!=2 && choose2!=3 &&
                choose2!=4 && choose2!=5 && choose2!=6 )
        {
            printf("获取的选择不符合格式，请重新输入！\n");
            printf("请选择需要修改信息的编号:");
            scanf("%d",&choose2);
        }
        printf("\n");

        switch(choose2)
        {


        case 1:
            printf("现存该位置的学生学号为:%d\n",p->num);
            printf("请输入需要修改成的学生学号(整型)：");
            scanf("%d",&p->num);
            printf("\n修改完毕!\n");
            break;

        case 2:
            printf("现存该位置的学生姓名为:%s\n",p->name);
            printf("请输入需要修改成的学生姓名(小于20字符)：");
            scanf("%s", p->name);
            printf("\n修改完毕！\n");
            break;

        case 3:
            printf("现存该位置的学生性别为:%c\n",p->sex);
            printf("请输入需要修改成的学生性别(m/f)：");
            scanf("% c", &p->sex);
            printf("\n修改完毕！\n");
            break;

        case 4:
            printf("现存该位置的学生数学成绩为:%lf\n",p->math_score);
            printf("请输入需要修改成的数学成绩(double型)：");
            scanf("%lf",&p->math_score);
            //学生的总成绩
            p->sum_score = p->math_score + p->english_score + p->chinese_score ;
            //学生的平均成绩
            p->ave_score = ( p->math_score + p->english_score + p->chinese_score )/3;
            printf("\n修改完毕！\n");
            break;

        case 5:
            printf("现存该位置的学生英语成绩为:%lf\n",p->english_score);
            printf("请输入需要修改成的英语成绩(double型)：");
            scanf("%lf", &p->english_score);
            //学生的总成绩
            p->sum_score = p->math_score + p->english_score + p->chinese_score ;
            //学生的平均成绩
            p->ave_score = ( p->math_score + p->english_score + p->chinese_score )/3;
            printf("\n修改完毕！\n");
            break;

        case 6:
            printf("现存该位置的学生语文成绩为:%lf\n",p->chinese_score);
            printf("请输入需要修改成的语文成绩(double型)：");
            scanf("%lf",&p->chinese_score);
            //学生的总成绩
            p->sum_score = p->math_score + p->english_score + p->chinese_score ;
            //学生的平均成绩
            p->ave_score = ( p->math_score + p->english_score + p->chinese_score )/3;
            printf("\n修改完毕！\n");
            break;
        }
    }
}

