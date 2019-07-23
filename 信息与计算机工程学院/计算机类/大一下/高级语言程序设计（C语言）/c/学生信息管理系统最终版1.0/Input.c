
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"



//对已有的节点进行数据的输入

node * Input(node *p)
{
    //学号
    printf("\t请输入学生的学号(1~100,输入0时结束):");
    scanf("%d",&p->num);
    while( p->num>100 )
    {
        printf("输入学号格式有误，请重新输入！\n");
        printf("\t请输入学生的学号(1~100,输入0时结束):");
        scanf("%d",&p->num);
    }
    printf("\n");

    if(p->num == 0)
    {
        free(p);//释放内存
        p=NULL;//重置p
        return NULL;//表示结束
    }
//姓名
    printf("\t请输入学生的姓名(小于20字符):");
    scanf("%s", p->name);
    while( strlen(p->name)>20 )
    {
        printf("输入姓名格式有误，请重新输入！\n");
        printf("\t请输入学生的姓名(小于20字符):");
        scanf("%s", p->name);
    }
    printf("\n");
//性别
    printf("\t请输入学生的性别(m是男性/f是女性):");
    getchar();
    //printf("运行到这里1\n");
    scanf("%c",&p->sex);

    while( p->sex!='m' && p->sex!='f' )
    {
        printf("输入性别格式有误，请重新输入！\n");
        printf("\t请输入学生的性别(m是男性/f是女性):");
        getchar();
        scanf("%c",&p->sex);

        //p->sex=getchar();
    }
    printf("\n");
//数学成绩
    printf("\t请输入学生的数学成绩(double型,0.00~100.00):");
    scanf("%lf",&p->math_score);
    while( p->math_score<0 || p->math_score>100 )
    {
        printf("输入数学成绩格式有误，请重新输入！\n");
        printf("\t请输入学生的数学成绩(double型):");
        scanf("%lf",&p->math_score);
    }
    printf("\n");
//英语成绩
    printf("\t请输入学生的英语成绩(double型,0.00~100.00):");
    scanf("%lf",&p->english_score);
    while( p->english_score<0 || p->english_score>100 )
    {

        printf("输入英语成绩格式有误，请重新输入！\n");
        printf("\t请输入学生的英语成绩(double型):");
        scanf("%lf",&p->english_score);
    }
    printf("\n");
//语文成绩
    printf("\t请输入学生的语文成绩(double型,0.00~100.00):");
    scanf("%lf",&p->chinese_score);
    while( p->chinese_score<0 || p->chinese_score>100 )
    {
        printf("输入英语成绩格式有误，请重新输入！\n");
        printf("\t请输入学生的语文成绩(double型):");
        scanf("%lf",&p->chinese_score);
    }
    printf("\n");

    //学生的总成绩(double型,0.00~100.00)
    p->sum_score = p->math_score + p->english_score + p->chinese_score ;
    //学生的平均成绩(double型,0.00~100.00)
    p->ave_score = ( p->math_score + p->english_score + p->chinese_score )/3;

    p->next ==NULL;
    return p;
}
