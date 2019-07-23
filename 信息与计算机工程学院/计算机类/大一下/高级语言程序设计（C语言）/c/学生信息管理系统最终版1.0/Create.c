#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

//创建一个节点,它会返回一个新创建的学生信息节点的指针
/*
void Create()
{
    int sex;
    student *p = (student *)malloc( sizeof(student) );//动态申请空间，存储学生信息
    if( p == NULL )
    {
        printf("申请内存空间失败!\n");
        return NULL;
    }

    printf("请输入学生的学号(整型)：");
    while(scanf("%d", &p->num) !=  1 || GetPrevAddr(p->num) )
    {
        printf("学生编号输入错误或已经存在，请重新输入学生的编号(整型)：");
        fflush(stdin);
    }

    printf("请输入学生的姓名(小于20字符)：");
    scanf("%20s", p->name);

    printf("请选择学生的性别(1.男  2.女)：");
    while(scanf("%d", &sex) != 1 || sex < 1 || sex > 2)
    {
        printf("性别选择错误，请重新选择学生的性别(1.男  2.女)：");
        fflush(stdin);
    }
    if(1 == sex)
    {
        pstu->sex = m;
    }
    else
    {
        pstu->sex = f;
    }

    printf("请输入学生的数学成绩(小于20字符)：");
    scanf("%20s", p->math_score);
    p->next = NULL;

    printf("请输入学生的英语成绩(小于20字符)：");
    scanf("%20s", p->math_score);
    p->next = NULL;

    printf("请输入学生的语文成绩(小于20字符)：");
    scanf("%20s", p->math_score);
    p->next = NULL;

    //printf("请输入学生的总成绩(小于20字符)：");
    p->sum_score = p->math_score + p->english_score + p->chinese_score ;
    //printf("请输入学生的平均成绩(小于20字符)：");
    p->ave_score = ( p->math_score + p->english_score + p->chinese_score )/3;

}

/*
    printf("请输入学生的年龄(10 ~ 40)：");
    while(1 != scanf("%d", &pstu->age) || pstu->age < 10 || pstu->age > 40)
    {
        printf("年龄输入错误！请重新输入学生的年龄(10 ~ 40)：");
        fflush(stdin);
    }
    */
